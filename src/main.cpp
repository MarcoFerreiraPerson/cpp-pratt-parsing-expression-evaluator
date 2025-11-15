#include <iostream>
#include "Lexer.hpp"

int main(int argc, char *argv[])
{
    std::string const test_expression = "1 + 1 * 5 + 2";

    /*
    a = 5
    b = 6
    c = b + 1

    1 + c + 3 * a
    
    */
    Lexer lexer = Lexer();

    Expression e = lexer.process(test_expression);

    return 0;
}
