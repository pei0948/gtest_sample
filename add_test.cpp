#include "addtest_fixture.h"
#include <gtest/gtest.h>

TEST_F(AddTest, add) {
	EXPECT_EQ(AddTest::GetAddInstanceSptr()->add(1, 2), 3);
}
