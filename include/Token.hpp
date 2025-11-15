# pragma once

#include <string>
#include <stdexcept>

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


    Token(const std::string& value);
    Token();
};

class TokenizationError : public std::runtime_error {
public:
    TokenizationError(const std::string& msg) : std::runtime_error(msg) {}
};