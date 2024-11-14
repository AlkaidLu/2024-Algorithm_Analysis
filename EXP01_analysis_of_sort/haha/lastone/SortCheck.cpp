#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <string>
#include <cstring>
#include "Algorithm.h"


using namespace std;
long long CntCmp,CntSwp;

void Prt(vector<int>& nums)
{
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;
}

void InsertSortTest()
{
    vector<int> nums(100);
    for (int i = 0; i < 100; i++)
        nums[i] = 100 - i;
    InsertSort(nums,CntCmp,CntSwp);
    int flag = 0;
    for (int i = 0; i < 100; i++)
    {
        if (nums[i] != i+1)
            flag = 1;
    }
    if (flag)
    {
        cout << "The InsertSort code is incorrect." << endl;
        Prt(nums);
    }
    else
        cout << "The InsertSort code is right." << endl;
}

void BubbleSortTest()
{
    vector<int>nums(100);
    for (int i = 0; i < 100; i++)
        nums[i] = 100 - i;
    BubbleSort(nums,CntCmp,CntSwp);
    int flag = 0;
    for (int i = 0; i < 100; i++)
    {
        if (nums[i] != i+1)
            flag = 1;
    }
    if(flag)
    {
        cout << "The BubbleSort code is incorrect." << endl;
        Prt(nums);
    }
    else
    {
        cout << "The BubbleSort code is right." << endl;
    }
}

void QuickSortTest()
{
    vector<int>nums(100);
    for (int i = 0; i < 100; i++)
        nums[i] = 100 - i;
    QuickSort(nums,0,99,CntCmp,CntSwp);
    int flag = 0;
    for (int i = 0; i < 100; i++)
    {
        if (nums[i] != i+1)
            flag = 1;
    }
    if(flag)
    {
        cout << "The QuickSort code is incorrect." << endl;
        Prt(nums);
    }
    else
    {
        cout << "The QuickSort code is right." << endl;
    }
}

void MergeSortTest()
{
    vector<int>nums(100);
    for (int i = 0; i < 100; i++)
        nums[i] = 100 - i;
    MergeSort(nums,0,99,CntCmp,CntSwp);
    int flag = 0;
    for (int i = 0; i < 100; i++)
    {          
        if (nums[i] != i+1)
            flag = 1;
    }
    if(flag)
    {
        cout << "The MergeSort code is incorrect." << endl;
        Prt(nums);
    }
    else
    {
        cout << "The MergeSort code is right." << endl;
    }
}

void ShellSortTest()
{
    vector<int>nums(100);
    for (int i = 0; i < 100; i++)
        nums[i] = 100 - i;
    ShellSort(nums,CntCmp,CntSwp);
    int flag = 0;
    for (int i = 0; i < 100; i++)
    {
        if (nums[i] != i+1)
            flag = 1;
    }
    if(flag)
    {
        cout << "The ShellSort code is incorrect." << endl;
        Prt(nums);
    }
    else
    {
        cout << "The ShellSort code is right." << endl;
    }
}

int main()
{
    srand(time(0));
    InsertSortTest();
    BubbleSortTest();
    QuickSortTest();
    MergeSortTest();
    ShellSortTest();
    return 0;
}