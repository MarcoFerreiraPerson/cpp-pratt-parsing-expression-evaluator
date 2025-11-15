#pragma once

#include "Token.hpp"
#include "Expression.hpp"
#include <vector>

class Lexer {
private:
    std::vector<Token> m_tokens; // list of tokens (can contain subexpressions)

public:
    Lexer(); // constructor
    void tokenize_expression(const std::string& expresion_str);
    Expression parse_expression(float min_priority);
    Token pop();    // method declaration
    Token peek();
    std::string print() const;
};

std::vector<std::string> split(const std::string& s, char delimiter);

class LexerError : public std::runtime_error {
public:
    LexerError(const std::string& msg) : std::runtime_error(msg) {}
};