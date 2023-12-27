#pragma once

#include "calculator.h"
#include <gtest/gtest.h>


class CalculatorTest : public testing::Test {
public:
       static std::shared_ptr<Calculator> GetCalculatorInstanceSptr() {
              return _calculatorSptr;
        }
protected:
	// 第一个测试用例执行前执行,只执行一次
	static void SetUpTestCase(); 

	// 最后一个测试用例执行后执行,只执行一次
	static void TearDownTestCase(); 

	void SetUp() override;

	void TearDown() override;

private:
	static std::shared_ptr<Calculator> _calculatorSptr;
};

