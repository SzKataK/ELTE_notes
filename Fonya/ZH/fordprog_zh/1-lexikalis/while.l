%option c++ noyywrap yylineno

%{
#include <iostream>
#include <cstdlib>
%}

%%

program                     std::cout << "PRG" << std::endl;
begin                       std::cout << "BEG" << std::endl;
end                         std::cout << "END" << std::endl;
boolean                     std::cout << "BOO" << std::endl;
natural                     std::cout << "NAT" << std::endl;
read                        std::cout << "REA" << std::endl;
write                       std::cout << "WRI" << std::endl;
if                          std::cout << "IF" << std::endl;
then                        std::cout << "THE" << std::endl;
else                        std::cout << "ELS" << std::endl;
endif                       std::cout << "EIF" << std::endl;
while                       std::cout << "WHI" << std::endl;
do                          std::cout << "DO" << std::endl;
done                        std::cout << "DON" << std::endl;
true                        std::cout << "TRU" << std::endl;
false                       std::cout << "FAL" << std::endl;
":="                        std::cout << "ASN" << std::endl;
"+"                         std::cout << "ADD" << std::endl;
"-"                         std::cout << "SUB" << std::endl;
"*"                         std::cout << "MUL" << std::endl;
"/"                         std::cout << "DIV" << std::endl;
"%"                         std::cout << "MOD" << std::endl;
"<"                         std::cout << "LS" << std::endl;
">"                         std::cout << "GR" << std::endl;
"<="                        std::cout << "LSE" << std::endl;
">="                        std::cout << "GRE" << std::endl;
"="                         std::cout << "EQ" << std::endl;
and                         std::cout << "AND" << std::endl;
or                          std::cout << "OR" << std::endl;
not                         std::cout << "NOT" << std::endl;
"("                         std::cout << "OP" << std::endl;
")"                         std::cout << "CL" << std::endl;
[a-zA-Z_][a-zA-Z0-9_]*      std::cout << "ID" << ' ' << YYText() << std::endl;
[0-9]+                      std::cout << "NUM" <<  ' ' << YYText() << std::endl;
[ \t\n]+                    // Whitespaces skipped.
#.*                         // Commens skipped.
.                           { std::cerr << "Line " << lineno() << ": Unexpected character: '" << YYText() << "'." << std::endl; exit(1); }
