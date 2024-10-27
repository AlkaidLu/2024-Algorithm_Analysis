#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

void InsertSort(vector<int>&A,int &compare, int &move);
void SelectSort(vector<int>&A,int &compare, int &move);
void BubbleSort(vector<int>&A,int &compare, int &move);
void merge(vector<int>& A, int left, int mid, int right);
void MergeSort(vector<int>& A, int left, int right,int &compare, int &move);
void QuickSort(vector<int>&A,int &compare, int &move);
void ShellSort(vector<int>&A,int &compare, int &move);

