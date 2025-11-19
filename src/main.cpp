#include <iostream>
#include <string>
#include "Evaluator.hpp"
#include "Expression.hpp"
#include "Lexer.hpp"

int main()
{
    Lexer lexer = Lexer();
    Evaluator evaluator = Evaluator();

    std::cout << "Expression Evaluator - Type 'exit' or 'quit' to end\n";
    std::cout << "Examples: a = 5, b = a * 2, 1 + 2 * 3\n";
    std::cout << "-------------------------------------------\n";

    std::string input;

    while (true) {
        std::cout << ">>> ";
        std::getline(std::cin, input);

        // Check for exit commands
        if (input == "exit" || input == "quit") {
            std::cout << "Goodbye!\n";
            break;
        }

        // Skip empty lines
        if (input.empty()) {
            continue;
        }

        try {
            lexer.tokenize_expression(input);
            Expression e = lexer.parse_expression(0);

            float result = e.evaluate(evaluator.get_vars());
            std::cout << "= " << result << "\n";
        } catch (const std::exception& ex) {
            std::cout << "Error: " << ex.what() << "\n";
        }
    }

    return 0;
}
