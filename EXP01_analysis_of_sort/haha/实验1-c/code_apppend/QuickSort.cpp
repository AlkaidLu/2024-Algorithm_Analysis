#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <string>
#include <cstring>
using namespace std;
#define UP_BOUND 123456


/**
 * @brief 快速排序，平均时间复杂度O(nlogn),平均比较次数O(nlogn)
 *
 * @param nums 待排序序列
 * @param low 序列起点
 * @param high 序列终点
 * @param cntcmp 比较次数
 * @param cntmov 交换次数（交换次数）
 */
void QuickSort(vector<int> &nums, long long low, long long high,long long &cntcmp,long long &cntmov)
{

	long long i, j;
	int temp;
	if (low >= high)
		return;
	i = low;
	j = high;
	temp = nums[i];

	while (i < j)
	{
		while (i < j && temp < nums[j])
		{
			j--;
			cntcmp++;
		}
		if (i < j)
		{
			nums[i++] = nums[j];
			cntmov++;
			
		}
		while (i < j && temp >= nums[i])
		{
			i++;
			cntcmp++;
			
		}
		if (i < j)
		{
			nums[j--] = nums[i];
			cntmov++;
		
		}
	}
	nums[i] = temp;
	QuickSort(nums, low, --j,cntcmp,cntmov);
	QuickSort(nums, ++i, high,cntcmp,cntmov);
}


// int main()
// {
// 	vector<int> nums = {3, 6, 8, 10, 1, 2, 1};
// 	long long cntcmp = 0, cntmov = 0;
// 	QuickSort(nums, 0, nums.size() - 1, cntcmp, cntmov);
// 	for (int num : nums)
// 	{
// 		cout << num << " ";
// 	}
// 	cout << endl;
// 	cout << cntcmp << " " << cntmov << endl;
// 	return 0;
// }
