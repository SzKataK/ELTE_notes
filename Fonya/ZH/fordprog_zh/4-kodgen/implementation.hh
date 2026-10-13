#ifndef IMPLEMENTATION_HH
#define IMPLEMENTATION_HH

#include <map>
#include <string>

void semantic_error(int line, std::string text);

enum type {boolean, natural};

std::string get_type_name(type typ);

extern long id;

std::string next_label();

struct symbol_data {
    type typ;
    std::string label;
    symbol_data();
    symbol_data(type t);
};

extern std::map<std::string, symbol_data> symbol_table;

void declare(int line, std::string name, type typ);
type get_type(int line, std::string name);
void check_assignment(int line, std::string left, type right);
void check_condition(int line, type typ);
void check_uop(int line, std::string op, type expected, type actual);
void check_binop(int line, std::string op, type left_expected, type right_expected, type left_actual, type right_actual);
void check_my_fun(int line, type fst, type snd, type thr);

void output_code(const std::string & instructions);
std::string read_command(std::string var_name);
std::string write_command(type typ, std::string expr_code);
std::string assign_command(std::string left, type typ, std::string code);
std::string if1_command(std::string condition_code, std::string branch_code);
std::string if2_command(std::string condition_code, std::string branch1_code, std::string branch2_code);
std::string while_command(std::string condition_code, std::string iterated_code);

struct expression {
    type typ;
    std::string code;
    expression();
    expression(type typ, std::string code);
};

expression literal_expression(type typ, std::string value);
expression id_expression(int line, std::string name);
std::string operator_code(std::string op);
expression binop_expression(std::string op, type typ, expression left, expression right);
expression not_expression(expression param);
expression function_expression(expression fst, expression snd, expression thr);

#endif // IMPLEMENTATION_HH
