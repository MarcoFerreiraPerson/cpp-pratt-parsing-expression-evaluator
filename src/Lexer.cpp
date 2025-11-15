#include "Lexer.hpp"
#include "Expression.hpp"
#include <cctype>
#include <algorithm>
#include <stdexcept>
#include <iostream>

std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> parts;
    std::string current;

    for (char c : s) {
        if (c == delimiter) {
            parts.push_back(current);
            current.clear();
        } else {
            current += c;
        }
    }

    parts.push_back(current); // last segment
    return parts;
}

Lexer::Lexer() : m_tokens{} {}

// Remove and return next token
Token Lexer::pop() {
    if (this->m_tokens.empty()) {
        return Token();
    }

    Token next_token = this->m_tokens.back();

    this->m_tokens.pop_back();

    return next_token;
}

// return next token
Token Lexer::peek() {
    if (this->m_tokens.empty()) {
        return Token();
    }

    Token next_token = this->m_tokens.back();

    return next_token;
}

std::string Lexer::print() const {
    std::string result = "Tokens: ";
    for (const auto& token : m_tokens) {
        result += token.value + " ";
    }
    return result;
}


// processes all tokens into an expression
Expression Lexer::process(const std::string& expr) {

    // split into array
    std::vector<std::string> expression_string_vector = split(expr, ' ');

    // tokzenize
    for (std::string token_str : expression_string_vector) {
        this->m_tokens.push_back(Token(token_str));
    }

    // reverse so we dont have to shift
    std::reverse(this->m_tokens.begin(), this->m_tokens.end());

    std::cout << this->print();

    return Expression();
} 