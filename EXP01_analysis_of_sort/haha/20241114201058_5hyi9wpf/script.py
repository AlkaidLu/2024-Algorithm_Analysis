import subprocess
import matplotlib.pyplot as plt
import numpy as np
import os

# 创建图片文件夹
if not os.path.exists("./pictures"):
    os.makedirs("./pictures")

# 定义要运行的排序算法和问题规模
algorithms = [
    "InsertSort",
    "BubbleSort",
    "MergeSort",
    "QuickSort",
    "ShellSort",
    "BlockQuickSort",
    "DualPivotQuickSort",
    "LogQuickSort",
    "OptimizedQuickSort",
]
sizes = [
    10**1,
    2 * 10**1,
    3 * 10**1,
    4 * 10**1,
    5 * 10**1,
    6 * 10**1,
    7 * 10**1,
    8 * 10**1,
    9 * 10**1,
    10**2,
    2 * 10**2,
    3 * 10**2,
    4 * 10**2,
    5 * 10**2,
    6 * 10**2,
    7 * 10**2,
    8 * 10**2,
    9 * 10**2,
    10**3,
    2 * 10**3,
    3 * 10**3,
    4 * 10**3,
    5 * 10**3,
    6 * 10**3,
    7 * 10**3,
    8 * 10**3,
    9 * 10**3,
    10**4,
    2 * 10**4,
    3 * 10**4,
    4 * 10**4,
    5 * 10**4,
    6 * 10**4,
    7 * 10**4,
    8 * 10**4,
    9 * 10**4,
    10**5,
    10**6,
    10**7,
    10**8,
]


# 运行排序算法
def run_sorting_algorithm(algo, size_local):
    print(f"Running {algo} with size {size_local}...")
    result = subprocess.run(
        [
            "./main.o",
            f"--function={algo}",
            f"--size={size_local}",
            "--repeat=10",
        ],
        capture_output=True,
        text=True,
    )
    output = result.stdout
    time_line = [line for line in output.split("\n") if "The average time" in line][0]
    comparisons_line = [line for line in output.split("\n") if "Comparisons" in line]
    moves_line = [line for line in output.split("\n") if "Moves" in line]
    branch_predictions_line = [
        line for line in output.split("\n") if "Branch Predictions" in line
    ]
    recursion_depth_line = [
        line for line in output.split("\n") if "Recursion Depth" in line
    ]

    time = float(time_line.split()[-2])
    comparisons = int(comparisons_line[0].split()[-1]) if comparisons_line else 0
    moves = int(moves_line[0].split()[-1]) if moves_line else 0
    branch_predictions = (
        int(branch_predictions_line[0].split()[-1]) if branch_predictions_line else 0
    )
    recursion_depth = (
        int(recursion_depth_line[0].split()[-1]) if recursion_depth_line else 0
    )

    print(f"{algo} with size {size_local} completed.")
    return time, comparisons, moves, branch_predictions, recursion_depth


# 收集所有数据
data = {
    algo: {
        "times": [],
        "comparisons": [],
        "moves": [],
        "branch_predictions": [],
        "recursion_depth": [],
    }
    for algo in algorithms
}

for size in sizes:
    for algo in algorithms:
        if size >= 10**6 and algo in ["InsertSort", "BubbleSort"]:
            continue
        time, comparisons, moves, branch_predictions, recursion_depth = (
            run_sorting_algorithm(algo, size)
        )
        data[algo]["times"].append(time)
        data[algo]["comparisons"].append(comparisons)
        data[algo]["moves"].append(moves)
        data[algo]["branch_predictions"].append(branch_predictions)
        data[algo]["recursion_depth"].append(recursion_depth)


# 任务一：绘制插入排序、冒泡排序、快速排序、归并排序、Shell排序的运行时间图
plt.figure(figsize=(7, 5))

for algo in algorithms[:6]:  # 增加 LogQuickSort 对比
    if algo in data and data[algo]["times"]:
        plt.plot(sizes[: len(data[algo]["times"])], data[algo]["times"], label=algo)
plt.xscale("log")
plt.yscale("log")
plt.xlabel("Input Size (log scale)")
plt.ylabel("Time (s)")
plt.title("Sorting Algorithms Time Complexity")
plt.legend()
plt.savefig("./pictures/sorting_time_complexity.png")
plt.close()

# 任务一：绘制插入排序、冒泡排序、快速排序、归并排序、Shell排序的比较次数图
plt.figure(figsize=(14, 5))
plt.subplot(1, 2, 1)
for algo in algorithms[:6]:  # 增加 LogQuickSort 对比
    if algo in data and data[algo]["comparisons"]:
        plt.plot(
            sizes[: len(data[algo]["comparisons"])],
            data[algo]["comparisons"],
            label=algo,
        )
