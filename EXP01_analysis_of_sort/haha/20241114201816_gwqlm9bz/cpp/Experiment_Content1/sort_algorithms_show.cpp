#include <iostream>
#include <vector>
#include <algorithm>

// 插入排序
std::vector<int> insertion_sort(std::vector<int> arr) {
	for (size_t i = 1; i < arr.size(); ++i) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
	return arr;
}

// 冒泡排序
std::vector<int> bubble_sort(std::vector<int> arr) {
	for (size_t i = 0; i < arr.size(); ++i) {
		for (size_t j = 0; j < arr.size() - i - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
	return arr;
}

// 快速排序辅助函数
void quick_sort_helper(std::vector<int>& arr, int left, int right) {
	if (left >= right) {
		return;
	}
	int pivot = arr[(left + right) / 2];
	int i = left, j = right;
	while (i <= j) {
		while (arr[i] < pivot) ++i;
		while (arr[j] > pivot) --j;
		if (i <= j) {
			std::swap(arr[i], arr[j]);
			++i;
			--j;
		}
	}
	quick_sort_helper(arr, left, j);
	quick_sort_helper(arr, i, right);
}

// 快速排序
std::vector<int> quick_sort(std::vector<int> arr) {
	quick_sort_helper(arr, 0, arr.size() - 1);
	return arr;
}

// 合并排序的合并函数
std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right) {
	std::vector<int> result;
	size_t i = 0, j = 0;
	while (i < left.size() && j < right.size()) {
		if (left[i] <= right[j]) {
			result.push_back(left[i++]);
		} else {
			result.push_back(right[j++]);
		}
	}
	while (i < left.size()) {
		result.push_back(left[i++]);
	}
	while (j < right.size()) {
		result.push_back(right[j++]);
	}
	return result;
}

// 合并排序
std::vector<int> merge_sort(std::vector<int> arr) {
	if (arr.size() <= 1) {
		return arr;
	}
	int mid = arr.size() / 2;
	std::vector<int> left = merge_sort(std::vector<int>(arr.begin(), arr.begin() + mid));
	std::vector<int> right = merge_sort(std::vector<int>(arr.begin() + mid, arr.end()));
	return merge(left, right);
}

// 希尔排序
std::vector<int> shell_sort(std::vector<int> arr) {
	int n = arr.size();
	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; ++i) {
			int temp = arr[i];
			int j = i;
			while (j >= gap && arr[j - gap] > temp) {
				arr[j] = arr[j - gap];
				j -= gap;
			}
			arr[j] = temp;
		}
	}
	return arr;
}

int main() {
	std::vector<std::vector<int>> test_arr = {
		{5, 1, 3, 4, 5},
		{},
		{0, 0, 0},
		{1, 2, 3, 4, 5},
		{5, 4, 3, 2, 1}
	};
	
	for (const auto& arr : test_arr) {
		std::cout << "Original: ";
		for (int num : arr) std::cout << num << " ";
		std::cout << std::endl;
		
		auto sorted_arr = insertion_sort(arr);
		std::cout << "Insertion Sort: ";
		for (int num : sorted_arr) std::cout << num << " ";
		std::cout << std::endl;
		
		sorted_arr = bubble_sort(arr);
		std::cout << "Bubble Sort: ";
		for (int num : sorted_arr) std::cout << num << " ";
		std::cout << std::endl;
		
		sorted_arr = quick_sort(arr);
		std::cout << "Quick Sort: ";
		for (int num : sorted_arr) std::cout << num << " ";
		std::cout << std::endl;
		
		sorted_arr = merge_sort(arr);
		std::cout << "Merge Sort: ";
		for (int num : sorted_arr) std::cout << num << " ";
		std::cout << std::endl;
		
		sorted_arr = shell_sort(arr);
		std::cout << "Shell Sort: ";
		for (int num : sorted_arr) std::cout << num << " ";
		std::cout << std::endl;
		
		std::cout << "-----------------------------" << std::endl;
	}
	
	return 0;
}

