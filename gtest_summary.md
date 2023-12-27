# 总结 gtest 基本概念和使用
## 1. gtest 简介
gtest是Google的一套用于编写**C++**单元测试的框架，可以运行在很多平台上（包括Linux、Mac OS X、Windows、Cygwin等等）。基于xUnit架构。支持很多好用的特性，包括自动识别测试、丰富的断言、断言自定义、死亡测试、非终止的失败、生成XML报告等等。

>- 测试应该是**独立的、可重复的**。一个测试的结果不应该作为另一个测试的前提。gtest中每个测试运行在独立的对象中。如果某个测试失败了，可以单独地调试它。
>- 测试应该是有**清晰的结构**的。gtest的测试有很好的组织结构，易于维护。
>- 测试应该是**可移植和可复用**的。有很多代码是不依赖平台的，因此它们的测试也需要不依赖于平台。gtest可以在多种操作系统、多种编译器下工作，有很好的可移植性。
>- 测试失败时，应该给出尽可能**详尽的信息**。gtest在遇到失败时并不停止接下来的测试，而且还可以选择使用非终止的失败来继续执行当前的测试。这样一次可以测试尽可能多的问题。
>- 测试框架应该避免让开发者**维护测试框架**相关的东西。gtest可以**自动识别**定义的全部测试，你不需要一一列举它们。
>- 测试应该够**快**。gtest在满足测试独立的前提下，允许你复用共享数据，它们只需创建一次。
>- gtest采用的是**xUnit**架构，你会发现和JUnit、PyUnit很类似，所以上手非常快。

