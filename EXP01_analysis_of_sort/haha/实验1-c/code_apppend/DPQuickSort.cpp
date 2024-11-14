#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <string>
#include <cstring>
using namespace std;

/**
 * @brief 
 * 
 * @param arr 
 * @param low 
 * @param high 
 * @param cntcmp 
 * @param cntmov 
 */
void DPQuickSort(vector<int> &arr, long long low, long long high, long long &cntcmp, long long &cntmov)
{
	if (low < high)
	{
		// 选择两个轴
		if (arr[low] > arr[high])
		{
			swap(arr[low], arr[high]);
			cntmov++;
		}

		int leftPivot = arr[low];
		int rightPivot = arr[high];

		long long i = low + 1;
		long long lt = low + 1;
		long long gt = high - 1;

		while (i <= gt)
		{
			cntcmp++;
			if (arr[i] < leftPivot)
			{
				swap(arr[i], arr[lt]);
				lt++;
			}
			else if (arr[i] > rightPivot)
			{
				while (arr[gt] > rightPivot && i < gt)
				{
					cntcmp++;
					gt--;
				}
				swap(arr[i], arr[gt]);
				cntmov++;
				gt--;
				cntcmp++;
				if (arr[i] < leftPivot)
				{
					swap(arr[i], arr[lt]);
					cntmov++;
					lt++;
				}
			}
			i++;
		}

		lt--;
		gt++;

		swap(arr[low], arr[lt]);
		swap(arr[high], arr[gt]);
		cntmov += 2;

		DPQuickSort(arr, low, lt - 1, cntcmp, cntmov);
		DPQuickSort(arr, lt + 1, gt - 1, cntcmp, cntmov);
		DPQuickSort(arr, gt + 1, high, cntcmp, cntmov);
	}
}

// int main()
// {
// 	vector<int> nums = {3, 6, 8, 10, 1, 2, 1};
// 	long long cntcmp = 0, cntmov = 0;
// 	DPQuickSort(nums, 0, nums.size() - 1, cntcmp, cntmov);
// 	for (int num : nums)
// 	{
// 		cout << num << " ";
// 	}
// 	cout << endl;
// 	cout << cntcmp << " " << cntmov << endl;
// 	return 0;
// }
