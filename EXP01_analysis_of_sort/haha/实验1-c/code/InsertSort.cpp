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
 * @brief 插入排序，平均时间复杂度O(n^2)，平均比较次数O(n^2)，平均交换次数O(n^2)
 * 
 * @param nums 待排序序列
 * @param cntcmp 比较次数
 * @param cntmov 移动次数（交换次数）
 */
void InsertSort(vector<int> &nums,long long int &cntcmp,long long int &cntmov)
{
	for (int i = 1; i < nums.size(); i++)
	{
		int j = i, key = nums[j];
		while (j > 0 && nums[j - 1] > key)
		{
			nums[j] = nums[j - 1];
			cntcmp++,cntmov++;
			j--;
		}
		cntcmp++;
		nums[j] = key;
	}
}


// int main() {
// 	vector<int> nums = {8,7,6,5,4,3,2,1};
// 	long long cntcmp=0,cntmov=0;
// 	InsertSort(nums,cntcmp,cntmov);
// 	for (int num : nums) {
// 		cout << num << " ";
// 	}
// 	cout<<endl;
// 	cout<<cntcmp<<" "<<cntmov<<endl;
// 	return 0;
// }
