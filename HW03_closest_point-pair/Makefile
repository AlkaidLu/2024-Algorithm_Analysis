# 定义编译器
CXX = g++

# 定义编译选项，这里开启了一些警告以帮助捕获常见错误
CXXFLAGS = -Wall -Wextra -std=c++11

# 定义程序的名称
TARGET = closest_points

# 定义依赖的源文件
SOURCES = closest_points.cpp

# 定义依赖的头文件，如果有的话
HEADERS = closest_points.h

# 生成对象文件列表
OBJECTS = $(SOURCES:.cpp=.o)

# 默认目标
all: $(TARGET)

# 链接目标
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# 编译源文件为对象文件
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理编译生成的文件
clean:
	rm -f $(OBJECTS) $(TARGET)

# phony 目标，确保 make 每次都执行这些命令
.PHONY: all clean