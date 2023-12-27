#include "calculator_test_fixture.h"
#include "add_mock.h"
#include <gtest/gtest.h>

TEST_F(CalculatorTest, Add) {
   EXPECT_EQ(CalculatorTest::GetCalculatorInstanceSptr()->Add(1, 2), 3);
}


TEST_F(CalculatorTest, MockAdd) {
   std::shared_ptr<MockAdder> mockAddSptr = std::make_shared<MockAdder>();
   EXPECT_CALL(*mockAddSptr, Add(1, 2))
        .Times(1)    //! 期望被调 1 次
        .WillOnce(testing::Return(2));   //! 返回值为5
   CalculatorTest::GetCalculatorInstanceSptr()->SetAddSptr(mockAddSptr);

   EXPECT_NE(CalculatorTest::GetCalculatorInstanceSptr()->Add(1, 2), 3);
}

