#pragma once

#include "Token.hpp"

struct Node{
        Token token;
        Node* left;
        Node* right;
};

struct BTree{
    Node head;
};
