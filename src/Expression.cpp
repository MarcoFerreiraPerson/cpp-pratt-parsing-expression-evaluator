#include "Expression.hpp"
#include "Token.hpp"

std::string Expression::print() const {
    std::string result;

    // If this is a leaf node (atom)
    if (expression_tree.head.left == nullptr && expression_tree.head.right == nullptr) {
        return expression_tree.head.token.value;
    }

    // Otherwise it's an operation node
    result += "(";

    if (expression_tree.head.left != nullptr) {
        if (expression_tree.head.left->token.expression.has_value()) {
            result += expression_tree.head.left->token.expression.value()->print();
        } else {
            result += expression_tree.head.left->token.value;
        }
    }

    result += " " + expression_tree.head.token.value + " ";

    if (expression_tree.head.right != nullptr) {
        if (expression_tree.head.right->token.expression.has_value()) {
            result += expression_tree.head.right->token.expression.value()->print();
        } else {
            result += expression_tree.head.right->token.value;
        }
    }

    result += ")";
    return result;
}

Expression::Expression(const Token& op, const Token& lhs, const Token& rhs) {
    // Create the head node with the operator
    expression_tree.head.token = op;

    // Create left child node (allocate on heap)
    expression_tree.head.left = new Node{lhs, nullptr, nullptr};

    // Create right child node (allocate on heap)
    expression_tree.head.right = new Node{rhs, nullptr, nullptr};
}

Expression::Expression(const Token& atom) {
    expression_tree.head.token = atom;
    expression_tree.head.left = nullptr;
    expression_tree.head.right = nullptr;
}

// Copy constructor
Expression::Expression(const Expression& other) {
    expression_tree.head.token = other.expression_tree.head.token;

    if (other.expression_tree.head.left != nullptr) {
        expression_tree.head.left = new Node(*other.expression_tree.head.left);
    } else {
        expression_tree.head.left = nullptr;
    }

    if (other.expression_tree.head.right != nullptr) {
        expression_tree.head.right = new Node(*other.expression_tree.head.right);
    } else {
        expression_tree.head.right = nullptr;
    }
}

// Copy assignment operator
Expression& Expression::operator=(const Expression& other) {
    if (this != &other) {
        // Clean up existing nodes
        delete expression_tree.head.left;
        delete expression_tree.head.right;

        expression_tree.head.token = other.expression_tree.head.token;

        if (other.expression_tree.head.left != nullptr) {
            expression_tree.head.left = new Node(*other.expression_tree.head.left);
        } else {
            expression_tree.head.left = nullptr;
        }

        if (other.expression_tree.head.right != nullptr) {
            expression_tree.head.right = new Node(*other.expression_tree.head.right);
        } else {
            expression_tree.head.right = nullptr;
        }
    }
    return *this;
}
