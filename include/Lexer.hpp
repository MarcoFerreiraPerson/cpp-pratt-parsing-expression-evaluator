#pragma once

#include "Token.hpp"
#include "Expression.hpp"
#include <vector>
#include <variant>

class Lexer {
private:
    std::vector<std::variant<Token, Expression>> m_tokens; // list of tokens or expressions to process

public:
    Lexer(); // constructor
    Expression process(const std::string& expresion_str);
    std::variant<Token, Expression> pop();    // method declaration
    std::variant<Token, Expression> peek();
    std::string print() const;
};

std::vector<std::string> split(const std::string& s, char delimiter);