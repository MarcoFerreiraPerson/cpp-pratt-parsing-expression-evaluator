
#include "Token.hpp"

// Constructor definition
Token::Token(const std::string& val) 
    : value(val) 
{
    
    if (value.empty()) {
        throw TokenizationError("Token cannot be empty");
    }

    switch (value[0]) {
        case '+':
        case '-':
            type = TokenType::Operation;
            break;
        case '*':
        case '/':
            type = TokenType::Operation;
            left_priority = 2.1;
            right_priority = 2;
            break;
        case '=':
            type = TokenType::Operation;
            left_priority = 3.1;
            right_priority = 3;

            break;
        default:
            type = TokenType::Atom;
            break;
    }

}

// Constructor for EOF
Token::Token() {
    type = TokenType::EndOfFile;
    value = "\0";
}