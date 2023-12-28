#pragma once

#include "add.h"
#include <memory>

enum class OPERATOR {
    OPERATOR_ADD = 0,  // 加
    OPERATOR_SUB = 1,  // 减
    OPERATOR_MUL = 2,  // 乘
    OPERATOR_DIV = 3   // 除
};

class Calculator {
public:
    void SetAddSptr(std::shared_ptr<Adder> addSptr) {
        _addSptr = addSptr;
    }

    virtual int Add(const int num1, const int num2);

    virtual int Calc(const OPERATOR op, const int num1, const int num2);

    virtual ~Calculator() {
        _addSptr = nullptr;
    }
private:
    std::shared_ptr<Adder> _addSptr;
};
