
#include "Token.hpp"
#include "Expression.hpp"

// Constructor definition
Token::Token(const std::string& val)
    : value(val), expression(std::nullopt)
{

    if (value.empty()) {
        throw TokenizationError("Token cannot be empty");
    }

    switch (value[0]) {
        case '+':
        case '-':
            type = TokenType::Operation;
            left_priority = 1;
            right_priority = 2;
            break;
        case '*':
        case '/':
            type = TokenType::Operation;
            left_priority = 3;
            right_priority = 4;
            break;
        case '=':
            type = TokenType::Operation;
            left_priority = 0;
            right_priority = 1;
            break;
        default:
            type = TokenType::Atom;
            left_priority = 0;
            right_priority = 0;
            break;
    }
}

Token::Token(Expression expr)
    : type(TokenType::Atom), value("[Expression]"), left_priority(0), right_priority(0)
{
    this->expression = std::make_unique<Expression>(std::move(expr));
}

// Constructor for EOF
Token::Token()
    : type(TokenType::EndOfFile),
      value("\0"),
      left_priority(0),
      right_priority(0),
      expression(std::nullopt)
{
}

// Copy constructor
Token::Token(const Token& other)
    : type(other.type),
      value(other.value),
      left_priority(other.left_priority),
      right_priority(other.right_priority)
{
    if (other.expression.has_value()) {
        expression = std::make_unique<Expression>(*other.expression.value());
    } else {
        expression = std::nullopt;
    }
}

// Copy assignment operator
Token& Token::operator=(const Token& other) {
    if (this != &other) {
        type = other.type;
        value = other.value;
        left_priority = other.left_priority;
        right_priority = other.right_priority;

        if (other.expression.has_value()) {
            expression = std::make_unique<Expression>(*other.expression.value());
        } else {
            expression = std::nullopt;
        }
    }
    return *this;
}