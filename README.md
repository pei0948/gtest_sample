# gtest_sample
gtest 示例

## 编译执行原代码
```
g++ main.cpp add.cpp -o main
./main
```

## 安装 gtest
- 拉取 gtest 仓库
[GTest](https://github.com/google/googletest)
- 安装 gtest
```
mkdir build
cd build

cmake ..
make 
make install
```

## cmake 运行 gtest
```
mkdir build
cd build

cmake ..
make
./AddTests
```
