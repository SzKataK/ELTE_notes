%language "c++"
%locations
%define api.value.type variant

%code requires {
#include "implementation.hh"
}

%code provides {
int yylex(yy::parser::semantic_type* yylval, yy::parser::location_type* yylloc);
}

%token PRG
%token BEG
%token END
%token BOO
%token NAT
%token REA
%token WRI
%token IF
%token THE
%token ELS
%token EIF
%token WHI
%token DO
%token DON
%token TRU
%token FAL
%token ASN
%token OP
%token CL
%token <std::string> ID
%token <std::string> NUM
%token FUNNAME
%token COMMA
%token BROPEN
%token BRCLOSE

%left OR
%left AND
%left EQ
%left LS GR LSE GRE
%left ADD SUB
%left MUL DIV MOD
%precedence NOT

%type <expression> expression
%type <std::string> commands
%type <std::string> command

%%

start:
    PRG ID declarations BEG commands END
    {
        output_code($5);
    }
;

declarations:
    // empty
|
    declarations declaration
;

declaration:
    BOO ID
    {
        declare(@1.begin.line, $2, boolean);
    }
|
    NAT ID
    {
        declare(@1.begin.line, $2, natural);
    }
;

commands:
    // empty
    {
        $$ = "";
    }
|
    commands command
    {
        $$ = $1 + $2;
    }
;

command:
    REA OP ID CL
    {
        get_type(@3.begin.line, $3);
        $$ = read_command($3);
    }
|
    WRI OP expression CL
    {
        $$ = write_command($3.typ, $3.code);
    }
|
    ID ASN expression
    {
        check_assignment(@1.begin.line, $1, $3.typ);
        $$ = assign_command($1, $3.typ, $3.code);
    }
|
    IF expression THE commands EIF
    {
        check_condition(@1.begin.line, $2.typ);
        $$ = if1_command($2.code, $4);
    }
|
    IF expression THE commands ELS commands EIF
    {
        check_condition(@1.begin.line, $2.typ);
        $$ = if2_command($2.code, $4, $6);
    }
|
    WHI expression DO commands DON
    {
        check_condition(@1.begin.line, $2.typ);
        $$ = while_command($2.code, $4);
    }
;

expression:
    NUM
    {
        $$ = literal_expression(natural, $1);
    }
|
    TRU
    {
        $$ = literal_expression(boolean, "1");
    }
|
    FAL
    {
        $$ = literal_expression(boolean, "0");
    }
|
    ID
    {
        $$ = id_expression(@1.begin.line, $1);
    }
|
    expression ADD expression
    {
        check_binop(@2.begin.line, "+", natural, natural, $1.typ, $3.typ);
        $$ = binop_expression("+", natural, $1, $3);
    }
|
    expression SUB expression
    {
        check_binop(@2.begin.line, "-", natural, natural, $1.typ, $3.typ);
        $$ = binop_expression("-", natural, $1, $3);
    }
|
    expression MUL expression
    {
        check_binop(@2.begin.line, "*", natural, natural, $1.typ, $3.typ);
        $$ = binop_expression("*", natural, $1, $3);
    }
|
    expression DIV expression
    {
        check_binop(@2.begin.line, "/", natural, natural, $1.typ, $3.typ);
        $$ = binop_expression("/", natural, $1, $3);
    }
|
    expression MOD expression
    {
        check_binop(@2.begin.line, "%", natural, natural, $1.typ, $3.typ);
        $$ = binop_expression("%", natural, $1, $3);
    }
|
    expression LS expression
    {
        check_binop(@2.begin.line, "<", natural, natural, $1.typ, $3.typ);
        $$ = binop_expression("<", boolean, $1, $3);
    }
|
    expression GR expression
    {
        check_binop(@2.begin.line, ">", natural, natural, $1.typ, $3.typ);
        $$ = binop_expression(">", boolean, $1, $3);
    }
|
    expression LSE expression
    {
        check_binop(@2.begin.line, "<=", natural, natural, $1.typ, $3.typ);
        $$ = binop_expression("<=", boolean, $1, $3);
    }
|
    expression GRE expression
    {
        check_binop(@2.begin.line, ">=", natural, natural, $1.typ, $3.typ);
        $$ = binop_expression(">=", boolean, $1, $3);
    }
|
    expression AND expression
    {
        check_binop(@2.begin.line, "and", boolean, boolean, $1.typ, $3.typ);
        $$ = binop_expression("and", boolean, $1, $3);
    }
|
    expression OR expression
    {
        check_binop(@2.begin.line, "or", boolean, boolean, $1.typ, $3.typ);
        $$ = binop_expression("or", boolean, $1, $3);
    }
|
    expression EQ expression
    {
        type typ = $1.typ;
        check_binop(@2.begin.line, "=", typ, typ, $1.typ, $3.typ);
        $$ = (typ == boolean) ?
                binop_expression("=boolean", boolean, $1, $3) :
                binop_expression("=natural", boolean, $1, $3);
    }
|
    NOT expression
    {
        check_uop(@2.begin.line, "not", boolean, $2.typ);
        $$ = not_expression($2);
    }
|
    OP expression CL
    {
        $$ = $2;
    }
|
    FUNNAME BROPEN expression COMMA expression COMMA expression BRCLOSE
    {
        // ellenőrizni a típusokat
        check_my_fun(@1.begin.line, $3.typ, $5.typ, $7.typ);
        
        // kiértékelés
        $$ = function_expression($3, $5, $7);
    }
;

%%
