/*****************************************************************************
*  Copyright (C) 2022 Mingtian Shao  shaomt@nudt.edu.cn                      *
*                                                                            *
*  This file is part of homework of Algorithm Design and Analysis.           *
*                                                                            *
*  @file     main.cpp                                                        *
*  @brief    Test the performance of different algorithms                    *
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

#include <ctime>
#include <cstdlib>
#include <stack>
#include <string>
#include <cstring>
#include "algorithm.h"
#include "test.h"

using namespace std;

int main(int argc, char *argv[])
{
    //input: data_file
    if (argc != 2)
    {
        cout<< "参数错误，参数：数据集文件，如test_x_x_x.data" << endl;
        exit(1);
    }
    long double average_time_1, average_time_2;
    average_time_1 = test_5(argv[1], algorithm_1);
    //average_time_2 = test_5(argv[1], algorithm_2);
    cout << average_time_1 << endl;
    //cout << average_time_2 << endl;
    return 0;

    /**
     * 供参考：
     * 可能的输入：数据集文件、n（物品种类）、w（背包重量上限）
     * 1. 读取data_gen生成的测试集文件
     * 2. 使用不同算法对于测试集进行求解
     * 3. 记录算法性能并保存到文件
     * coding
     */
}
