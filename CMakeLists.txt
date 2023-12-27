cmake_minimum_required(VERSION 3.12)

# 设置项目名称
project(HelloGTest)

# 添加可执行文件，指定测试文件和源文件
add_executable(CalculatorTests 
              calculator_test.cpp 
              add.cpp
              calculator_test_fixture.cpp
              calculator.cpp)

find_package(GTest REQUIRED)

enable_testing()

# 链接 gtest gmock 
target_link_libraries(CalculatorTests gmock gtest gtest_main pthread)

# 添加测试
gtest_discover_tests(CalculatorTests)

