#pragma once

#include "add.h"
#include <memory>

class Calculator {
public:
    void SetAddSptr(std::shared_ptr<Adder> addSptr) {
        _addSptr = addSptr;
    }

    int Add(const int num1, const int num2);

    virtual ~Calculator() {
        _addSptr = nullptr;
    }
private:
    std::shared_ptr<Adder> _addSptr;
};
