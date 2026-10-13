#include "implementation.hh"
#include "while.tab.hh"
#include <iostream>
#include <sstream>

// Semantic analyzer

void semantic_error(int line, std::string text) {
    std::cerr << "Line " << line << ": Error: " << text << std::endl;
    exit(1);
}

std::string get_type_name(type typ) {
    switch(typ) {
        case boolean: return "boolean";
        case natural: return "natural";
        default:
            std::cerr << "Bug: Unknown type with index " << typ;
            exit(1);
    }
}

long id = 0;

std::string next_label() {
    std::stringstream ss;
    ss << "label" << id++;
    return ss.str();
}

symbol_data::symbol_data() {}

symbol_data::symbol_data(type t) : typ(t), label(next_label()) {}

std::map<std::string, symbol_data> symbol_table;

void declare(int line, std::string name, type typ) {
    if(symbol_table.find(name) == symbol_table.end()) {
        symbol_table[name] = symbol_data(typ);
    } else {
        semantic_error(line, "Re-declared variable: '" + name + "'.");
    }
}

symbol_data get_symbol_data(int line, std::string name) {
    if(symbol_table.find(name) != symbol_table.end()) {
        return symbol_table[name];
    } else {
        semantic_error(line, "Undeclared variable: '" + name + "'.");
    }
}

type get_type(int line, std::string name) {
    return get_symbol_data(line, name).typ;
}

std::string get_label(int line, std::string name) {
    return get_symbol_data(line, name).label;
}

void check_assignment(int line, std::string left_name, type right) {
    type left = get_type(line, left_name);
    if(left != right) {
        semantic_error(line, "Type error in assignment.");
    }
}

void check_condition(int line, type typ) {
    if(typ != boolean) {
        semantic_error(line, "Condition must be boolean.");
    }
}

void check_my_fun(int line, type fst, type snd, type thr)
{
    if (fst != natural)
    {
        semantic_error(line, "Type error function's first arg.");
    }
    if (snd != natural)
    {
        semantic_error(line, "Type error function's second arg.");
    }
    if (thr != boolean)
    {
        semantic_error(line, "Type error function's third arg.");
    }
}

void check_uop(int line, std::string op, type expected, type actual) {
    if(expected != actual) {
        semantic_error(line, "Type error in argument of '" + op + "'.");
    }
}

void check_binop(int line, std::string op, type left_expected, type right_expected, type left_actual, type right_actual) {
    if(left_expected != left_actual) {
        semantic_error(line, "Type error in left argument of '" + op + "'.");
    }
    if(right_expected != right_actual) {
        semantic_error(line, "Type error in right argument of '" + op + "'.");
    }
}

// Code generator

expression function_expression(expression fst, expression snd, expression thr)
{
    return expression(natural, if2_command(thr.code, binop_expression("+", natural, fst, snd).code, binop_expression("-", natural, snd, fst).code));
}

void output_code(const std::string & instructions) {
    std::cout << "global main" << std::endl;
    std::cout << "extern write_natural" << std::endl;
    std::cout << "extern read_natural" << std::endl;
    std::cout << "extern write_boolean" << std::endl;
    std::cout << "extern read_boolean" << std::endl;
    std::cout << std::endl;
    std::cout << "section .bss" << std::endl;
    std::map<std::string,symbol_data>::iterator it;
    for(it = symbol_table.begin(); it != symbol_table.end(); ++it) {
        std::string label = it->second.label;
        std::cout
            << it->second.label << ": "
            << (it->second.typ == boolean ? "resb " : "resd ")
            << 1 << std::endl;
    }
    std::cout << std::endl;
    std::cout << "section .text" << std::endl;
    std::cout << "main:" << std::endl;
    std::cout << instructions;
    std::cout << "xor eax,eax" << std::endl;
    std::cout << "ret" << std::endl;
}

std::string read_command(std::string var_name) {
    std::stringstream ss;
    type typ = symbol_table[var_name].typ;
    ss << "call " << (typ == boolean ? "read_boolean" : "read_natural") << std::endl;
    ss << "mov [" << symbol_table[var_name].label << "], " << (typ == boolean ? "al" : "eax") << std::endl;
    return ss.str();
}

std::string write_command(type typ, std::string expr_code) {
    std::stringstream ss;
    ss << expr_code;
    if(typ == boolean) {
        ss << "and eax,1" << std::endl;
    }
    ss << "push eax" << std::endl;
    ss << "call write_" << get_type_name(typ) << std::endl;
    ss << "add esp,4" << std::endl;
    return ss.str();
}

std::string assign_command(std::string left, type typ, std::string code) {
    std::stringstream ss;
    ss << code;
    ss << "mov [" << symbol_table[left].label << "], "
       << (typ == boolean ? "al" : "eax") << std::endl; 
    return ss.str();
}

std::string if1_command(std::string condition_code, std::string branch_code) {
    std::stringstream ss;
    std::string end_label = next_label();
    ss << condition_code
       << "cmp al,1\n"
       << "jne near " << end_label << std::endl
       << branch_code
       << end_label << ":\n";
    return ss.str();
}

