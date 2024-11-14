import re
import pandas as pd
import numpy as np

def text_to_excel(input_file, output_file):
    with open(input_file, 'r') as file:
        lines = file.readlines()

    data = []
    vector_size = None

    for i, line in enumerate(lines):
        # 检测并更新 vector_size
        if line.startswith("vector_size"):
            vector_size = int(line.split(":")[1].strip())
        
        # 匹配排序方法并提取相关信息
        elif line.startswith("Sort Name"):
            sort_name = line.split(":")[1].strip()
            
            # 提取平均比较次数、内存访问次数和时间
            compares_line = lines[i + 1]
            accesses_line = lines[i + 2]
            time_line = lines[i + 3]

            # 使用正则表达式提取数据
            compares_match = re.search(r'\d+', compares_line)
            accesses_match = re.search(r'\d+', accesses_line)
            time_match = re.search(r'-?\d+(\.\d+)?([eE][-+]?\d+)?', time_line)
            
            if compares_match and accesses_match and time_match:
                try:
                    compares = int(compares_match.group())
                    accesses = int(accesses_match.group())
                    time = float(time_match.group())
                    data.append([vector_size, sort_name, compares, accesses, time])
                except ValueError:
                    print(f"Skipping invalid time format on line: {time_line.strip()}")

    # 转换为 DataFrame 并写入 Excel
    df = pd.DataFrame(data, columns=["Vector Size", "Sort Name", "Average Compares", "Average Memory Accesses", "Average Time"])
    df.to_excel(output_file, index=False)

# 将文本文件 sorting_data.txt 转换为 Excel 文件 data.xlsx
text_to_excel("sorting_data.txt", "data.xlsx")


import pandas as pd
import matplotlib.pyplot as plt
'''
def plot_line_charts(file):
    """
    根据Excel数据绘制3个折线图，展示不同排序算法的平均比较次数、平均内存访问次数和平均时间，
    使用更多的点样式来区分算法，而线型样式相对简单。
    
    参数:
        file (str): 包含排序数据的Excel文件路径
    """
    # 加载数据
    df = pd.read_excel(file)

    # 提取排序算法名称和向量大小
    sort_methods = df["Sort Name"].unique()
    vector_sizes = sorted(df["Vector Size"].unique())

    # 定义少量的线型样式和更多样的点样式
    line_styles = ['-']  # 简化为单一线型
    marker_styles = ['o', 's', 'D', '^', 'v', 'p', '*', 'X', 'P', 'H', '8', '1', '2', '3', '4']
    num_markers = len(marker_styles)

    # 创建图表
    plt.figure(figsize=(18, 6))

    # 图表1: 平均比较次数
    plt.subplot(1, 3, 1)
    for i, method in enumerate(sort_methods):
        method_data = df[df["Sort Name"] == method]
        plt.plot(
            method_data["Vector Size"], 
            method_data["Average Compares"], 
            label=method, 
            marker=marker_styles[i % num_markers], 
            linestyle=line_styles[0],  # 所有线型相同
            markersize=5, 
            linewidth=1.5
        )
    plt.xscale("log")
    plt.yscale("log")
    plt.xlabel("Vector Size (log scale)")
    plt.ylabel("Average Compares (log scale)")
    plt.title("Average Compares by Vector Size")
    plt.legend(loc="upper left", bbox_to_anchor=(1, 1))

    # 图表2: 平均内存访问次数
    plt.subplot(1, 3, 2)
    for i, method in enumerate(sort_methods):
        method_data = df[df["Sort Name"] == method]
        plt.plot(
            method_data["Vector Size"], 
            method_data["Average Memory Accesses"], 
            label=method, 
            marker=marker_styles[i % num_markers], 
            linestyle=line_styles[0],
            markersize=5, 
            linewidth=1.5
        )
    plt.xscale("log")
    plt.yscale("log")
    plt.xlabel("Vector Size (log scale)")
    plt.ylabel("Average Memory Accesses (log scale)")
    plt.title("Average Memory Accesses by Vector Size")
    plt.legend(loc="upper left", bbox_to_anchor=(1, 1))

        # 图表3: 平均时间 + 复杂度曲线
    plt.subplot(1, 3, 3)
    for i, method in enumerate(sort_methods):
        method_data = df[df["Sort Name"] == method]
        plt.plot(
            method_data["Vector Size"], 
            method_data["Average Time"], 
            label=method, 
            marker=marker_styles[i % num_markers], 
            linestyle=line_styles[0],
            markersize=5, 
            linewidth=1.5
        )

    # 添加O(n log n)和O(n^2)复杂度曲线
    n_values = np.array(vector_sizes)
    plt.plot(n_values, 0.00000001*n_values * np.log2(n_values), 'k--', label="O(n log n)", linewidth=1.5)  # 黑色虚线
    plt.plot(n_values, 0.00000001*n_values ** 2, 'k:', label="O(n^2)", linewidth=1.5)  # 黑色点线

    plt.xscale("log")
    plt.yscale("log")
    plt.xlabel("Vector Size (log scale)")
    plt.ylabel("Average Time (seconds, log scale)")
    plt.title("Average Time by Vector Size with Complexity Curves")
    plt.legend(loc="upper left", bbox_to_anchor=(1, 1))

    # 调整布局并显示图表
    plt.tight_layout(rect=[0, 0, 0.85, 1])
    plt.savefig("data.png")

# 从data.xlsx文件中读取数据并绘制图表
plot_line_charts("data.xlsx")

'''
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

