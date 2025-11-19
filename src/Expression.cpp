#include "Expression.hpp"
#include "Token.hpp"
#include <cstddef>

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

float dfs(Node current_node, std::unordered_map<std::string, float>& vars) {
    // If the token wraps an expression, evaluate that expression
    if (current_node.token.expression.has_value()) {
        return current_node.token.expression.value()->evaluate(vars);
    }
    
    // if current_node of the tree is an atom then traverse upward
    if (current_node.token.type == TokenType::Atom){

        // if its a digit then just return the float repr of it
        if (isDigits(current_node.token.value))
            return std::stof(current_node.token.value);
        else {
            // potentially is a variable
            auto it = vars.find(current_node.token.value);
            if (it != vars.end()) {
                return it->second;  // Variable exists
            } else {
                throw std::runtime_error("Variable '" + current_node.token.value + "' is not defined");
            }
        }
    }

    // Handle assignment separately (don't evaluate left side as a value because its the variable)
    if (current_node.token.value == "=") {
        // Left side should be a variable name
        if (current_node.left->token.type == TokenType::Atom &&
            !isDigits(current_node.left->token.value)) {
            std::string var_name = current_node.left->token.value;
            float right_val = dfs(*current_node.right, vars);  // Only evaluate right side
            vars[var_name] = right_val;  // Assign the value
            return right_val;  // Return the assigned value
        } else {
            throw std::runtime_error("Left side of assignment must be a variable");
        }
    }

    // evaluate both sides
    float left_val = dfs(*current_node.left, vars);
    float right_val = dfs(*current_node.right, vars);

    // Apply the operation
    if (current_node.token.value == "+") return left_val + right_val;
    if (current_node.token.value == "-") return left_val - right_val;
    if (current_node.token.value == "*") return left_val * right_val;
    if (current_node.token.value == "/") return right_val != 0 ? left_val / right_val : 0;

    return 0;  // Default case


}

float Expression::evaluate(std::unordered_map<std::string, float>& vars) const {
    
    Node head = this->expression_tree.head;


    return dfs(head, vars);

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


bool isDigits(const std::string& s) {
    if (s.empty()) return false;

    for (unsigned char c : s) {
        if (!std::isdigit(c))
            return false;
    }
    return true;
}