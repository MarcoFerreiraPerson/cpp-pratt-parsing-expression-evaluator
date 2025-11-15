#include <iostream>
#include "Expression.hpp"
#include "Lexer.hpp"

int main(int argc, char *argv[])
{
    std::string const test_expression = "1 + 2 * a + b";

    std::vector<std::string> str_expression_lines;

    str_expression_lines.push_back("a = 2");
    str_expression_lines.push_back("b = a * 67");
    str_expression_lines.push_back(test_expression);

    std::vector<Expression> expression_lines;




    /*
    a = 5
    b = 6
    c = b + 1

    1 + c + 3 * a
    
    */
    Lexer lexer = Lexer();

    for (std::string line : str_expression_lines){
        lexer.tokenize_expression(line);
        std::cout << std::endl;

        Expression e = lexer.parse_expression(0);

        expression_lines.push_back(e);

    }

    for (Expression e : expression_lines){
        
        std::cout << "Expression tree: " << e.print() << std::endl;

    }

   

    return 0;
}
