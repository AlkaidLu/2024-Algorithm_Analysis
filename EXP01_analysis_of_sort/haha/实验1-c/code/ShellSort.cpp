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
 * @brief 希尔排序，平均时间复杂度O(n^1.3)
 * 
 * @param nums 
 * @param cntcmp 
 * @param cntmov 
 */
void ShellSort(vector<int> &nums,long long &cntcmp,long long &cntmov) {
	int gap, i, j, temp;
	int len = nums.size();
	for (gap = len >> 1; gap > 0; gap >>= 1) {
		for (i = gap; i < len; i++) {
			temp = nums[i];
			j=i-gap;
			while(j>=0&&temp<nums[j])
			{
				nums[j+gap]=nums[j];
				j-=gap;
				cntcmp++,cntmov++;
			}
			cntcmp++;
			nums[j + gap] = temp;
		}
	}
}


// int main() {
// 	vector<int> nums = {13,19,20,2,1,6,5,9,12,7,8,3,10,11,11};
// 	long long cntcmp=0,cntmov=0;
// 	ShellSort(nums,cntcmp,cntmov);
// 	for (int num : nums) {
// 		cout << num << " ";
// 	}
// 	cout<<endl;
// 	cout<<cntcmp<<" "<<cntmov<<endl;
// 	return 0;
// }

