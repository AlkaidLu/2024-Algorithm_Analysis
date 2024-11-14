#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include<cmath>
using namespace std;


// 比较和内存访问计数器的初始值
long long compare = 0;
long long memaccess = 0;
void BlockQuickSort(vector<int>&A,int low,int high,long long &compare, long long &memaccess){
    if(low>=high) return;
    int pivot=A[low];
    int B=sqrt(A.size());
    int offsetsL[B],offsetsR[B];
    int startL=0,startR=0,numL=0,numR=0;
    int r=high,l=low;
    while(r-l+1>2*B){
        if(numL == 0){
            startL=0;
            for(int i=0;i<B;i++){
                offsetsL[numL]=i;
                numL+=(pivot<=A[l+i]);
            }
        }
        if(numR == 0){
            startR=0;
            for(int i=0;i<B;i++){
                offsetsR[numR]=i;
                numR+=(pivot<=A[r-i]);
            }
        }
        int num=min(numL,numR);
        for(int j=0;j<num;j++){
            swap(A[l+offsetsL[startL+j]],A[r-offsetsR[startR+j]]);
        }
        numL-=num;
        numR-=num;
        startL+=num;
        startR+=num;
        if(numL==0){
            l+=B;
        }
        if(numR==0){
            r-=B;
        }
    }

    //比较并且重新定位剩下的元素
    int i = l, j = r;   
    while (i <= j) {
        while (i < high && A[i] < pivot) {
            i++;
            compare++;
        }
        while (j > low && A[j] > pivot) {
            j--;
            compare++;
        }
        if (i < j) {
            swap(A[i], A[j]);
            memaccess += 2; // 访问三个元素（两个被交换的元素和一个索引）
            i++;
            j--;
        }
    }
    A[j]=pivot;
    int q = j;
  
    BlockQuickSort(A,low,q-1,compare,memaccess);
    BlockQuickSort(A,q+1,high,compare,memaccess);
}

// 测试函数
void testBlockQuickSort() {
    // 创建一个随机数组
    int n = 20; // 你可以改变数组的大小
    std::vector<int> A(n);
    std::srand(std::time(0)); // 设置随机种子
    for (int i = 0; i < n; i++) {
        A[i] = std::rand() % 100; // 生成0到99之间的随机数
    }

    // 输出原始数组
    std::cout << "Original array: ";
    for (int num : A) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 重置计数器
    compare = 0;
    memaccess = 0;

    // 排序数组
    BlockQuickSort(A, 0, A.size() - 1,compare,memaccess);

    // 输出排序后的数组
    std::cout << "Sorted array: ";
    for (int num : A) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 输出比较和内存访问的次数
    std::cout << "Number of comparisons: " << compare << std::endl;
    std::cout << "Number of memory accesses: " << memaccess << std::endl;
}

int main() {
    testBlockQuickSort();
    return 0;
}