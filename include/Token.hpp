# pragma once

#include <string>
#include <stdexcept>

enum class TokenType : char {
    Operation,
    Atom
};

struct Token {
    TokenType type;
    std::string value;

    Token(const std::string& value);
};

class TokenizationError : public std::runtime_error {
public:
    TokenizationError(const std::string& msg) : std::runtime_error(msg) {}
};