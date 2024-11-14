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
 * @brief 冒泡排序，平均时间复杂度O(n^2)，平均比较次数O(n^2)，平均移动次数O(n^2)
 * 
 * @param nums 待排序序列
 * @param cntcmp 比较次数
 * @param cntmov 移动次数（交换次数）
 */
void BubbleSort(vector<int> &nums, long long &cntcmp, long long &cntmov)
{
	int temp;
	bool flag;//标记位，若flag为false，说明该趟没有交换，即排序已完成
	for (int i = nums.size() - 1, flag = (bool)1; i > 0 && flag; i--)
	{
		flag = false;
		for (int j = 0; j < i; j++)
		{
			if (nums[j + 1] < nums[j])
			{
				flag = true;
				temp = nums[j + 1];
				nums[j + 1] = nums[j];
				nums[j] = temp;
				cntmov++;
			}
			cntcmp++;
		}
	}
}

// int main() {
// 	vector<int> nums = {7,6,5,4,3,2,1};
// 	long long cntcmp=0,cntmov=0;
// 	BubbleSort(nums,cntcmp,cntmov);
// 	for (int num : nums) {
// 		cout << num << " ";
// 	}
// 	cout<<endl;
// 	cout<<cntcmp<<" "<<cntmov<<endl;
// 	return 0;
// }
