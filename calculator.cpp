#include "calculator.h"

#include <climits>

int Calculator::Add(const int num1, const int num2) {
    return _addSptr->Add(num1, num2);
}  

int Calculator::Calc(const OPERATOR op, const int num1, const int num2) {
    int result = INT_MIN;
    switch(op) {
        case OPERATOR::OPERATOR_ADD:
        result = Add(num1, num2);
        break;

        case OPERATOR::OPERATOR_SUB:
        result = num1 - num2;
        break;

        case OPERATOR::OPERATOR_MUL:
        result = num1 * num2;
        break;

        case OPERATOR::OPERATOR_DIV:
        if (num2 != 0) {
            result = num1 / num2;
        }
        break;

        default:
        result = INT_MIN;
    }
    return result;
}

