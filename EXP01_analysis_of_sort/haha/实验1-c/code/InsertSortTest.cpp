#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <string>
#include <cstring>
#include "algorithm.h"
#include "out.h"

using namespace std;

void InsertSortTest()
{
    vector<int> nums(10);
    long long cntcmp=0,cntmov=0;
    for (int i = 0; i < 10; i++)
        nums[i] = 10 - i;
    ShellSort(nums,cntcmp,cntmov);
	Out(nums);
    int flag = 0;
    for (int i = 0; i < 10; i++)
    {
        if (nums[i] != i+1)
            flag = 1;
    }
    if (flag)
        cout << "The code is wrong.";
    else
        cout << "The code is correct.";
}
