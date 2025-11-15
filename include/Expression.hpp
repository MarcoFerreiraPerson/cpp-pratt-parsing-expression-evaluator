# pragma once

#include "BTree.hpp"

// Forward declaration
struct Token;

class Expression{

    private:
        BTree expression_tree;
    public:
        Expression(); // default constructor
        Expression(const Token& op, const Token& lhs, const Token& rhs); // constructor for operations
        Expression(const Token& atom); // constructor for single atom

        // Copy constructor
        Expression(const Expression& other);
        Expression& operator=(const Expression& other);

        // Move constructor
        Expression(Expression&& other) noexcept = default;
        Expression& operator=(Expression&& other) noexcept = default;

        float evaluate() const; // methods

};