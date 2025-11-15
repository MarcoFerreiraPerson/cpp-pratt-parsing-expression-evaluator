# pragma once

#include <string>

enum TokenType : char {
    Operation,
    Atom,
    EndOfFile
};

struct Token {
    TokenType type;
    std::string value;

    Token(std::string value);
};