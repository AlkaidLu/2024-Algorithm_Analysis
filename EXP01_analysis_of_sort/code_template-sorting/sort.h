#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <string>
#include <cstring>
#include<cmath>
using namespace std;

void InsertSort(vector<int>&A,long long &compare, long long &memaccess);
void SelectSort(vector<int>&A,long long &compare, long long &memaccess);
void BubbleSort(vector<int>&A,long long &compare, long long &memaccess);
void merge(vector<int>& A, int left, int mid, int right,long long &compare,long long &memaccess);
void MergeSort(vector<int>& A, int left, int right,long long &compare, long long &memaccess);
void ShellSort(vector<int>&A,int s,long long &compare, long long&memaccess);
void QuickSort_Hole(vector<int>&A,int low,int high,long long &compare, long long &memaccess);
void QuickSort_Hoare(vector<int>&A,int low,int high,long long &compare, long long &memaccess);
void QuickSort_Book(vector<int>&A,int low,int high,long long &compare, long long &memaccess);
void QuickSort_Hole_Better_Selection(vector<int>&A,int low,int high,long long &compare, long long &memaccess);
void BlockQuickSort(vector<int>&A,int low,int high,long long &compare, long long &memaccess);
