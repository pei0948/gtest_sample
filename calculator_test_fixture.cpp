#include "calculator_test_fixture.h"

std::shared_ptr<Calculator> CalculatorTest::_calculatorSptr = nullptr;

void CalculatorTest::SetUpTestCase() {
    std::shared_ptr<Adder> addSptr = std::make_shared<Adder>();
    _calculatorSptr = std::make_shared<Calculator>();
    _calculatorSptr->SetAddSptr(addSptr);
}   

void CalculatorTest::TearDownTestCase() {
	_calculatorSptr = nullptr;
}

void CalculatorTest::SetUp() {}

void CalculatorTest::TearDown() {}
