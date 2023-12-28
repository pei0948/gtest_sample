#pragma once

#include "calculator.h"
#include <gmock/gmock.h>

class MockCalculator : public Calculator {
public:
    MOCK_METHOD2(Add, int(const int, const int));
};

