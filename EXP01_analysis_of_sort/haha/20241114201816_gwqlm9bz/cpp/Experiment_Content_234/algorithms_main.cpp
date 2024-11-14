#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <numeric>  // for std::iota
#include <cstdint>  // for std::int64_t
#include <fstream>  

// 插入排序
std::vector<std::int64_t> insertion_sort(std::vector<std::int64_t> arr, std::int64_t& comparisons, std::int64_t& moves) {
	comparisons = 0;
	moves = 0;
	for (std::int64_t i = 1; i < static_cast<std::int64_t>(arr.size()); ++i) {
		std::int64_t key = arr[i];
		std::int64_t j = i - 1;
		while (j >= 0 && arr[j] > key) {
			++comparisons;
			arr[j + 1] = arr[j];
			++moves;
			--j;
		}
		++comparisons; // for the last failed comparison
		arr[j + 1] = key;
		++moves;
	}
	return arr;
}

// 冒泡排序
std::vector<std::int64_t> bubble_sort(std::vector<std::int64_t> arr, std::int64_t& comparisons, std::int64_t& swaps) {
	comparisons = 0;
	swaps = 0;
	std::int64_t n = arr.size();
	for (std::int64_t i = 0; i < n - 1; ++i) {
		for (std::int64_t j = 0; j < n - i - 1; ++j) {
			++comparisons;
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
				++swaps;
			}
		}
	}
	return arr;
}

// 快速排序的分割函数
std::int64_t partition(std::vector<std::int64_t>& arr, std::int64_t low, std::int64_t high, std::int64_t& comparisons, std::int64_t& swaps) {
	std::int64_t pivot = arr[high];
	std::int64_t i = low - 1;
	for (std::int64_t j = low; j <= high - 1; ++j) {
		++comparisons;
		if (arr[j] < pivot) {
			++i;
			std::swap(arr[i], arr[j]);
			++swaps;
		}
	}
	std::swap(arr[i + 1], arr[high]);
	++swaps;
	return i + 1;
}

// 快速排序
void quick_sort_helper(std::vector<std::int64_t>& arr, std::int64_t low, std::int64_t high, std::int64_t& comparisons, std::int64_t& swaps) {
	if (low < high) {
		std::int64_t pi = partition(arr, low, high, comparisons, swaps);
		quick_sort_helper(arr, low, pi - 1, comparisons, swaps);
		quick_sort_helper(arr, pi + 1, high, comparisons, swaps);
	}
}

std::vector<std::int64_t> quick_sort(std::vector<std::int64_t> arr, std::int64_t& comparisons, std::int64_t& swaps) {
	comparisons = 0;
	swaps = 0;
	quick_sort_helper(arr, 0, static_cast<std::int64_t>(arr.size()) - 1, comparisons, swaps);
	return arr;
}

// 归并排序的合并函数
void merge(std::vector<std::int64_t>& arr, std::int64_t l, std::int64_t m, std::int64_t r, std::int64_t& comparisons, std::int64_t& moves) {
	std::int64_t n1 = m - l + 1;
	std::int64_t n2 = r - m;
	
	std::vector<std::int64_t> L(n1), R(n2);
	for (std::int64_t i = 0; i < n1; ++i)
		L[i] = arr[l + i];
	for (std::int64_t j = 0; j < n2; ++j)
		R[j] = arr[m + 1 + j];
	
	std::int64_t i = 0, j = 0, k = l;
	while (i < n1 && j < n2) {
		++comparisons;
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			++i;
		} else {
			arr[k] = R[j];
			++j;
		}
		++moves;
		++k;
	}
	
	while (i < n1) {
		arr[k] = L[i];
		++i;
		++k;
		++moves;
	}
	while (j < n2) {
		arr[k] = R[j];
		++j;
		++k;
		++moves;
	}
}

