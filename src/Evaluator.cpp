#include "Evaluator.hpp"
#include "Expression.hpp"
#include <iostream>

Evaluator::Evaluator() : vars{} {};

void Evaluator::evaluate_expressions(std::vector<Expression> expressions){

    float result;
    for (Expression expression : expressions){
        expression.print();
        result = expression.evaluate(this->vars);
        std::cout << result << std::endl;
    }

}

std::unordered_map<std::string, float>& Evaluator::get_vars() {
    return this->vars;
}