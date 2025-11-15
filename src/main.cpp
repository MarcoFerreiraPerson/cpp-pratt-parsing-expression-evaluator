#include <iostream>
#include "Lexer.hpp"

int main(int argc, char *argv[])
{
    std::string const test_expression = "a = 1 + 2 * a + b";

    /*
    a = 5
    b = 6
    c = b + 1

    1 + c + 3 * a
    
    */
    Lexer lexer = Lexer();

    lexer.tokenize_expression(test_expression);
    std::cout << std::endl;

    Expression e = lexer.parse_expression(0);

    std::cout << "Expression tree: " << e.print() << std::endl;

    return 0;
}
