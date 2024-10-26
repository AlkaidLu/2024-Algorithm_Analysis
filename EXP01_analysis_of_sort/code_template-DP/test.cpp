/*****************************************************************************
*  Copyright (C) 2022 Mingtian Shao  shaomt@nudt.edu.cn                      *
*                                                                            *
*  This file is part of homework of Algorithm Design and Analysis.           *
*                                                                            *
*  @file     algorithm.cpp                                                   *
*  @brief    test different algorithms                                       *
*                                                                            *
*  @author   Mingtian Shao                                                   *
*  @email    shaomt@nudt.edu.cn                                              *
*  @version  1.0                                                             *
*  @date     2022-11-12                                                      *
*  @license  GNU General Public License (GPL)                                *
*                                                                            *
*----------------------------------------------------------------------------*
*  Change History :                                                          *
*  <Date>     | <Version> | <Author>       | <Description>                   *
*----------------------------------------------------------------------------*
*  2022/11/12 | 1.0       | Mingtian Shao  | Create file                     *
*----------------------------------------------------------------------------*
*                                                                            *
*****************************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <string>
#include <cstring>
#include <fstream>
#include "algorithm.h"
#include "test.h"

using namespace std;

/**
 * @func PrintArray
 * @brief 输出指针数组
 * @param n: 数组长度
 * @param nums: 整型指针数组
 *
 * @return null
 */
void PrintArray(int n, int* nums)
{
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

/**
 * @func test_5
 * @brief 测试算法运行时间并输出每组测试用例的结果
 * @param data_file: 测试数据集文件
 * @param fun: 测试算法的实现函数，该函数有5个参数，故该测试函数名为test_5
 *
 * @return 算法的平均运行时间
 */
long double test_5(char* data_file, int (fun)(int, int, int*, int*, int*))
{
    double sum_time = 0;
    clock_t start_time, end_time;

    ifstream fin(data_file);

    int result; //保存每个测试用例的最大价值
    int repeat; //记录测试数据组数
    // k: 生成数据的组数
    // n: 物品的种类（问题的规模）
    // w: 背包重量限制
    int k, n, w;
    fin >> k >> n >> w;
    repeat = k;
    cout << "数据集组数：" << k << " , 物品种类：" << n << " , 背包容量限制： " << w << endl;
    int* weights = new int[n], * values = new int[n];
    int* solve = new int[n];
    while (k--) {
        for (int i = 0; i < n; i++) {
            fin >> weights[i];
        }
        for (int i = 0; i < n; i++) {
            fin >> values[i];
            solve[i] = 0;
        }

        cout << "weights:" << endl;
        PrintArray(n, weights);
        cout << "values:" << endl;
        PrintArray(n, values);

        // 仅记录算法运行时间
        start_time = clock();
        result = fun(n, w, weights, values, solve);
        end_time = clock();

        sum_time += (double)(end_time - start_time) / CLOCKS_PER_SEC;
        cout << "max value is " << result << endl;
        cout << "the solution is "; PrintArray(n, solve);
    }
    delete[] weights;
    delete[] values;
    delete[] solve;
    long double average_time = sum_time / repeat;
    return average_time;
}

/**
 * @func test_7
 * @brief 主要用于记录算法fun的关键操作次数
 * @param data_file: 测试数据集文件
 * @param fun: 测试算法的实现函数，该函数有7个参数，故该测试函数名为test_7
 *
 * @return 算法的平均运行时间，该值仅供参考，因为插桩代码影响了算法运行效率
 */
long double test_7(char* data_file, int (fun)(int, int, int*, int*, int*, int&, int&))
{
    /*
     * coding
     */
}