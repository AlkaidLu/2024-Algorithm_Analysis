# 定义编译器
CXX = g++

# 定义编译选项
CXXFLAGS = -Wall -std=c++11

# 定义链接选项
LDFLAGS = 

# 定义要编译的源文件
SOURCES = main.cpp sort.cpp test.cpp

# 定义生成的可执行文件名
EXECUTABLE = main

# 默认目标
all: $(EXECUTABLE)

# 链接目标
$(EXECUTABLE): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $@ $(LDFLAGS)

# 清理编译生成的文件
clean:
	rm -f $(EXECUTABLE) *.o

# 防止 make 执行时显示这些规则
.PHONY: all clean