def plot_basic_sorts(file):
    """
    绘制基本排序算法的性能比较
    """
    df = pd.read_excel(file)
    basic_sorts = ["InsertSort", "BubbleSort", "QuickSort_Hoare", "MergeSort", "ShellSort"]
    vector_sizes = sorted(df["Vector Size"].unique())
    plt.figure(figsize=(36, 12))

    # 平均时间
    plt.subplot(1, 3, 1)
    for i, method in enumerate(basic_sorts):
        method_data = df[df["Sort Name"] == method]
        plt.plot(
            method_data["Vector Size"], 
            method_data["Average Time"], 
            label=method, 
            marker='o', 
            markersize=5, 
            linewidth=1.5
        )
    n_values = np.array(vector_sizes)
    plt.plot(n_values, 0.00000001*n_values * np.log2(n_values), 'k--', label="O(n log n)", linewidth=1.5)
    plt.plot(n_values, 0.00000001*n_values ** 2, 'k:', label="O(n^2)", linewidth=1.5)

    plt.xscale("log")
    plt.yscale("log")
    plt.xlabel("Vector Size (log scale)")
    plt.ylabel("Average Time (seconds, log scale)")
    plt.title("Basic Sorts: Average Time")
    plt.legend(loc="upper left", bbox_to_anchor=(1, 1))

    # 平均内存访问次数
    plt.subplot(1, 3, 2)
    for i, method in enumerate(basic_sorts):
        method_data = df[df["Sort Name"] == method]
        plt.plot(
            method_data["Vector Size"], 
            method_data["Average Memory Accesses"], 
            label=method, 
            marker='o', 
            markersize=5, 
            linewidth=1.5
        )
    plt.xscale("log")
    plt.yscale("log")
    plt.xlabel("Vector Size (log scale)")
    plt.ylabel("Average Memory Accesses (log scale)")
    plt.title("Basic Sorts: Average Memory Accesses")
    plt.legend(loc="upper left", bbox_to_anchor=(1, 1))

    # 平均比较次数
    plt.subplot(1, 3, 3)
    for i, method in enumerate(basic_sorts):
        method_data = df[df["Sort Name"] == method]
        plt.plot(
            method_data["Vector Size"], 
            method_data["Average Compares"], 
            label=method, 
            marker='o', 
            markersize=5, 
            linewidth=1.5
        )
    plt.xscale("log")
    plt.yscale("log")
    plt.xlabel("Vector Size (log scale)")
    plt.ylabel("Average Compares (log scale)")
    plt.title("Average Compares by Vector Size")
    plt.legend(loc="upper left", bbox_to_anchor=(1, 1))

    #plt.tight_layout(rect=[0, 0, 0.85, 1])
    plt.subplots_adjust(left=0.05, right=0.95, top=0.85, bottom=0.1, wspace=0.3, hspace=0.3)
    plt.savefig("Basic_sorting_performance_comparison.png")
    plt.close()