std::string if2_command(std::string condition_code, std::string branch1_code, std::string branch2_code) {
    std::stringstream ss;
    std::string else_label = next_label();
    std::string end_label = next_label();
    ss << condition_code
       << "cmp al,1\n"
       << "jne near " << else_label << std::endl
       << branch1_code
       << "jmp " << end_label << std::endl
       << else_label << ":\n"
       << branch2_code
       << end_label << ":\n";
    return ss.str();
}

std::string while_command(std::string condition_code, std::string iterated_code) {
    std::stringstream ss;
    std::string start_label = next_label();
    std::string end_label = next_label();
    ss << start_label << ":\n"
       << condition_code
       << "cmp al,1\n"
       << "jne near " << end_label << std::endl
       << iterated_code
       << "jmp " << start_label << std::endl
       << end_label << ":\n";
    return ss.str();
}

expression::expression() : typ(natural), code("") {}

expression::expression(type t, std::string c) : typ(t), code(c) {}

std::string get_register(type t, std::string instance = "a") {
    if(t == boolean) {
        return instance + "l";
    } else {
        return std::string("e") + instance + "x";
    }
}

std::string get_register_for_stack(type t, std::string instance = "a") {
    if(t == boolean) {
        return instance + "x";
    } else {
        return std::string("e") + instance + "x";
    }
}

expression literal_expression(type typ, std::string value) {
    std::stringstream ss;
    ss << "mov " << get_register(typ) << "," << value << std::endl;
    return expression(typ, ss.str());
}

expression id_expression(int line, std::string name) {
    type typ = get_type(line, name);
    std::stringstream ss;
    ss << "mov " << get_register(typ) << ",[" << get_label(line, name) << "]\n";
    return expression(typ, ss.str());
}

std::string operator_code(std::string op) {
    std::stringstream ss;
    if(op == "+") {
        ss << "add eax,ecx" << std::endl;
    } else if(op == "-") {
        ss << "sub eax,ecx" << std::endl;
    } else if(op == "*") {
        ss << "xor edx,edx" << std::endl;
        ss << "mul ecx" << std::endl;
    } else if(op == "/") {
        ss << "xor edx,edx" << std::endl;
        ss << "div ecx" << std::endl;   
    } else if(op == "%") {
        ss << "xor edx,edx" << std::endl;
        ss << "div ecx" << std::endl;
        ss << "mov eax,edx" << std::endl;
    } else if(op == "<") {
        ss << "cmp eax,ecx" << std::endl;
        ss << "mov al,0" << std::endl;
        ss << "mov cx,1" << std::endl;
        ss << "cmovb ax,cx" << std::endl;
    } else if(op == "<=") {
        ss << "cmp eax,ecx" << std::endl;
        ss << "mov al,0" << std::endl;
        ss << "mov cx,1" << std::endl;
        ss << "cmovbe ax,cx" << std::endl;
    } else if(op == ">") {
        ss << "cmp eax,ecx" << std::endl;
        ss << "mov al,0" << std::endl;
        ss << "mov cx,1" << std::endl;
        ss << "cmova ax,cx" << std::endl;
    } else if(op == ">=") {
        ss << "cmp eax,ecx" << std::endl;
        ss << "mov al,0" << std::endl;
        ss << "mov cx,1" << std::endl;
        ss << "cmovae ax,cx" << std::endl;
    } else if(op == "=boolean") {
        ss << "cmp ax,cx" << std::endl;
        ss << "mov al,0" << std::endl;
        ss << "mov cx,1" << std::endl;
        ss << "cmove ax,cx" << std::endl;
    } else if(op == "=natural") {
        ss << "cmp eax,ecx" << std::endl;
        ss << "mov al,0" << std::endl;
        ss << "mov cx,1" << std::endl;
        ss << "cmove ax,cx" << std::endl;
    } else if(op == "and") {
        ss << "cmp al,1" << std::endl;
        ss << "cmove ax,cx" << std::endl;
    } else if(op == "or") {
        ss << "cmp al,0" << std::endl;
        ss << "cmove ax,cx" << std::endl;
    } else {
        semantic_error(-1, std::string("Bug: Unsupported binary operator: ") + op);
    }
    return ss.str();
}

expression binop_expression(std::string op, type typ, expression left, expression right) {
    std::stringstream ss;
    std::string reg1 = get_register(left.typ, "a");
    std::string reg1_stack = get_register_for_stack(left.typ, "a");
    std::string reg2 = get_register(left.typ, "c");
    std::string reg2_stack = get_register_for_stack(left.typ, "c");
    ss << left.code;
    ss << "push " << reg1_stack << std::endl;
    ss << right.code;
    ss << "mov " << reg2 << "," << reg1 << std::endl;
    ss << "pop " << reg1_stack << std::endl;
    ss << operator_code(op);
    return expression(typ, ss.str());
}

expression not_expression(expression param) {
    std::stringstream ss;
    ss << param.code;
    ss << "xor al,1" << std::endl;
    return expression(boolean, ss.str());
}
