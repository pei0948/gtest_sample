cmake_minimum_required(VERSION 3.12)

# 设置项目名称
project(HelloGTest)

# 添加可执行文件，指定测试文件和源文件
add_executable(AddTests 
              add_test.cpp 
              add.cpp
              addtest_fixture.cpp)

find_package(GTest REQUIRED)

enable_testing()

# 链接 gtest 库
target_link_libraries(AddTests ${GTEST_BOTH_LIBRARIES})

# 添加测试
gtest_discover_tests(AddTests)

