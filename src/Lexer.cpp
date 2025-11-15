#include "Lexer.hpp"
#include "Expression.hpp"
#include <cctype>
#include <algorithm>
#include <iostream>
#include <variant>

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

// Remove and return next token or expression
std::variant<Token, Expression> Lexer::pop() {
    if (this->m_tokens.empty()) {
        return Token();
    }

    auto next_item = this->m_tokens.back();

    this->m_tokens.pop_back();

    return next_item;
}

// return next token or expression
std::variant<Token, Expression> Lexer::peek() {
    if (this->m_tokens.empty()) {
        return Token();
    }

    auto next_item = this->m_tokens.back();

    return next_item;
}

std::string Lexer::print() const {
    std::string result = "Tokens: ";
    for (const auto& item : m_tokens) {
        // Use std::visit to handle both Token and Expression
        std::visit([&result](auto&& arg) {
            using T = std::decay_t<decltype(arg)>;
            if constexpr (std::is_same_v<T, Token>) {
                result += arg.value + " ";
            } else if constexpr (std::is_same_v<T, Expression>) {
                result += "[Expression] ";
            }
        }, item);
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


    m_tokens.clear();

    return Expression();
} 