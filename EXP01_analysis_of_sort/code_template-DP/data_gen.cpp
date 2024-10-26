/*****************************************************************************
*  Copyright (C) 2022 Mingtian Shao  shaomt@nudt.edu.cn                      *
*                                                                            *
*  This file is part of homework of Algorithm Design and Analysis.           *
*                                                                            *
*  @file     data_gen.cpp                                                    *
*  @brief    Generate data and save it to a file                             *
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
#include<ctime>

using namespace std;

/**
 * @func data_gen
 * @brief 生成测试数据集
 * @param k: 测试集数量
 * @param n: 物品种类
 * @param w: 背包重量限制
 *
 * @return null
 */
void data_gen(int k, int n, int w)
{
    char out_file[100];
    //输出文件名可参考"test_{k}_{n}_{w}.data"
    sprintf(out_file, "test_%d_%d_%d.data", k, n, w);
    ofstream fout(out_file);
    fout << k << " " << n << " " << w << endl;
    default_random_engine e(time(nullptr));
    //随机数分布对象
    uniform_int_distribution<signed> u(2, w / 1.5);
    while (k--)
    {
        // 生成weight值
        for (int i = 0; i < n; i++) //生成2~n的随机数序列
            fout << u(e) << " ";
        fout << endl;
        // 生成value值
        for (int i = 0; i < n; i++) //生成2~n的随机数序列
            fout << u(e) << " ";
        fout << endl;
    }
}

int main(int argc, char *argv[])
{
    // k: 生成数据的组数
    // n: 物品的种类（问题的规模）
    // w: 背包重量限制
    if(argc != 4 )
    {
        cout << "参数错误，参数包括: 生成数据的组数k, 物品的种类n, 背包重量限制w" << endl;
        exit(1);
    }

    int k, n, w;
    k = atoi(argv[1]);
    n = atoi(argv[2]);
    w = atoi(argv[3]);
    data_gen(k,n,w);

    return 0;
}
