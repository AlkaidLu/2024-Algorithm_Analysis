#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <string>
#include <cstring>
#include "algorithm.h"
using namespace std;
extern long long blockSize;

/**
 * @brief
 *
 * @param nums
 * @param left
 * @param right
 * @param cntcmp
 * @param cntmov
 */
void blockQuickSort(vector<int> &nums, long long left, long long right, long long &cntcmp, long long &cntmov)
{
	if (left >= right)
		return;

	// 对每个块进行排序
	for (long long i = left; i <= right; i += blockSize)
	{
		long long blockRight = min(i + blockSize - 1, right);
		QuickSort(nums, i, blockRight, cntcmp, cntmov);
	}

	// 对整个数组进行快速排序
	int pivot = nums[(left + right) / 2];
	long long i = left, j = right;
	while (i <= j)
	{
		while (nums[i] < pivot)
		{
			cntcmp++;
			i++;
		}
		while (nums[j] > pivot)
		{
			cntcmp++;
			j--;
		}
		if (i <= j)
		{
			swap(nums[i], nums[j]);
			cntmov++;
			i++;
			j--;
		}
	}
	// 递归地对左右两部分进行排序
	blockQuickSort(nums, left, j, cntcmp, cntmov);
	blockQuickSort(nums, i, right, cntcmp, cntmov);
}

// int main()
// {
// 	vector<int> nums = {5, 2, 9, 1, 5, 6, 7, 3, 8, 4};
// 	long long cntcmp = 0, cntmov = 0;
// 	blockQuickSort(nums, 0, nums.size() - 1, cntcmp, cntmov);

// 	for (int num : nums)
// 	{
// 		cout << num << " ";
// 	}
// 	cout << endl;
// 	cout << cntcmp << " " << cntmov;
// 	return 0;
// }
