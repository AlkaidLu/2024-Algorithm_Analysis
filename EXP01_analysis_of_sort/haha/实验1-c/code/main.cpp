#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <random>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <string>
#include <cstring>
#include "algorithm.h"
#include "out.h"
using namespace std;

#define UP_BOUND 123456

void analy_fun(int num, void fun(vector<int> &nums, long long &, long long &))
{

    int size_list[15] = {1000,2000,3000,4000,5000,6000,7000,8000,9000,10000};
    int vector_size;
    int num_repeat = 20;
    double sum_time = 0;
    for (int i = 0; i < num; i++)
    {
        long long cntcmp = 0, cntmov = 0;
        vector_size = size_list[i];
        string filename = "../data/data_" + to_string(vector_size) + ".txt";
        const char *p = filename.data();
        ifstream fin(p);
        vector<int> vec(vector_size);
        for (int j = 0; j < num_repeat; j++)
        {
            for (int k = 0; k < vector_size; k++)
                fin >> vec[k];

            clock_t start_time, end_time;
            start_time = clock();
            fun(vec, cntcmp, cntmov);
            end_time = clock();
            sum_time += (double)(end_time - start_time) / CLOCKS_PER_SEC;
            // Out(vev);
        }
        cout << "--------size = " << vector_size << "--------" << endl;
        cout << "The average time is " << sum_time / num_repeat << " s." << endl;
        cout << "The average cntcmp is " << cntcmp / num_repeat << endl;
        cout << "The average cntmov is " << cntmov / num_repeat << endl;
    }
    return;
}

void analy_fun11(int num, int mode, void fun(vector<int> &nums, int low, int high, long long &, long long &, int))
{

    int size_list[15] = {1000, 2000,3000,4000,5000,6000,7000,8000,9000,10000};
    int vector_size;
    int num_repeat = 20;
    double sum_time = 0;
    for (int i = 0; i < num; i++)
    {
        long long cntcmp = 0, cntmov = 0;
        vector_size = size_list[i];
        string filename = "../data/data_" + to_string(vector_size) + ".txt";
        const char *p = filename.data();
        ifstream fin(p);
        vector<int> vec(vector_size);
        for (int j = 0; j < num_repeat; j++)
        {
            for (int k = 0; k < vector_size; k++)
                fin >> vec[k];

            clock_t start_time, end_time;
            start_time = clock();
            fun(vec, 0, vector_size - 1, cntcmp, cntmov, mode);
            end_time = clock();
            if (vector_size == 1000)
                Out(vec);
            sum_time += (double)(end_time - start_time) / CLOCKS_PER_SEC;
        }
        cout << "--------size = " << vector_size << "--------" << endl;
        cout << "The average time is " << sum_time / num_repeat << " s." << endl;
        cout << "The average cntcmp is " << cntcmp / num_repeat << endl;
        cout << "The average cntmov is " << cntmov / num_repeat << endl;
    }
    return;
}

int main(int argc, char *argv[])
{

    int key = atoi(argv[1]);
    int num = atoi(argv[2]);
    int mode = atoi(argv[3]);
    if (key == 1)
        analy_fun(num, InsertSort);
    else if (key == 2)
        analy_fun(num, BubbleSort);
    else if (key == 3)
        analy_fun(num, ShellSort);
    else if (key == 4)
        analy_fun(num, MergeSort);
    else if (key == 0)
        analy_fun11(num, mode, QuickSort);
    else if (key == 6)
        analy_fun11(num, 0, QuickSort_book);
    else if (key == 7)
        analy_fun11(num, 0, QuickSort_Hoare);
    else
        cout << "参数错误" << endl;

    return 0;
}
