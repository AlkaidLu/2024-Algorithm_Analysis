#ifndef TEST_H
#define TEST_H

#include "sort.h"
#include<ctime>
#include <random>
#include <fstream>

#define DEBUG
using namespace std;
vector<int> getRandom(int low, int high, long long n);

// 排序测试函数模板声明
template <typename SortFunc>
void SortTest(const std::string& sortName, SortFunc sortFunc, int vector_size, int upbound, ofstream& results_file, ofstream& data_file);

// 各个排序算法的测试函数声明
void InsertSortTest(int vector_size, int upbound, ofstream& results_file, ofstream& data_file);
void SelectSortTest(int vector_size, int upbound, ofstream& results_file, ofstream& data_file);
void BubbleSortTest(int vector_size, int upbound, ofstream& results_file, ofstream& data_file);
void MergeSortTest(int vector_size, int upbound, ofstream& results_file, ofstream& data_file);
void ShellSortTest(int vector_size, int upbound, ofstream& results_file, ofstream& data_file);
void QuickSort_HoleTest(int vector_size, int upbound, ofstream& results_file, ofstream& data_file);
void QuickSort_HoareTest(int vector_size, int upbound, ofstream& results_file, ofstream& data_file);
void QuickSort_BookTest(int vector_size, int upbound, ofstream& results_file, ofstream& data_file);
void QuickSort_Hole_Better_SelectionTest(int vector_size, int upbound, ofstream& results_file, ofstream& data_file);
void BlockQuickSortTest(int vector_size, int upbound, std::ofstream& results_file, std::ofstream& data_file) ;
#endif