def plot_optimized_quick_sort(file):
    """
    绘制优化前后的快速排序比较
    """
    df = pd.read_excel(file)
    optimized_quick_sort = ["QuickSort_Hole", "QuickSort_Hole_Better_Selection"]
    vector_sizes = sorted(df["Vector Size"].unique())

    plt.figure(figsize=(36, 12))

    # 平均时间
    plt.subplot(1, 3, 1)
    for i, method in enumerate(optimized_quick_sort):
        method_data = df[df["Sort Name"] == method]
        plt.plot(
            method_data["Vector Size"], 
            method_data["Average Time"], 
            label=method, 
            marker='o', 
            markersize=5, 
            linewidth=1.5
        )
    n_values = np.array(vector_sizes)
    plt.plot(n_values, 0.00000001*n_values * np.log2(n_values), 'k--', label="O(n log n)", linewidth=1.5)
  
    plt.xscale("log")
    plt.yscale("log")
    plt.xlabel("Vector Size (log scale)")
    plt.ylabel("Average Time (seconds, log scale)")
    plt.title("Optimized Quick Sort: Average Time")
    plt.legend(loc="upper left", bbox_to_anchor=(1, 1))

    # 平均内存访问次数
    plt.subplot(1, 3, 2)
    for i, method in enumerate(optimized_quick_sort):
        method_data = df[df["Sort Name"] == method]
        plt.plot(
            method_data["Vector Size"], 
            method_data["Average Memory Accesses"], 
            label=method, 
            marker='o', 
            markersize=5, 
            linewidth=1.5
        )
    plt.xscale("log")
    plt.yscale("log")
    plt.xlabel("Vector Size (log scale)")
    plt.ylabel("Average Memory Accesses (log scale)")
    plt.title("Optimized Quick Sort: Average Memory Accesses")
    plt.legend(loc="upper left", bbox_to_anchor=(1, 1))

    # 平均比较次数
    plt.subplot(1, 3, 3)
    for i, method in enumerate(optimized_quick_sort):
        method_data = df[df["Sort Name"] == method]
        plt.plot(
            method_data["Vector Size"], 
            method_data["Average Compares"], 
            label=method, 
            marker='o', 
            markersize=5, 
            linewidth=1.5
        )
    plt.xscale("log")
    plt.yscale("log")
    plt.xlabel("Vector Size (log scale)")
    plt.ylabel("Average Compares (log scale)")
    plt.title("Average Compares by Vector Size")
    plt.legend(loc="upper left", bbox_to_anchor=(1, 1))
    plt.subplots_adjust(left=0.05, right=0.95, top=0.85, bottom=0.1, wspace=0.3, hspace=0.3)
    plt.savefig("optimized_quick_sort_sorting_performance_comparison.png")
    plt.close()

def plot_multi_quick_sorts(file):

    """
    绘制多种快速排序实现的比较
    """
    df = pd.read_excel(file)
    advanced_quick_sorts = ["QuickSort_Hole", "QuickSort_Hoare", "QuickSort_Book", "QuickSort_Hole_Better_Selection", "BlockQuickSort"]
    vector_sizes = sorted(df["Vector Size"].unique())

    plt.figure(figsize=(36, 12))

    # 平均时间
    plt.subplot(1, 3, 1)
    for i, method in enumerate(advanced_quick_sorts):
        method_data = df[df["Sort Name"] == method]
        plt.plot(
            method_data["Vector Size"], 
            method_data["Average Time"], 
            label=method, 
            marker='o', 
            markersize=5, 
            linewidth=1.5
        )
    n_values = np.array(vector_sizes)
    plt.plot(n_values, 0.00000001*n_values * np.log2(n_values), 'k--', label="O(n log n)", linewidth=1.5)
   

    plt.xscale("log")
    plt.yscale("log")
    plt.xlabel("Vector Size (log scale)")
    plt.ylabel("Average Time (seconds, log scale)")
    plt.title("multi Quick Sorts: Average Time")
    plt.legend(loc="upper left", bbox_to_anchor=(1, 1))

    # 平均内存访问次数
    plt.subplot(1, 3, 2)
    for i, method in enumerate(advanced_quick_sorts):
        method_data = df[df["Sort Name"] == method]
        plt.plot(
            method_data["Vector Size"], 
            method_data["Average Memory Accesses"], 
            label=method, 
            marker='o', 
            markersize=5, 
            linewidth=1.5
        )
    plt.xscale("log")
    plt.yscale("log")
    plt.xlabel("Vector Size (log scale)")
    plt.ylabel("Average Memory Accesses (log scale)")
    plt.title("multi Quick Sorts: Average Memory Accesses")
    plt.legend(loc="upper left", bbox_to_anchor=(1, 1))

    # 平均比较次数
    plt.subplot(1, 3, 3)
    for i, method in enumerate(advanced_quick_sorts):
        method_data = df[df["Sort Name"] == method]
        plt.plot(
            method_data["Vector Size"], 
            method_data["Average Compares"], 
            label=method, 
            marker='o', 
            markersize=5, 
            linewidth=1.5
        )

    plt.xscale("log")
    plt.yscale("log")
    plt.xlabel("Vector Size (log scale)")
    plt.ylabel("Average Compares (log scale)")
    plt.title("multi Quick Sorts:Average Compares by Vector Size")
    plt.legend(loc="upper left", bbox_to_anchor=(1, 1))

    plt.subplots_adjust(left=0.05, right=0.95, top=0.85, bottom=0.1, wspace=0.3, hspace=0.3)
    plt.savefig("multi_quick_sort_sorting_performance_comparison.png")
    plt.close()

plot_basic_sorts("data.xlsx")
plot_optimized_quick_sort("data.xlsx")
plot_multi_quick_sorts("data.xlsx")

