#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef void (*SortFunction)(vector<int> &);

void InsertSort(vector<int> &);
void BubbleSort(vector<int> &);
void MergeSort(vector<int> &);
void QuickSort(vector<int> &);
void ShellSort(vector<int> &);
void OptimizedQuickSort(vector<int> &);
void BlockQuickSort(vector<int> &);
void DualPivotQuickSort(vector<int> &);
void LogQuickSort(vector<int> &);
void Test(SortFunction sortFunc);

extern long int insertSortComparisons;
extern long int insertSortMoves;
extern long int bubbleSortComparisons;
extern long int bubbleSortMoves;
extern long int mergeSortComparisons;
extern long int mergeSortMoves;
extern long int quickSortComparisons;
extern long int quickSortMoves;
extern long int shellSortComparisons;
extern long int shellSortMoves;
extern long int optimizedQuickSortComparisons;
extern long int optimizedQuickSortMoves;
extern long int blockQuickSortBranchPredictions;
extern long int dualPivotQuickSortRecursionDepth;
extern long int currentRecursionDepth;
extern long int logQuickSortBranchPredictions;
extern long int logQuickSortRecursionDepth;
extern long int currentLogQuickSortDepth;
