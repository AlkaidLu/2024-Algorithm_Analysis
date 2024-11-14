#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

void InsertSort(vector<int> &, long long int &, long long int &);
void BubbleSort(vector<int> &, long long &, long long &);
void MergeSort(vector<int> &, long long &, long long &);
void QuickSort(vector<int> &, int, int, long long &, long long &, int mode = 0);
void ShellSort(vector<int> &, long long &, long long &);
void QuickSort_book(vector<int> &, int, int, long long &, long long &,int mode);
void QuickSort_Hoare(vector<int> &, int, int, long long &, long long &,int mode);