#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iomanip>

// 使用 int64_t 来表示大的整数，避免溢出
struct Stats {
    int64_t comparisons = 0;
    int64_t swaps = 0;
};

int64_t partition(std::vector<int64_t>& arr, int64_t low, int64_t high, Stats& stats) {
    int64_t pivot = arr[high];
    int64_t i = low - 1;
    for (int64_t j = low; j < high; ++j) {
        stats.comparisons++;
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
            stats.swaps++;
        }
    }
    std::swap(arr[i + 1], arr[high]);
    stats.swaps++;
    return i + 1;
}

void quick_sort(std::vector<int64_t>& arr, int64_t low, int64_t high, Stats& stats) {
    if (low < high) {
        int64_t p = partition(arr, low, high, stats);
        quick_sort(arr, low, p - 1, stats);
        quick_sort(arr, p + 1, high, stats);
    }
}

int64_t median_of_three(std::vector<int64_t>& arr, int64_t low, int64_t high) {
    int64_t mid = (low + high) / 2;
    if (arr[low] > arr[mid])
        std::swap(arr[low], arr[mid]);
    if (arr[low] > arr[high])
        std::swap(arr[low], arr[high]);
    if (arr[mid] > arr[high])
        std::swap(arr[mid], arr[high]);
    std::swap(arr[mid], arr[high]);
    return arr[high];
}

int64_t partition_median_of_three(std::vector<int64_t>& arr, int64_t low, int64_t high, Stats& stats) {
    int64_t pivot = median_of_three(arr, low, high);
    int64_t i = low - 1;
    for (int64_t j = low; j < high; ++j) {
        stats.comparisons++;
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
            stats.swaps++;
        }
    }
    std::swap(arr[i + 1], arr[high]);
    stats.swaps++;
    return i + 1;
}

void quick_sort_median_of_three(std::vector<int64_t>& arr, int64_t low, int64_t high, Stats& stats) {
    if (low < high) {
        int64_t p = partition_median_of_three(arr, low, high, stats);
        quick_sort_median_of_three(arr, low, p - 1, stats);
        quick_sort_median_of_three(arr, p + 1, high, stats);
    }
}

void run_quick_sort_comparison(const std::vector<int64_t>& sizes, int num_trials = 3) {
	
	std::ofstream outFile("Better_Quick_Sorting.txt");
	if (!outFile.is_open()) {
		std::cerr << "Error opening file for writing." << std::endl;
		return;
	}
	
	outFile << std::fixed << std::setprecision(6);
	
	
    for (auto size : sizes) {
        double avg_comparisons_original = 0;
        double avg_swaps_original = 0;
        double avg_time_original = 0;

        double avg_comparisons_optimized = 0;
        double avg_swaps_optimized = 0;
        double avg_time_optimized = 0;

        for (int trial = 0; trial < num_trials; ++trial) {
            std::vector<int64_t> data(size);
            for (int64_t i = 0; i < size; ++i) {
                data[i] = rand() % 10000;
            }
            
            Stats stats_original;
            {
                auto data_copy = data;
                auto start_time = std::chrono::high_resolution_clock::now();
                quick_sort(data_copy, 0, size - 1, stats_original);
                auto end_time = std::chrono::high_resolution_clock::now();
                avg_time_original += std::chrono::duration<double>(end_time - start_time).count();
            }

            Stats stats_optimized;
            {
                auto data_copy = data;
                auto start_time = std::chrono::high_resolution_clock::now();
                quick_sort_median_of_three(data_copy, 0, size - 1, stats_optimized);
                auto end_time = std::chrono::high_resolution_clock::now();
                avg_time_optimized += std::chrono::duration<double>(end_time - start_time).count();
            }

            avg_comparisons_original += stats_original.comparisons;
            avg_swaps_original += stats_original.swaps;

            avg_comparisons_optimized += stats_optimized.comparisons;
            avg_swaps_optimized += stats_optimized.swaps;
        }

        std::cout << "Size: " << size << std::endl;
        std::cout << "Original Quick Sort - Comparisons: " << avg_comparisons_original / num_trials
                  << ", Swaps: " << avg_swaps_original / num_trials
                  << ", Time: " << avg_time_original / num_trials << "s" << std::endl;
        std::cout << "Optimized Quick Sort - Comparisons: " << avg_comparisons_optimized / num_trials
                  << ", Swaps: " << avg_swaps_optimized / num_trials
                  << ", Time: " << avg_time_optimized / num_trials << "s" << std::endl;
        std::cout << std::endl;
		outFile << "Original Quick Sort - Size: " << size << " | Comparisons: " 
		<< avg_comparisons_original / num_trials << " | Swaps: " 
		<< avg_swaps_original / num_trials << " | Time: " 
		<< avg_time_original / num_trials << "s" << std::endl;
		
		outFile << "Optimized Quick Sort - Size: " << size << " | Comparisons: " 
		<< avg_comparisons_optimized / num_trials << " | Swaps: " 
		<< avg_swaps_optimized / num_trials << " | Time: " 
		<< avg_time_optimized / num_trials << "s" << std::endl;
		
    }
}

int main() {
    srand(time(0));
    std::vector<int64_t> sizes = {100000, 200000, 300000, 500000, 800000, 1000000, 2000000, 3000000, 5000000, 8000000, 10000000};
    run_quick_sort_comparison(sizes);
    std::cout << "Quick Sort comparison experiment completed." << std::endl;
    return 0;
}
