#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <cmath>

using namespace std;

// BlockQuickSort 的实现（略去详细实现，假设你已经有了这个函数）

void BlockQuickSort(vector<int>&A,int low,int high,long long &compare, long long &memaccess, int B){
	if (low >= high) {
		return;
	}
    vector<int> offsetsL(B), offsetsR(B);  // 缓冲区
    int startL = 0, startR = 0, numL = 0, numR = 0;
    int r = high, l = low;
    memaccess++;
    int pivot=A[low];
    // 主循环
    while (r - l + 1 > 2 * B) {
        // 填充左缓冲区
        if (numL == 0) {
            startL = 0;
            numL = 0;
            for (int i = 0; i < B; i++) {
                memaccess+=2;
                offsetsL[numL] = i;
                compare++;
                numL += (A[l + i] > pivot);  // 如果A[l + i] <= pivot则累加numL
            }
        }

        // 填充右缓冲区
        if (numR == 0) {
            startR = 0;
            numR = 0;
            for (int i = 0; i < B; i++) {
                memaccess+=2;
                offsetsR[numR] = i;
                compare++;
                numR += (A[r - i] < pivot);  // 如果A[r - i] >= pivot则累加numR
            }
        }

        // 比较并交换
        int num = min(numL, numR);
        for (int j = 0; j < num; j++) {
            memaccess+=4;
            swap(A[l + offsetsL[startL + j]], A[r - offsetsR[startR + j]]);
        }

        // 更新计数器和指针
        numL -= num;
        numR -= num;
        startL += num;
        startR += num;

        if (numL == 0) {
            l += B;
        }
        if (numR == 0) {
            r -= B;
        }
    }

    // 比较和重新排列剩余的元素
    int i = l, j = r;
    
    while(i<j){
        while(i<j){
           memaccess++;
           compare++;
            if(A[j]>=pivot){
                j--;
            } 
            else{
                break;
            }
        }
        while(i<j){
           memaccess++;
           compare++;
            if(A[i]<=pivot) {
                i++;
            } 
            else{
                break;
            }
        }
        if(i<j){
            memaccess+=2;
            swap(A[j],A[i]);
        }
    }
    memaccess+=2;
    swap(A[low],A[j]);
   
	int keyi = j;
	BlockQuickSort(A, low, keyi - 1,compare,memaccess,B);
	BlockQuickSort(A, keyi + 1, high,compare,memaccess,B);
}
// 测试不同块大小的运行时间
void test_block_size_performance(int num_trials, const vector<int>& block_sizes, int array_size) {
    // 生成随机数
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100000);  // 随机数范围

    for (int block_size : block_sizes) {
        // 记录平均运行时间
        double total_time = 0.0;

        for (int trial = 0; trial < num_trials; ++trial) {
            // 生成随机数组
            vector<int> A(array_size);
            for (int i = 0; i < array_size; ++i) {
                A[i] = dis(gen);
            }

            long long compare = 0, memaccess = 0;

            // 计时开始
            auto start = chrono::high_resolution_clock::now();
            BlockQuickSort(A, 0, array_size - 1, compare, memaccess,block_size);
            // 计时结束
            auto end = chrono::high_resolution_clock::now();

            // 计算运行时间
            chrono::duration<double> duration = end - start;
            total_time += duration.count(); // 累加时间
        }

        // 计算平均运行时间
        double average_time = total_time / num_trials;
        cout << "Block Size: " << block_size << ", Average Time: " << average_time << " seconds" << endl;
    }
}

int main() {
    int num_trials = 10; // 测试次数
    
    int array_size = 100000; // 数组大小
    vector<int> block_sizes = { int(sqrt(sqrt(sqrt(array_size)))),int(sqrt(sqrt(array_size))) , int(sqrt(array_size))>>1, int(sqrt(array_size)),2*int(sqrt(array_size))}; // 不同的块大小
    test_block_size_performance(num_trials, block_sizes, array_size);

    return 0;
}
