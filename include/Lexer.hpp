#pragma once

#include "Token.hpp"
#include "Expression.hpp"
#include <vector>

class Lexer {
private:
    std::vector<Token> m_tokens; // list of tokens to process

public:
    Lexer(); // constructor
    Expression  process();                  
    Token pop();    // method declaration
    Token next();
};