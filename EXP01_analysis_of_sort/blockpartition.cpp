#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
/*
int BlockPartition(vector<int>& A, int low, int high) {
    int B = sqrt(A.size());  // 块大小
    vector<int> offsetsL(B), offsetsR(B);  // 缓冲区
    int startL = 0, startR = 0, numL = 0, numR = 0;
    int r = high, l = low;
    int pivot=A[low];
    // 主循环
    while (r - l + 1 > 2 * B) {
        // 填充左缓冲区
        if (numL == 0) {
            startL = 0;
            numL = 0;
            for (int i = 0; i < B; i++) {
                offsetsL[numL] = i;
                numL += (A[l + i] > pivot);  // 如果A[l + i] <= pivot则累加numL
            }
        }

        // 填充右缓冲区
        if (numR == 0) {
            startR = 0;
            numR = 0;
            for (int i = 0; i < B; i++) {
                offsetsR[numR] = i;
                numR += (A[r - i] < pivot);  // 如果A[r - i] >= pivot则累加numR
            }
        }

        // 比较并交换
        int num = min(numL, numR);
        for (int j = 0; j < num; j++) {
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
           
            if(A[j]>=pivot){
                j--;
            } 
            else{
                break;
            }
        }
        while(i<j){
           
            if(A[i]<=pivot) {
                i++;
            } 
            else{
                break;
            }
        }
        if(i<j){
           
            swap(A[j],A[i]);
        }
    }
    swap(A[low],A[j]);
    return j;
}

void QuickSort(vector<int>& A, int left,int right) {
	if (left >= right) {
		return;
	}
	int keyi = BlockPartition(A, left, right);
	QuickSort(A, left, keyi - 1);
	QuickSort(A, keyi + 1, right);


}

*/

void QuickSort(vector<int>& A, int low,int high) {
	if (low >= high) {
		return;
	}
    int B = sqrt(A.size());  // 块大小
    vector<int> offsetsL(B), offsetsR(B);  // 缓冲区
    int startL = 0, startR = 0, numL = 0, numR = 0;
    int r = high, l = low;
    int pivot=A[low];
    // 主循环
    while (r - l + 1 > 2 * B) {
        // 填充左缓冲区
        if (numL == 0) {
            startL = 0;
            numL = 0;
            for (int i = 0; i < B; i++) {
                offsetsL[numL] = i;
                numL += (A[l + i] > pivot);  // 如果A[l + i] <= pivot则累加numL
            }
        }

        // 填充右缓冲区
        if (numR == 0) {
            startR = 0;
            numR = 0;
            for (int i = 0; i < B; i++) {
                offsetsR[numR] = i;
                numR += (A[r - i] < pivot);  // 如果A[r - i] >= pivot则累加numR
            }
        }

        // 比较并交换
        int num = min(numL, numR);
        for (int j = 0; j < num; j++) {
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
           
            if(A[j]>=pivot){
                j--;
            } 
            else{
                break;
            }
        }
        while(i<j){
           
            if(A[i]<=pivot) {
                i++;
            } 
            else{
                break;
            }
        }
        if(i<j){
           
            swap(A[j],A[i]);
        }
    }
    swap(A[low],A[j]);
   
	int keyi = j;
	QuickSort(A, low, keyi - 1);
	QuickSort(A, keyi + 1, high);


}


int main() {
    // 测试BlockPartition函数
    vector<int> A = {29, 15, 27, 10, 34, 45, 12, 8, 23, 41};
    QuickSort(A, 0, A.size() - 1);

    // 输出分区结果
    cout << "After BlockPartition: ";
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
