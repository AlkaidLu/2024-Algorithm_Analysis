#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <string>
#include <cstring>
using namespace std;

// 三数取中函数
int GetMid(vector<int> &nums, int left, int right)
{
	int mid = (left + right) / 2;
	if (nums[left] < nums[mid])
	{
		if (nums[mid] < nums[right])
			return mid;
		else if (nums[left] > nums[right])
			return left;
		else
			return right;
	}
	else
	{
		if (nums[mid] > nums[right])
			return mid;
		else if (nums[left] > nums[right])
			return left;
		else
			return right;
	}
}
/**
 * @brief 快速排序，平均时间复杂度O(nlogn),平均比较次数O(nlogn)
 *
 * @param nums 待排序序列
 * @param low 序列起点
 * @param high 序列终点
 * @param cntcmp 比较次数
 * @param cntmov 交换次数（交换次数）
 * @param mode 中枢点选取模式，0：队首元素 1：随机元素 2：三数取中
 */
void QuickSort(vector<int> &nums, int low, int high, long long &cntcmp, long long &cntmov, int mode = 0)
{

	int i, j, temp;
	if (low >= high)
		return;
	i = low;
	j = high;
	if (mode == 1)
	{
		int randi = rand();
		randi %= (high - low + 1);
		randi += low;
		swap(nums[randi], nums[low]);
	}
	else if (mode == 2)
	{
		int mid=GetMid(nums,low,high);
		swap(nums[mid],nums[low]);
	}
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
	QuickSort(nums, low, --j, cntcmp, cntmov, mode);
	QuickSort(nums, ++i, high, cntcmp, cntmov, mode);
}

//int main() {
//	vector<int> nums = {3, 6, 8, 10, 1, 2, 1};
//	long long cntcmp=0,cntmov=0;
//	QuickSort(nums,0,nums.size()-1,cntcmp,cntmov);
//	for (int num : nums) {
//		cout << num << " ";
//	}
//	cout<<endl;
//	cout<<cntcmp<<" "<<cntmov<<endl;
//	return 0;
//}
