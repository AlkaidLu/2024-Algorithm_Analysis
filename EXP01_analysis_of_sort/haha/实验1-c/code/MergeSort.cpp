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
 * @brief 合并两个有序序列
 * 
 * @param nums 
 * @param v1 序列1
 * @param v2 序列2
 * @param cntcmp 比较次数
 * @param cntmov 移动次数（交换次数）
 */
void merge(vector<int> &nums, vector<int> &v1, vector<int> &v2, long long &cntcmp, long long &cntmov)
{
	auto size1 = v1.size();
	auto size2 = v2.size();
	size_t p1 = 0;
	size_t p2 = 0;
	size_t p3 = 0;
	while (p1 < size1 && p2 < size2)
	{
		if (v1[p1] < v2[p2])
			nums[p3++]=v1[p1++];
		else
			nums[p3++]=v2[p2++];
		cntcmp++;
	}

	while (p1 < size1)
	{
		nums[p3++]=v1[p1++];
	}
	while (p2 < size2)
	{
		nums[p3++]=v2[p2++];
	}
}
/**
 * @brief 归并排序，平均时间复杂度O(nlogn),平均比较次数O(nlogn),不涉及交换
 * 
 * @param nums 待排序序列
 * @param cntcmp 比较次数
 * @param cntmov 移动（交换）次数
 */
void MergeSort(vector<int> &nums, long long &cntcmp, long long &cntmov)
{
	if (nums.size() <= 1)
		return;

	auto iter = nums.begin()+nums.size() / 2;
	vector<int> v1(nums.begin(), iter);
	vector<int> v2(iter, nums.end());

	MergeSort(v1, cntcmp, cntmov);
	MergeSort(v2, cntcmp, cntmov);

	merge(nums, v1, v2, cntcmp, cntmov);
}

//  int main() {
//  	vector<int> nums = {9,4,5,3,2,1,1};
//  	long long cntcmp=0,cntmov=0;
//  	MergeSort(nums,cntcmp,cntmov);
//  	for (int num : nums) {
//  		cout << num << " ";
//  	}
//  	cout<<endl;
//  	cout<<cntcmp<<" "<<cntmov<<endl;
//  	return 0;
//  }
