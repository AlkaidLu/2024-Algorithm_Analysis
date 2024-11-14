#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <string>
#include <cstring>
#include "QuickSortAlgorithm.h"


using namespace std;

void QuickSortTest()
{
    long long CntCmp,CntSwp;
    vector<int> nums(100);
    for (int i = 0; i < 100; i++)
        nums[i] = 100 - i;
    QuickSort(nums,0, nums.size()-1,CntCmp,CntSwp);
    int flag = 0;
    for (int i = 0; i < 100; i++) 
    {
        if (nums[i] != i+1)
            flag = 1;
    }
    if (flag)
    {
        cout << "The QuickSort code is incorrect." << endl;
        Prt(nums);
    }
    else
        cout << "The QuickSort code is right." << endl;
}

void QuickSortRandTest()
{
    long long CntCmp,CntSwp;
    vector<int> nums(100);
    for (int i = 0; i < 100; i++)
        nums[i] = 100 - i;
    QuickSortRand(nums,0, nums.size()-1,CntCmp,CntSwp);
    int flag = 0;
    for (int i = 0; i < 100; i++) 
    {
        if (nums[i] != i+1)
            flag = 1;
    }
    if (flag)
    {
        cout << "The QuickSortRand code is incorrect." << endl;
        Prt(nums);
    }
    else
        cout << "The QuickSortRand code is right." << endl;
}

void QuickSortThreeTest()
{
    long long CntCmp,CntSwp;
    vector<int> nums(100);
    for (int i = 0; i < 100; i++)
        nums[i] = 100 - i;
    QuickSortThree(nums,0, nums.size()-1,CntCmp,CntSwp);
    int flag = 0;
    for (int i = 0; i < 100; i++) 
    {
        if (nums[i] != i+1)
            flag = 1;
    }
    if (flag)
    {
        cout << "The QuickSortThree code is incorrect." << endl;
        Prt(nums);
    }
    else
        cout << "The QuickSortThree code is right." << endl;
}

void QuickSortKongXueTest()
{
    long long CntCmp,CntSwp;
    vector<int> nums(100);
    for (int i = 0; i < 100; i++)
        nums[i] = 100 - i;
    QuickSortKongXue(nums,0, nums.size()-1,CntCmp,CntSwp);
    int flag = 0;
    for (int i = 0; i < 100; i++) 
    {
        if (nums[i] != i+1)
            flag = 1;
    }
    if (flag)
    {
        cout << "The QuickSortKongXue code is incorrect." << endl;
        Prt(nums);
    }
    else
        cout << "The QuickSortKongXue code is right." << endl;
}

void QuickSortHoareTest()
{
    long long CntCmp,CntSwp;
    vector<int> nums(100);
    for (int i = 0; i < 100; i++)
        nums[i] = 100 - i;
    QuickSortHoare(nums,0, nums.size()-1,CntCmp,CntSwp);
    int flag = 0;
    for (int i = 0; i < 100; i++) 
    {
        if (nums[i] != i+1)
            flag = 1;
    }
    if (flag)
    {
        cout << "The QuickSortHoare code is incorrect." << endl;
        Prt(nums);
    }
    else
        cout << "The QuickSortHoare code is right." << endl;
}

void QuickSortLomutoTest()
{
    long long CntCmp,CntSwp;
    vector<int> nums(100);
    for (int i = 0; i < 100; i++)
        nums[i] = 100 - i;
    QuickSortLomuto(nums,0, nums.size()-1,CntCmp,CntSwp);
    int flag = 0;
    for (int i = 0; i < 100; i++) 
    {
        if (nums[i] != i+1)
            flag = 1;
    }
    if (flag)
    {
        cout << "The QuickSortLomuto code is incorrect." << endl;
        Prt(nums);
    }
    else
        cout << "The QuickSortLomuto code is right." << endl;
}
int main()
{
    srand(time(0));
    QuickSortTest();
    QuickSortRandTest();
    QuickSortThreeTest();
    QuickSortKongXueTest();
    QuickSortHoareTest();
    QuickSortLomutoTest();
    return 0;
}