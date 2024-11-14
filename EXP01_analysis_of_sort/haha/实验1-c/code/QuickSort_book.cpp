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
 * @brief 教材上快速排序，队尾元素为基元
 * 
 * @param nums 
 * @param low 
 * @param high 
 * @param cntcmp 
 * @param cntmov 
 */
void QuickSort_book(vector<int> &nums, int low, int high, long long &cntcmp, long long &cntmov,int mode)
{
    if (low >= high)
        return;
    int i, j, temp;
    temp = nums[high];
    i = low - 1;
    for (j = low; j <= high - 1; j++)
    {
        cntcmp++;
        if (nums[j] <= temp)
        {
            i++;
            swap(nums[i], nums[j]);
            cntmov++;
        }
    }
    swap(nums[i + 1], nums[high]);
    cntmov++;
    QuickSort_book(nums, low, i, cntcmp, cntmov,0);
    QuickSort_book(nums, i + 2, high, cntcmp, cntmov,0);
}

// int main()
// {
//     vector<int> nums = {3, 6, 8, 10, 1, 2, 1};
//     long long cntcmp = 0, cntmov = 0;
//     QuickSort_book(nums, 0, nums.size() - 1, cntcmp, cntmov);
//     for (int num : nums)
//     {
//         cout << num << " ";
//     }
//     cout << endl;
//     cout << cntcmp << " " << cntmov << endl;
//     return 0;
// }
