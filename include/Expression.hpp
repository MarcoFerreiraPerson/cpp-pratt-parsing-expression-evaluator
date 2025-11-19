# pragma once

#include "BTree.hpp"
#include <unordered_map>


// Forward declaration
struct Token;

class Expression{

    private:
        BTree expression_tree;
    public:
        Expression(const Token& op, const Token& lhs, const Token& rhs); // constructor for operations
        Expression(const Token& atom); // constructor for single atom

        // Copy constructor
        Expression(const Expression& other);
        Expression& operator=(const Expression& other);

        // Move constructor
        Expression(Expression&& other) noexcept = default;
        Expression& operator=(Expression&& other) noexcept = default;

        float evaluate(std::unordered_map<std::string, float>& vars) const; // methods
        std::string print() const;

};

bool isDigits(const std::string& s);