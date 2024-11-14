# 排序算法性能测试项目

本项目旨在比较不同排序算法的性能。实现了几种经典的排序算法，并通过设计测试脚本来衡量它们在不同大小的输入数据上的性能。


## 主要文件结构

├── Basic_sorting_performance_comparison.png  # 不同排序算法性能比较图
├── data.xlsx                                 # 排序实验数据文件
├── get_picture.py                            # 生成图表的Python脚本
├── main                                      # 编译生成的可执行文件
├── main.cpp                                  # 主程序入口文件，负责整体流程控制
├── Makefile                                  # 构建文件，用于自动化编译
├── multi_quick_sort_sorting_performance_comparison.png  # 快速排序不同实现性能比较图
├── optimized_quick_sort_sorting_performance_comparison.png # 快速排序优化前后性能比较图
├── README.md                                 # 项目说明文档
├── sort.cpp                                  # 排序算法实现文件
├── sort.h                                    # 排序算法头文件
├── sorting_data.txt                          # 排序实验输入数据文件
├── sorting_results.xlsx                      # 排序实验结果文件
├── test.cpp                                  # 测试文件，用于测试排序算法的正确性和性能
└── test.h                                    # 测试函数头文件

## 文件详细说明

* **Basic_sorting_performance_comparison.png** : 展示了不同排序算法在不同输入规模下的性能比较图。
* **data.xlsx** : 用于存储实验数据的Excel文件，包含不同排序算法的运行时间、比较次数和移动次数等数据。
* **get_picture.py** : 生成图表的Python脚本，读取 `sorting_results.xlsx` 文件并生成性能比较图，主要用于实验数据的可视化。
* **main.cpp** : 主程序入口，负责读取数据、调用排序算法、记录运行时间并输出实验结果。
* **Makefile** : 用于项目的编译管理，包含编译 `main.cpp` 和其他源文件的规则，可以通过 `make` 命令一键构建项目。
* **multi_quick_sort_sorting_performance_comparison.png** : 展示了快速排序的多种实现（如Hoare法、双指针法、挖洞法等）在不同输入规模下的性能比较图。
* **optimized_quick_sort_sorting_performance_comparison.png** : 展示了优化前后快速排序的性能比较图。
* **sort.cpp** : 包含各种排序算法的实现，如插入排序、冒泡排序、快速排序、归并排序、Shell排序等。
* **sort.h** : 声明了 `sort.cpp` 中排序算法的函数接口。
* **sorting_data.txt** : 输入数据文件，包含实验中使用的随机数组数据，供排序算法测试使用。
* **sorting_results.xlsx** : 输出结果文件，记录了不同排序算法的实验结果，包括运行时间、关键操作次数等。
* **test.cpp** : 包含测试排序算法的代码，用于验证算法正确性及性能测试。
* **test.h** : 声明 `test.cpp` 中测试函数的接口。

## 包含的排序算法

- 插入排序 (Insertion Sort)
- 选择排序 (Selection Sort)
- 冒泡排序 (Bubble Sort)
- 归并排序 (Merge Sort)
- 希尔排序 (Shell Sort)
- 快速排序 (Quick Sort) - 包括三种不同的实现：挖洞法，Hoare法和 书上的s双指针法，还有优化了基数选择的挖洞法，以及BlockQuickSort

## 编译指南

为了编译和运行排序算法性能测试，请遵循以下步骤：

1. 输入 `make` 命令来编译项目。
2. 编译完成后，可执行文件将被命名为 `main`。
3. 运行 `./main` 来执行排序算法性能测试。

## 清理构建

要清理编译生成的文件，包括可执行文件和对象文件，请输入 `make clean` 命令。

## 注意事项

- 确保所有源文件和头文件都位于正确的目录中，并且 `Makefile` 中的路径设置正确。
- 如果你修改了源文件，请重新编译项目以确保更改生效。
- 本项目假定你使用的是符合 C++11 标准的编译器。
