#include "sort.h"
#include "out.h"

using namespace std;

void InsertSortTest()
{
    clock_t start_time, end_time;
    start_time = clock();
    InsertSort(vec);
    end_time = clock();
    sum_time += (double)(end_time - start_time) / CLOCKS_PER_SEC;

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

void SelectSortTest(){


}
void BubbleSort(vector<int>&A);
void merge(vector<int>& A, int left, int mid, int right);
void MergeSort(vector<int>& A, int left, int right);
void QuickSort(vector<int>&A);
void ShellSort(vector<int>&A);
