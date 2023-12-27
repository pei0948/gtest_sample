#include "calculator_test_fixture.h"
#include <gtest/gtest.h>

TEST_F(CalculatorTest, Add) {
    EXPECT_EQ(CalculatorTest::GetCalculatorInstanceSptr()->Add(1, 2), 3);
}
