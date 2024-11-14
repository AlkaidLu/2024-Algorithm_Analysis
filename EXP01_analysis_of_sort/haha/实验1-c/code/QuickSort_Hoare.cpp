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
 * @brief original quickSort
 * 
 * @param nums 
 * @param low 
 * @param high 
 * @param cntcmp 
 * @param cntmov 
 */
void QuickSort_Hoare(vector<int> &nums, int low, int high, long long &cntcmp, long long &cntmov,int mode)
{
    if (low >= high)
        return;
    int i, j, temp;
    i = low, j = high + 1;
    temp = nums[low];
    while (i < j)
    {
        do
        {
            j--;
			cntcmp++;
        } while (nums[j] > temp);
        do
        {
            i++;
			cntcmp++;
        } while (nums[i] < temp);

        if (i < j)
        {
            swap(nums[i], nums[j]);
			cntmov++;
        }
    }
	swap(nums[low],nums[j]);
	cntmov++;
    QuickSort_Hoare(nums, low, j-1 , cntcmp, cntmov,0);
    QuickSort_Hoare(nums, j + 1, high, cntcmp, cntmov,0);
}

// int main()
// {
//     vector<int> nums = {3, 6, 8, 10, 1, 2, 1};
//     long long cntcmp = 0, cntmov = 0;
//     QuickSort_Hoare(nums, 0, nums.size() - 1, cntcmp, cntmov);
//     for (int num : nums)
//     {
//         cout << num << " ";
//     }
//     cout << endl;
//     cout << cntcmp << " " << cntmov << endl;
//     return 0;
// }
