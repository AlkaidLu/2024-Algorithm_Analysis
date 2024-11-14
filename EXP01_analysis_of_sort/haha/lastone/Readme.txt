---Algorithm.cpp				五种排序算法的具体实现
---Algorithm.h				五种排序算法的声明
---Draw.py					五种算法结果的绘图与其中三种算法的单独绘图
---DrawQuick.py				六种（三种基元选择方式和三种不同快速排序实现方式）快速排序的绘图
---FiveAlgorithm.cpp			五种排序算法的模拟运行代码，用于获取统计数据（时间，比较次数和交换次数）
---QuickSortAlgorithm.cpp		六种快速排序的算法具体实现
---QuickSortAlgorithm.h		六种快速排序算法的声明
---QuickSortCheck.cpp		快速排序的正确性检验
---QuickSortTest.cpp			六种快速排序的模拟运行代码，用于获取数据（时间，比较次数和交换次数）
---SortCheck.cpp				五种排序算法的正确性检验
---实验报告					实验报告

代码运行流程(推荐输入1000和10)
	首先，在当前目录下打开终端，然后按接下来的步骤运行
	五种排序算法:
	1.g++ FiveAlgorithmTest.cpp -o FiveAlgorithmTest.exe 
	2../FiveAlgorithmTest.exe
	(注意，FiveAlgorithm前面的是./，运行完之后会出现output.txt和output2.txt,分别储存五种排序算法和三种排序算法的数据)
	3.python Draw.py
	(会出现compare_counts.png,run_times.png和swap_counts.png以及compare_counts.png,run_times.png和swap_counts.png，分别记录了五种排序算法和后三种排序算法的比较次数，运行时间和交换次数)

	六种快速排序算法：
	1.g++ QuickSortTest.cpp -o QuickSortTest.exe
	2../QuickSortTest.exe(同上，出现outputQuick.txt)
	3.python DrawQuick.py（同上，会出现compare_countsQuick.png,run_timesQuick.png和swap_countsQuick.png）

