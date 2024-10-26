/*****************************************************************************                                               *
*  Copyright (C) 2022 Mingtian Shao  shaomt@nudt.edu.cn                      *
*                                                                            *
*  This file is part of homework of Algorithm Design and Analysis.           *
*                                                                            *
*  @file     algorithm.cpp                                                   *
*  @brief    Implement different algorithms                                  *
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
#include <vector>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <string>
#include <cstring>
#include "algorithm.h"

using namespace std;

/**
 * @func algorithm_1
 * @brief 解决背包问题思路一
 * @param n: 物品种类
 * @param w: 背包容量限制
 * @param weights: 物品重量数组
 * @param values: 物品价值数组
 * @param solve: 保存解的数组
 *
 * @return 返回背包容纳的最大价值
 */

int algorithm_1(int n, int w, int* weights, int* values, int* solve)
{
    // memo index start from 0, which means type-1 or weight-1
    vector< vector<int> > memo(n);
    vector< vector<int> > nums(n);
    for (int i = 0; i < n; i++)
    {
        memo[i].resize(w);
        nums[i].resize(w);
    }
    // avoid the inefficient branch for i = 0 in the following ciculation
    for (int j = 0; j < w; j++) // avaliable weight capacity - 1
    {
        int k = (j + 1) / weights[0];
        memo[0][j] = k * values[0]; // take as many as possible
        nums[0][j] = k;
    }
    for (int i = 1; i < n; i++) // index of chosen object
    {
        for (int j = 0; j < w; j++) // avaliable weight capacity - 1
        {
            int maxvalue = 0, maxk = 0;
            for (int k = 0; k <= (j + 1) / weights[i]; k++)
            {
                int tmp = k * values[i];
                if (j - k * weights[i] >= 0)
                {
                    tmp += memo[i - 1][j - k * weights[i]];
                }
                if (tmp > maxvalue)
                {
                    maxvalue = tmp;
                    maxk = k;
                }
            }
            memo[i][j] = maxvalue;
            nums[i][j] = maxk;
        }
    }
    int tmpw = w - 1;
    for (int i = n - 1; i >= 0; i--)
    {
        solve[i] = nums[i][tmpw];
        tmpw -= solve[i] * weights[i];
    }
    return memo[n - 1][w - 1];
}


/**
 * @func 函数名
 * @brief 函数简要说明
 * @param 参数1
 * @param 参数2
 *
 * @return 返回说明
 */
int algorithm_2(int n, int w, int* weights, int* values, int* solve)
{
    /*
     * coding
     */
}

/**
 * @func algorithm_1_analy
 * @brief 在函数algorithm_1的基础上进行插桩，记录关键操作次数
 * @param n: 物品种类
 * @param w: 背包容量限制
 * @param weights: 物品重量数组
 * @param values: 物品价值数组
 * @param solve: 保存解的数组
 * @param calc_count: 记录计算次数
 * @param search_count: 记录查找次数
 *
 * @return 返回背白容纳的最大价值
 */
int algorithm_1_analy(int n, int w, int* weights, int* values, int* solve, int& calc_count, int& search_count)
{
    /*
     * coding
     */
}

/**
 * @func 函数名
 * @brief 函数简要说明
 * @param 参数1
 * @param 参数2
 *
 * @return 返回说明
 */
int algorithm_2_analy(int n, int w, int* weights, int* values, int* solve, int& calc_count, int& search_count)
{
    /*
     * coding
     */
}