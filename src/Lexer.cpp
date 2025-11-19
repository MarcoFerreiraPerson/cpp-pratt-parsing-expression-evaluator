#include "Lexer.hpp"
#include "Expression.hpp"
#include "Token.hpp"
#include <cctype>
#include <algorithm>
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
        if (token.expression.has_value()) {
            result += "[Expression:" + token.value + "] ";
        } else {
            result += token.value + " ";
        }
    }
    return result;
}

void Lexer::tokenize_expression(const std::string& expr){
     // split into array
    std::vector<std::string> expression_string_vector = split(expr, ' ');

    // tokenize
    for (std::string token_str : expression_string_vector) {
        this->m_tokens.push_back(Token(token_str));
    }

    // reverse so we dont have to shift
    std::reverse(this->m_tokens.begin(), this->m_tokens.end());

    std::cout << this->print();
}

// processes all tokens into an expression
Expression Lexer::parse_expression(float min_priority) {

    Token lhs = this->pop();

    if (lhs.type != TokenType::Atom)
        throw LexerError("The next token must be an atom");

    for (Token next = this->peek(); next.type != TokenType::EndOfFile; next = this->peek()) {

        if (next.type == TokenType::EndOfFile)
            break;

        if (next.type != TokenType::Operation)
            throw LexerError("Expected operation after atom, token: " + next.value);

        if (next.left_priority < min_priority)
            break;

        // Now grab the operation
        Token op = this->pop();

        Expression rhs = this->parse_expression(op.right_priority);
        lhs = Token(Expression(op, lhs, rhs));
    }

    // Unwrap the expression from the token
    if (lhs.expression.has_value()) {
        return *lhs.expression.value();
    }

    return Expression(lhs);
} 