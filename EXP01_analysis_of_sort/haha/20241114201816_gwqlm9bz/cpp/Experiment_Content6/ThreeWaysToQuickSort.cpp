#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cstdint>  // 引入int64_t

struct PerformanceCounter {
	int64_t comparisons = 0;
	int64_t swaps = 0;
};

int64_t partition(std::vector<int64_t>& arr, int64_t low, int64_t high, PerformanceCounter& pc) {
	int64_t pivot = arr[low];
	int64_t i = low, j = high + 1;
	
	while (true) {
		while (arr[++i] <= pivot) {
			if (i == high) break;
			pc.comparisons++;
		}
		while (arr[--j] > pivot) {
			if (j == low) break;
			pc.comparisons++;
		}
		if (i >= j) break;
		std::swap(arr[i], arr[j]);
		pc.swaps++;
	}
	std::swap(arr[low], arr[j]);
	pc.swaps++;
	return j;
}

void quickSort(std::vector<int64_t>& arr, int64_t low, int64_t high, PerformanceCounter& pc) {
	if (low < high) {
		int64_t p = partition(arr, low, high, pc);
		quickSort(arr, low, p - 1, pc);
		quickSort(arr, p + 1, high, pc);
	}
}

int64_t randomPartition(std::vector<int64_t>& arr, int64_t low, int64_t high, PerformanceCounter& pc) {
	int64_t randomIndex = low + rand() % (high - low + 1);
	std::swap(arr[low], arr[randomIndex]);
	pc.swaps++;
	return partition(arr, low, high, pc);
}

void randomQuickSort(std::vector<int64_t>& arr, int64_t low, int64_t high, PerformanceCounter& pc) {
	if (low < high) {
		int64_t p = randomPartition(arr, low, high, pc);
		randomQuickSort(arr, low, p - 1, pc);
		randomQuickSort(arr, p + 1, high, pc);
	}
}

void threeWayPartition(std::vector<int64_t>& arr, int64_t low, int64_t high, int64_t& i, int64_t& j, PerformanceCounter& pc) {
	int64_t pivot = arr[low];
	i = low;
	j = high;
	int64_t k = low;
	
	while (k <= j) {
		if (arr[k] < pivot) {
			pc.comparisons++;  // 仅当需要比较时增加比较计数
			std::swap(arr[i++], arr[k++]);
			pc.swaps++;
		} else if (arr[k] > pivot) {
			pc.comparisons++;  // 同样，仅当需要比较时增加计数
			std::swap(arr[k], arr[j--]);
			pc.swaps++;
		} else {
			k++;
		}
	}
}

void threeWayQuickSort(std::vector<int64_t>& arr, int64_t low, int64_t high, PerformanceCounter& pc) {
	if (low < high) {
		int64_t i, j;
		threeWayPartition(arr, low, high, i, j, pc);
		threeWayQuickSort(arr, low, i - 1, pc);
		threeWayQuickSort(arr, j + 1, high, pc);
	}
}

void testQuickSortAlgorithms() {
	std::ofstream resultFile("three_ways_sorting_result.txt");
	if (!resultFile) {
		std::cerr << "Failed to open the output file." << std::endl;
		return;
	}
	
	const int64_t sizes[] = {1000000, 2000000, 3000000, 5000000, 10000000, 20000000}; // 样本数量
	const int num_trials = 5;  // 每个size进行5次测试
	srand(time(0));
	
	for (int64_t size : sizes) {
		double total_time_basic = 0, total_time_random = 0, total_time_threeway = 0;
		int64_t total_comparisons_basic = 0, total_swaps_basic = 0;
		int64_t total_comparisons_random = 0, total_swaps_random = 0;
		int64_t total_comparisons_threeway = 0, total_swaps_threeway = 0;
		
		for (int trial = 0; trial < num_trials; ++trial) {
			std::vector<int64_t> arr(size);
			for (int64_t i = 0; i < size; ++i) {
				arr[i] = rand() % (size);
			}
			
			// 基本快速排序测试
			PerformanceCounter pc_basic;
			std::vector<int64_t> arr_basic = arr;
			clock_t start = clock();
			quickSort(arr_basic, 0, size - 1, pc_basic);
			clock_t end = clock();
			double time_basic = double(end - start) / CLOCKS_PER_SEC;
			
			total_comparisons_basic += pc_basic.comparisons;
			total_swaps_basic += pc_basic.swaps;
			total_time_basic += time_basic;
			
			// 随机化快速排序测试
			PerformanceCounter pc_random;
			std::vector<int64_t> arr_random = arr;
			start = clock();
			randomQuickSort(arr_random, 0, size - 1, pc_random);
			end = clock();
			double time_random = double(end - start) / CLOCKS_PER_SEC;
			
			total_comparisons_random += pc_random.comparisons;
			total_swaps_random += pc_random.swaps;
			total_time_random += time_random;
			
			// 三路快速排序测试
			PerformanceCounter pc_threeway;
			std::vector<int64_t> arr_threeway = arr;
			start = clock();
			threeWayQuickSort(arr_threeway, 0, size - 1, pc_threeway);
			end = clock();
			double time_threeway = double(end - start) / CLOCKS_PER_SEC;
			
			total_comparisons_threeway += pc_threeway.comparisons;
			total_swaps_threeway += pc_threeway.swaps;
			total_time_threeway += time_threeway;
		}
		
		// 计算每种排序的平均值
		double avg_time_basic = total_time_basic / num_trials;
		double avg_time_random = total_time_random / num_trials;
		double avg_time_threeway = total_time_threeway / num_trials;
		
		int64_t avg_comparisons_basic = total_comparisons_basic / num_trials;
		int64_t avg_swaps_basic = total_swaps_basic / num_trials;
		
		int64_t avg_comparisons_random = total_comparisons_random / num_trials;
		int64_t avg_swaps_random = total_swaps_random / num_trials;
		
		int64_t avg_comparisons_threeway = total_comparisons_threeway / num_trials;
		int64_t avg_swaps_threeway = total_swaps_threeway / num_trials;
		
		// 输出结果到文件
		resultFile << "Basic QuickSort - Size: " << size << " | Comparisons: "
		<< avg_comparisons_basic << " | Swaps: " << avg_swaps_basic
		<< " | Time: " << avg_time_basic << "s\n";
		
		resultFile << "Randomized QuickSort - Size: " << size << " | Comparisons: "
		<< avg_comparisons_random << " | Swaps: " << avg_swaps_random
		<< " | Time: " << avg_time_random << "s\n";
		
		resultFile << "Three-Ways QuickSort - Size: " << size << " | Comparisons: "
		<< avg_comparisons_threeway << " | Swaps: " << avg_swaps_threeway
		<< " | Time: " << avg_time_threeway << "s\n";
		
		// 同时输出到控制台
		std::cout << "Basic QuickSort - Size: " << size << " | Comparisons: "
		<< avg_comparisons_basic << " | Swaps: " << avg_swaps_basic
		<< " | Time: " << avg_time_basic << "s\n";
		
		std::cout << "Randomized QuickSort - Size: " << size << " | Comparisons: "
		<< avg_comparisons_random << " | Swaps: " << avg_swaps_random
		<< " | Time: " << avg_time_random << "s\n";
		
		std::cout << "Three-Ways QuickSort - Size: " << size << " | Comparisons: "
		<< avg_comparisons_threeway << " | Swaps: " << avg_swaps_threeway
		<< " | Time: " << avg_time_threeway << "s\n";
	}
	
	resultFile.close();
}

int main() {
	testQuickSortAlgorithms();
	return 0;
}
