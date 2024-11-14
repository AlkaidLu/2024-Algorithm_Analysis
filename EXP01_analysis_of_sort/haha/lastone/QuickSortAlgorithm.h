#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <string>
#include <cstring>
#include "QuickSortAlgorithm.cpp"

using namespace std;


int Partition(vector<int> &nums, int left, int right, long long &CntCmp, long long &CntSwp);
void QuickSort(vector<int> &nums, int left, int right, long long &CntCmp, long long &CntSwp);
int PartitionRand(vector<int> &nums, int left, int right, long long &CntCmp, long long &CntSwp);
void QuickSortRand(vector<int> &nums, int left, int right, long long &CntCmp, long long &CntSwp);
int PartitionThree(vector<int> &nums, int left, int right, long long &CntCmp, long long &CntSwp);
void QuickSortThree(vector<int> &nums, int left, int right, long long &CntCmp, long long &CntSwp);
void QuickSortKongXue(vector<int> &nums, int left, int right, long long &CntCmp, long long &CntSwp);
void QuickSortHoare(vector<int> &nums, int left, int right, long long &CntCmp, long long &CntSwp);
void QuickSortLomuto(vector<int> &nums, int left, int right, long long &CntCmp, long long &CntSwp);

