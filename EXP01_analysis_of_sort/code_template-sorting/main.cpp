#include "sort.h"
#include "out.h"
#include<random>
#include<ctime>
using namespace std;


vector<int> getRandom(int low, int high ,int n) {
    vector<int> vec;

    if (n <= 1) {
        printf("Error! vector shouldn't be less than 2.");
        exit(0);
    }

    random_device seed; // 硬件生成随机数种子
    ranlux48 gen(seed()); // 利用种子生成随机数引擎
    uniform_real_distribution<> dis(low, high); // 设置的范围


    while (vec.size() < static_cast<size_t>(n)) {
        int p= dis(gen);
        vec.push_back(p);     // 添加到结果向量中
        }
    

    return vec;
}

int cycle(int vector_size, int upbound)
{
    double sum_time = 0;
    
    int num_repeat = 100;
    for (int i = 0; i < num_repeat; i++)
    {
        vector<int> vec=getRandom(vector_size,123456,1);

        clock_t start_time, end_time;
        start_time = clock();
        //InsertSort(vec);
        end_time = clock();
        sum_time += (double)(end_time - start_time) / CLOCKS_PER_SEC;

    }
    cout << "The average time is " << sum_time / num_repeat << " s." << endl;
    return 0;
}
int main(){
    int vector_size[5] = {10,100,1000,10000,100000};


    return 0;
}
