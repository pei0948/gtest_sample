#include "add.h"
#include <gtest/gtest.h>


class AddTest : public testing::Test {
public:
       static std::shared_ptr<Add> GetAddInstanceSptr() {
              return addSptr;
        }
protected:
	// 第一个测试用例执行前执行,只执行一次
	static void SetUpTestCase(); 

	// 最后一个测试用例执行后执行,只执行一次
	static void TearDownTestCase(); 

	void SetUp() override;

	void TearDown() override;

private:
	static std::shared_ptr<Add> addSptr;
};

