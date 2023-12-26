#include "addtest_fixture.h"

std::shared_ptr<Add> AddTest::addSptr = nullptr;

void AddTest::SetUpTestCase() {
	addSptr = std::make_shared<Add>();
}   

void AddTest::TearDownTestCase() {
	addSptr = nullptr;
}

void AddTest::SetUp() {}

void AddTest::TearDown() {}
