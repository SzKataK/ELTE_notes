#include <iostream>
#include <fstream>
#include <cstdlib>
#include "FlexLexer.h"

int main(int argc, char *argv[]) {
    if(argc != 2) {
        std::cerr << "Usage: " << argv[0] << " inputfile" << std::endl;
        exit(1);
    }
    
    std::ifstream input(argv[1]);
    if(!input) {
        std::cerr << "Cannot open input file: " << argv[1] << std::endl;
        exit(1);
    }
    
    yyFlexLexer lexer(&input);
    lexer.yylex();
    return 0;
}
