# pragma once

#include "BTree.hpp"

class Expression{

    private:
        BTree expression_tree;
    public:
        Expression(BTree expression_tree); // constructor
        float evaluate() const; // methods

};