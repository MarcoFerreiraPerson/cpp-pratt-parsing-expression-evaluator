#pragma once

#include "Expression.hpp" 
#include <vector>


class Evaluator {
private:
    // variables
    std::unordered_map<std::string, float> vars;

public:
    Evaluator(); // constructor
    void evaluate_expressions(std::vector<Expression> expressions); // method declaration
    std::unordered_map<std::string, float>& get_vars(); // getter for vars
};