
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
        case '*':
        case '/':
        case '=':
            type = TokenType::Operation;
            break;
        default:
            type = TokenType::Atom;
            break;
    }

}