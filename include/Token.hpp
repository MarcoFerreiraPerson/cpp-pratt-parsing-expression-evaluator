# pragma once

#include <string>
#include <stdexcept>
#include <optional>
#include <memory>

// Forward declaration
class Expression;

enum class TokenType : char {
    Operation,
    Atom,
    EndOfFile
};

struct Token {
    TokenType type;
    std::string value;
    float left_priority;
    float right_priority;

    // Optional: if this token represents an expression
    std::optional<std::unique_ptr<Expression>> expression;

    Token(const std::string& value);
    Token(Expression expr);
    Token();

    // Copy constructor and assignment needed due to unique_ptr
    Token(const Token& other);
    Token& operator=(const Token& other);

    // Move constructor and assignment
    Token(Token&& other) noexcept = default;
    Token& operator=(Token&& other) noexcept = default;
};

class TokenizationError : public std::runtime_error {
public:
    TokenizationError(const std::string& msg) : std::runtime_error(msg) {}
};