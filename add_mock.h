#pragma once

#include "add.h"
#include <gmock/gmock.h>

class MockAdder : public Adder {
public:
    MOCK_METHOD2(Add, int(const int, const int));
};