plt.xscale("log")
plt.yscale("log")
plt.xlabel("Input Size (log scale)")
plt.ylabel("Comparisons")
plt.title("Sorting Algorithms Comparisons")
plt.legend()

# 绘制插入排序、冒泡排序、快速排序、归并排序、Shell排序的移动次数图
plt.subplot(1, 2, 2)
for algo in algorithms[:6]:  # 增加 LogQuickSort 对比
    if algo in data and data[algo]["moves"]:
        plt.plot(sizes[: len(data[algo]["moves"])], data[algo]["moves"], label=algo)
plt.xscale("log")
plt.yscale("log")
plt.xlabel("Input Size (log scale)")
plt.ylabel("Moves")
plt.title("Sorting Algorithms Moves")
plt.legend()
# 保存任务一的图片
plt.savefig("./pictures/sorting_key_ops.png")
plt.close()

# 任务二：BlockQuickSort和DualPivotQuickSort的分支预测次数和递归深度(与QuickSort进行对比)
plt.figure(figsize=(14, 5))
plt.subplot(1, 2, 1)

plt.plot(
    sizes,
    data["BlockQuickSort"]["branch_predictions"],
    label="BlockQuickSort Branch Predictions",
)
plt.plot(
    sizes,
    data["LogQuickSort"]["branch_predictions"],
    label="QuickSort Branch Predictions",
)
plt.xscale("log")
plt.yscale("log")
plt.xlabel("Input Size (log scale)")
plt.ylabel("Count")
plt.title("BlockQuickSort vs QuickSort Branch Predictions")
plt.legend()

plt.subplot(1, 2, 2)

plt.plot(
    sizes,
    data["DualPivotQuickSort"]["recursion_depth"],
    label="DualPivotQuickSort Recursion Depth",
)
plt.plot(
    sizes,
    data["LogQuickSort"]["recursion_depth"],
    label="QuickSort Recursion Depth",
)
plt.xscale("log")
plt.yscale("log")
plt.xlabel("Input Size (log scale)")
plt.ylabel("Count")
plt.title("DualPivotQuickSort vs QuickSort Recursion Depth")
plt.legend()
# 保存任务二的图片
plt.savefig("./pictures/blockquick_dualpivot.png")
plt.tight_layout()


# 任务三：QuickSort与OptimizedQuickSort运行时间对比图
plt.figure(figsize=(14, 7))
plt.subplot(1, 2, 1)
for algo in ["QuickSort", "OptimizedQuickSort"]:
    if algo in data and data[algo]["times"]:
        plt.plot(sizes[: len(data[algo]["times"])], data[algo]["times"], label=algo)
plt.xscale("log")
plt.yscale("log")
plt.xlabel("Input Size (log scale)")
plt.ylabel("Time (s)")
plt.title("QuickSort vs OptimizedQuickSort Time Complexity")
plt.legend()

# OptimizedQuickSort的加速比图
plt.subplot(1, 2, 2)
quick_times = np.array(data["QuickSort"]["times"])
optimized_times = np.array(data["OptimizedQuickSort"]["times"])
speedup = ((quick_times - optimized_times) / quick_times) * 100
plt.plot(sizes[: len(speedup)], speedup, label="Speedup (%)")
plt.xscale("log")
plt.xlabel("Input Size (log scale)")
plt.ylabel("Speedup (%)")
plt.title("OptimizedQuickSort Speedup over QuickSort")
plt.legend()

plt.tight_layout()
plt.savefig("./pictures/quick_vs_optimized_with_speedup.png")
plt.close()

# 任务四：三种快速排序算法性能对比
sizes_large = [10**8]  # 设置规模为一亿
repeats = 1
quick_sorts = [
    "QuickSort",
    "BlockQuickSort",
    "DualPivotQuickSort",
]
performance_data = {algo: [] for algo in quick_sorts}

for algo in quick_sorts:
    for _ in range(repeats):
        time, _, _, _, _ = run_sorting_algorithm(algo, sizes_large[0])
        performance_data[algo].append(time)

# 绘制柱状图
plt.figure(figsize=(10, 6))
x = np.arange(len(quick_sorts))
avg_times = [np.mean(performance_data[algo]) for algo in quick_sorts]
plt.bar(x, avg_times, tick_label=quick_sorts)
plt.xlabel("Quick Sort Algorithms")
plt.ylabel("Average Time (s)")
plt.title("Quick Sort Algorithms Performance Comparison")
plt.savefig("./pictures/quick_sort_performance.png")
# plt.show()
