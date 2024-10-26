/*****************************************************************************
*  Copyright (C) 2022 Mingtian Shao  shaomt@nudt.edu.cn                      *
*                                                                            *
*  This file is part of homework of Algorithm Design and Analysis.           *
*                                                                            *
*  @file     analyser.cpp                                                    *
*  @brief    Analyze the number of critical operations                       *
*            for different algorithms                                        *
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
#include <fstream>
#include <random>
#include <cmath>
#include "algorithm.h"
#include "test.h"

using namespace std;

/**
 * @func analy_fun
 * @brief 插桩算法测试
 * @param data_file: 测试集文件
 * @param cntcalc: 计算计数器
 * @param cntsearch: 查找计数器
 * @param fun: 测试的算法函数
 *
 * @return 重复测试的次数（测试数据的组数）
 */
int analy_fun(char *data_file, int &cntcalc, int &cntsearch, int (fun)(int, int, int*, int*, int*, int&, int&))
{
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

        result = fun(n, w, weights, values, solve, cntcalc, cntsearch);

    }

    delete[] weights;
    delete[] values;
    delete[] solve;

    return repeat;
}

int main(int argc, char *argv[])
{
    //input: data_file
    if (argc != 2)
    {
        cout<< "参数错误，参数：数据集文件，如test_x_x_x.data" << endl;
        exit(1);
    }
    int cntcalc = 0;
    int cntsearch = 0;
    int repeat;
    repeat = analy_fun(argv[1], cntcalc, cntsearch, algorithm_1_analy);
    int average_calc = cntcalc / repeat;
    int average_search = cntsearch / repeat;
    cout << "average_calc: " << average_calc << endl;
    cout <<  "average_search: " << average_search << endl;

    return 0;
}