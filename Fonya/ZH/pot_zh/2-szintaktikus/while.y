%language "c++"
%locations
%define api.value.type variant

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
%token ID
%token NUM
%token FUNNAME
%token BAR
%token COMMA

%left OR
%left AND
%left EQ
%left LS GR LSE GRE
%left ADD SUB
%left MUL DIV MOD
%precedence NOT

%%

start:
    PRG ID declarations BEG commands END
    {
        std::cout << "start -> PRG ID declarations BEG commands END" << std::endl;
    }
;

declarations:
    // empty
    {
        std::cout << "declarations -> epsilon" << std::endl;
    }
|
    declarations declaration
    {
        std::cout << "declarations -> declarations declaration" << std::endl;
    }
;

declaration:
    BOO ID
    {
        std::cout << "declaration -> BOO ID" << std::endl;
    }
|
    NAT ID
    {
	std::cout << "declaration -> NAT ID" << std::endl;
    }
;

commands:
    // empty
    {
        std::cout << "commands -> epsilon" << std::endl;
    }
|
    commands command
    {
	std::cout << "commands -> commands command" << std::endl;
    }
;

command:
    REA OP ID CL
    {
        std::cout << "command -> REA OP ID CL" << std::endl;
    }
|
    WRI OP expression CL
    {
        std::cout << "command-> WRI OP expression CL" << std::endl;
    }
|
    ID ASN expression
    {
        std::cout << "command -> ID ASN expression" << std::endl;
    }
|
    IF expression THE commands EIF
    {
        std::cout << "command -> IF expression THE commands EIF" << std::endl;
    }
|
    IF expression THE commands ELS commands EIF
    {
        std::cout << "command -> IF expression THE commands ELS commands EIF" << std::endl;
    }
|
    WHI expression DO commands DON
    {
        std::cout << "command -> WHI expression DO commands DON" << std::endl;
    }
;

expression:
    NUM
    {
        std::cout << "expression -> NUM" << std::endl;
    }
|
    TRU
    {
        std::cout << "expression -> TRU" << std::endl;
    }
|
    FAL
    {
        std::cout << "expression -> FAL" << std::endl;
    }
|
    ID
    {
        std::cout << "expression -> ID" << std::endl;
    }
|
    expression ADD expression
    {
        std::cout << "expression -> expression ADD expression" << std::endl;
    }
|
    expression SUB expression
    {
        std::cout << "expression -> expression SUB expression" << std::endl;
    }
|
    expression MUL expression
    {
        std::cout << "expression -> expression MUL expression" << std::endl;
    }
|
    expression DIV expression
    {
        std::cout << "expression -> expression DIV expression" << std::endl;
    }
|
    expression MOD expression
    {
        std::cout << "expression -> expression MOD expression" << std::endl;
    }
|
    expression LS expression
    {
        std::cout << "expression -> expression LS expression" << std::endl;
    }
|
    expression GR expression
    {
        std::cout << "expression -> expression GR expression" << std::endl;
    }
|
    expression LSE expression
    {
        std::cout << "expression -> expression LSE expression" << std::endl;
    }
|
    expression GRE expression
    {
        std::cout << "expression -> expression GRE expression" << std::endl;
    }
|
    expression AND expression
    {
        std::cout << "expression -> expression AND expression" << std::endl;
    }
|
    expression OR expression
    {
        std::cout << "expression -> expression OR expression" << std::endl;
    }
|
    expression EQ expression
    {
        std::cout << "expression -> expression EQ expression" << std::endl;
    }
|
    NOT expression
    {
        std::cout << "expression -> NOT expression" << std::endl;
    }
|
    OP expression CL
    {
        std::cout << "expression -> OP expression CL" << std::endl;
    }
|
    FUNNAME BAR expression COMMA expression COMMA expression COMMA expression BAR
    {
        std::cout << "expression -> FUNNAME BAR expression COMMA expression COMMA expression COMMA expression BAR" << std::endl;
    }
;

%%
