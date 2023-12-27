# gtest_sample
gtest 示例

## 编译执行原代码
```
g++ add.cpp calculator.cpp main.cpp -o main
./main
```

## cmake 运行 gtest

### 安装 gtest
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

### 运行

```
mkdir build
cd build

cmake ..
make
./AddTests
```

## bazel 运行
### 安装 bazel
[bazel](https://bazel.build/?hl=zh-cn)
```
#下载 bazel 二进制文件
wget https://github.com/bazelbuild/bazel/releases/download/7.0.0/bazel-7.0.0-linux-x86_64

sudo mv bazel-4.2.0-linux-x86_64 /usr/local/bin/bazel

sudo chmod +x /usr/local/bin/bazel

bazel --version

```

### bazel 运行
```
bazel run :main
```

### bazel 运行 gtest
```
bazel test ...
```