## 2. gtest 使用方式
### 2.1 gtest 安装
- 拉取 gtest 仓库 [GTest](https://github.com/google/googletest)
- 安装 gtest
```
mkdir build
cd build

cmake ..
make 
make install
```
>- 当我们make install 以后gtest相关头文件已经安装到/usr/local/include/下了，所以在使用的时候直接写#include "gtest/gtest.h"就可以了,而对于库文件，由于make install的时候已经将gtest的相关库安装到/usr/local/lib下了，所以后续使用的话直接链接就好了不用加路径
>- libgtest.a或libgtest.so：gtest库的静态或动态链接库文件，包含gtest的实现代码。
>- libgtest_main.a或libgtest_main.so：gtest库的静态或动态链接库文件，包含gtest的主函数实现和启动测试的代码（当我们的测试文件中没有main函数的话就可以链接到这个库就可以运行了）。

### 2.2 gtest 断言
#### 2.2.1 断言分类
ASSERT_*断言和EXPECT_*断言的区别：
- ASSERT_类型的断言是**致命的**，如果它们失败，那么测试将会停止执行。这可以帮助你快速地定位错误，但同时也会影响到测试的覆盖范围。
- 而EXPECT_类型的断言则是**非致命的**，即使它们失败，测试仍将继续执行，这可以让你获得更多的测试覆盖范围，但也可能导致测试过于宽松，因为它们无法确保测试的正确性。

>因此，使用哪种类型的断言取决于你的具体需求。如果你想快速地定位错误并停止测试，那么使用ASSERT_；如果你更关心测试覆盖范围，并希望测试能够继续执行，那么使用EXPECT_。

#### 2.2.2 断言使用
| Fatal assertion | Nonfatal assertion | Verifies                                                    |
| -------------- | ------------------ | ------------------------------------------------------------ |
| ASSERT_TRUE(condition)    | EXPECT_TRUE(condition)        | condition is true                                                      |
| ASSERT_FALSE(condition)   | EXPECT_FALSE(condition)       | condition is false                                                     |
| ASSERT_EQ(expected, actual) | EXPECT_EQ(expected, actual)   | expected == actual                                                     |
| ASSERT_NE(expected, actual) | EXPECT_NE(expected, actual)   | expected != actual                                                     |
| ASSERT_LT(expected, actual) | EXPECT_LT(expected, actual)   | expected < actual                                                      |
| ASSERT_LE(expected, actual) | EXPECT_LE(expected, actual)   | expected <= actual                                                     |
| ASSERT_GT(expected, actual) | EXPECT_GT(expected, actual)   | expected > actual                                                      |
| ASSERT_GE(expected, actual) | EXPECT_GE(expected, actual)   | expected >= actual                                                     |
| ASSERT_STREQ(expected, actual) | EXPECT_STREQ(expected, actual)   | 字符串 expected == actual                    |
| ASSERT_STRNE(expected, actual) | EXPECT_STRNE(expected, actual)   | 字符串 expected != actual                    |
| ASSERT_STRCASEEQ(expected, actual) | EXPECT_STRCASEEQ(expected, actual)   | 忽略字符串大小写 expected == actual    |
| ASSERT_STRCASENE(expected, actual) | EXPECT_STRCASENE(expected, actual)   | 忽略字符串大小写 expected != actual    |
| ASSERT_THROWS(statement, expected_exception) | EXPECT_THROWS(statement, expected_exception)   | 期望 statement 抛出 expected_exception|
| ASSERT_NO_THROW(statement) | EXPECT_NO_THROW(statement)   | statement 不会抛出异常                    |
| ASSERT_ANY_THROW(statement) | EXPECT_ANY_THROW(statement)   | statement 抛出任何类型异常                    |
| ASSERT_FLOAT_EQ(expected, actual) | EXPECT_FLOAT_EQ(expected, actual)   | 浮点数 expected == actual                    |
| ASSERT_DOUBLE_EQ(expected, actual) | EXPECT_DOUBLE_EQ(expected, actual)   | 浮点数 expected == actual |

### 2.3 gtest 夹具
>在使用测试夹具（继承自testing::Test的测试类）的时候一般是使用 TEST_F，而不是 TEST
>TEST_F的第一个参数就不能乱取了，必须是测试夹具（继承自testing::Test的测试类）
#### 2.3.1 TestCase级别的，每个TestCase前后
需要写一个类，继承**testing::Test**，然后实现 SetUp方法和TearDown 方法：
- SetUp()方法在每个TestCase之前执行
- TearDown()方法在每个TestCase之后执行
```
#include "add.h"
#include <gtest/gtest.h>

class AddTest : public testing::Test {
protected:
	void SetUp() override;

	void TearDown() override;
};
```

#### 2.3.2 TestSuite级别的，某一批案例前后
需要写一个类，继承**testing::Test**，然后实现两个静态方法
- SetUpTestCase() 方法在第一个TestCase之前执行
- TearDownTestCase() 方法在最后一个TestCase之后执行
```
#include "add.h"
#include <gtest/gtest.h>

class AddTest : public testing::Test {
protected:
	// 第一个测试用例执行前执行,只执行一次
	static void SetUpTestCase(); 

	// 最后一个测试用例执行后执行,只执行一次
	static void TearDownTestCase(); 
};
```

#### 2.3.3 全局的，所有案例执行前后
要实现全局事件，必须写一个类，继承**testing::Environment**类，实现里面的SetUp和TearDown方法。
- SetUp()方法在所有案例执行前执行
- TearDown()方法在所有案例执行后执行
```
class FooEnvironment : public testing::Environment
{
public:
    virtual void SetUp()
    {
        std::cout << "Foo FooEnvironment SetUP" << std::endl;
    }
    virtual void TearDown()
    {
        std::cout << "Foo FooEnvironment TearDown" << std::endl;
    }
};
```
>当然，这样还不够，我们还需要告诉gtest添加这个全局事件，我们需要在main函数中通过testing::AddGlobalTestEnvironment方法将事件挂进来，也就是说，我们可以写很多个这样的类，然后将他们的事件都挂上去。
```
int _tmain(int argc, _TCHAR* argv[])
{
    testing::AddGlobalTestEnvironment(new FooEnvironment);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

### 2.4 gtest 和 JUnit 联合使用
参考 [AndroidGTestRunner](https://github.com/paleozogt/AndroidGTestRunner)

## 3. gmock 使用
- mock 主要使用了动态多态的特性
- 将 mock 类继承要 mock 的类，将 mock 类的实例 set 进入要测试的方法中。测试方法中实例调用对应的方法时，获得的结果则是 mock 后的结果

```
int Calculator::Add(const int num1, const int num2) {
    return _addSptr->Add(num1, num2);
}  
```

```
#include "add.h"
#include <gmock/gmock.h>

class MockAdder : public Adder {
public:
    MOCK_METHOD2(Add, int(const int, const int));
};
```

```
TEST_F(CalculatorTest, MockAdd) {
   std::shared_ptr<MockAdder> mockAddSptr = std::make_shared<MockAdder>();
   EXPECT_CALL(*mockAddSptr, Add(1, 2)) 
        .Times(1)    //! 期望被调 1 次
        .WillOnce(testing::Return(2));   //! 返回值为5
   CalculatorTest::GetCalculatorInstanceSptr()->SetAddSptr(mockAddSptr);

   EXPECT_NE(CalculatorTest::GetCalculatorInstanceSptr()->Add(1, 2), 3); 
}
```

## 4. 相关链接
- [GoogleTest](https://github.com/google/googletest)
- [AndroidGTestRunner](https://github.com/paleozogt/AndroidGTestRunner)
- [单元测试gtest的安装与使用方法](https://blog.csdn.net/Jacksqh/article/details/129805462)
- [gtest系列(一) | 断言(Assertion)](https://zhuanlan.zhihu.com/p/269351365)
- [googletest-gmock使用示例](https://zhuanlan.zhihu.com/p/101906555)
