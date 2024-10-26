#include "sort.h"
#include "out.h"

using namespace std;

void InsertSortTest()
{
    vector<int> nums(10);
    for (int i = 0; i < 10; i++)
        nums[i] = 10 - i;
    InsertSort(nums);
    int flag = 0;
    for (int i = 0; i < 10; i++)
    {
        if (nums[i] != i)
            flag = 1;
    }
    if (flag)
        cout << "The code is wrong.";
    else
        cout << "The code is correct.";
}