// 归并排序
void merge_sort_helper(std::vector<std::int64_t>& arr, std::int64_t l, std::int64_t r, std::int64_t& comparisons, std::int64_t& moves) {
	if (l >= r) return;
	
	std::int64_t m = l + (r - l) / 2;
	merge_sort_helper(arr, l, m, comparisons, moves);
	merge_sort_helper(arr, m + 1, r, comparisons, moves);
	merge(arr, l, m, r, comparisons, moves);
}

std::vector<std::int64_t> merge_sort(std::vector<std::int64_t> arr, std::int64_t& comparisons, std::int64_t& moves) {
	comparisons = 0;
	moves = 0;
	merge_sort_helper(arr, 0, static_cast<std::int64_t>(arr.size()) - 1, comparisons, moves);
	return arr;
}

// 希尔排序
std::vector<std::int64_t> shell_sort(std::vector<std::int64_t> arr, std::int64_t& comparisons, std::int64_t& moves) {
	comparisons = 0;
	moves = 0;
	std::int64_t n = arr.size();
	for (std::int64_t gap = n / 2; gap > 0; gap /= 2) {
		for (std::int64_t i = gap; i < n; ++i) {
			std::int64_t temp = arr[i];
			std::int64_t j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
				arr[j] = arr[j - gap];
				++moves;
				++comparisons;
			}
			arr[j] = temp;
			++moves;
		}
	}
	return arr;
}

void run_experiment(
	const std::string& name, 
	std::vector<std::int64_t> (*sort_func)(std::vector<std::int64_t>, std::int64_t&, std::int64_t&), 
	const std::vector<std::int64_t>& sizes, 
	int num_trials,
	std::ofstream& resultFile)  // 新增加的参数
{
	for (std::int64_t size : sizes) {
		double total_comparisons = 0;
		double total_moves = 0;
		double total_time = 0;
		
		for (int trial = 0; trial < num_trials; ++trial) {
			std::vector<std::int64_t> data(size);
			std::iota(data.begin(), data.end(), 0);  // Fill with 0...size-1
			std::shuffle(data.begin(), data.end(), std::mt19937{std::random_device{}()});
			
			std::int64_t comparisons, moves;
			auto start = std::chrono::high_resolution_clock::now();
			sort_func(data, comparisons, moves);
			auto end = std::chrono::high_resolution_clock::now();
			
			std::chrono::duration<double> elapsed = end - start;
			total_comparisons += comparisons;
			total_moves += moves;
			total_time += elapsed.count();
		}
		
		std::string result = name + " - Size: " + std::to_string(size) + " | "
		+ "Comparisons: " + std::to_string(total_comparisons / num_trials) + " | "
		+ "Moves: " + std::to_string(total_moves / num_trials) + " | "
		+ "Time: " + std::to_string(total_time / num_trials) + "s\n";
		
		std::cout << result;  // 同时打印到控制台
		resultFile << result; // 写入到文件
	}
}

int main() {
	std::vector<std::int64_t> sizes = {100, 200, 300, 400, 500, 700, 800, 1000, 2000, 3000, 5000, 8000, 10000, 20000, 30000, 50000};
	
	std::cout << "Running experiments...\n";
	
	// 打开文件用于写入
	std::ofstream resultFile("sorting_results.txt");
	if (!resultFile.is_open()) {
		std::cerr << "Failed to open the results file.\n";
		return 1;
	}
	
	// 传递resultFile给run_experiment
	run_experiment("Insertion Sort", insertion_sort, sizes, 10, resultFile);
	run_experiment("Bubble Sort", bubble_sort, sizes, 10, resultFile);
	run_experiment("Quick Sort", quick_sort, sizes, 10, resultFile);
	run_experiment("Merge Sort", merge_sort, sizes, 10, resultFile);
	run_experiment("Shell Sort", shell_sort, sizes, 10, resultFile);
	
	resultFile.close();  // 关闭文件
	std::cout << "Experiment completed.\n";
	
	return 0;
}
