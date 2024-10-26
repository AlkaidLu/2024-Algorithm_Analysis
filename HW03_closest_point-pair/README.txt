最近点对算法 README

概述：
该项目实现了一个算法，用于在一组点中找到最近的点对，使用两种不同的方法：
朴素的分治法和预处理的分治法。项目包括运行算法的代码、将结果导出到 Excel 
的功能，以及可视化输出的代码。

结构：
.
├── closest_points.cpp         # 最近点对算法的实现
├── closest_points.h           # 最近点对算法的头文件
├── draw.py                    # 用于可视化结果的 Python 脚本
├── intoexcel.py               # 用于将结果导出到 Excel 的 Python 脚本
├── Makefile                   # 编译配置文件
├── results.txt                # 包含算法结果的文本文件
├── output.xlsx                # 包含汇总结果的 Excel 文件
└── output.png                 # draw.py 生成的可视化输出

运行需求：
- Linux环境
- C++ 编译器: 需要一个 C++ 编译器，如 g++ 或 clang++ 来构建项目。
- Python 3: 确保已安装 Python 3 来运行 Python 脚本。
- Python 库: 需要 pandas 和 matplotlib 库。可以使用以下命令安装：
    pip install pandas matplotlib
-首先需要把原来的result.txt文件删除，否则cpp文件会在原来的result.txt文件后面追加输出。

构建项目：
要编译项目，请导航到项目目录并运行：
make
这将生成可执行文件 closest_points。

运行程序：
成功构建项目后，运行程序：
./closest_points
这将执行最近点对算法并生成输出文件 results.txt。

将结果导出到 Excel：
要将 results.txt 中的结果导出到 Excel 文件，请运行：
python3 intoexcel.py
这将创建一个名为 output.xlsx 的 Excel 文件，汇总结果。

可视化结果：
要可视化结果，请执行：
python3 draw.py
这将生成结果的图形表示，并将其保存为 output.png。

输出文件：
- closest_points: 可执行文件。
- results.txt: 算法运行结果的文本文件。
- output.xlsx: 汇总结果的 Excel 文件。
- output.png: 结果的可视化图像。


