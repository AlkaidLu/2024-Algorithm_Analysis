#include "sort.h"

using namespace std;

void InsertSort(vector<int>&A,int &compare, int &memaccess){
    int i,j;
    int temp;
	int n=A.size();
    for(i=1;i<n;i++){
        j=i;
        memaccess++;
        temp=A[i];
         while (j > 0) {
            compare++; // 在每次进入 while 循环体时增加比较计数
            memaccess++; // 记录访存次数
            if (temp < A[j - 1]) {
                memaccess+=2; // 记录访存次数
                A[j] = A[j - 1];
                j--;
            } else {
                break; // 一旦不满足条件，跳出循环
            }
        }
        memaccess++;
        A[j]=temp;
    }
 }

void SelectSort(vector<int>&A,int &compare, int &memaccess){
	int i,j,k;
	int n=A.size();
    for(i=0;i<n-1;i++){
        k=i;
        for(j=i+1;j<n;j++){
            compare++; // 每次比较 A[j] 和 A[k] 进行计数
            memaccess+=2;
            if(A[j]<A[k]){
                k=j;
            }
        }
        if(i!=k){
            memaccess+=2;// 记录交换次数
			swap(A[k],A[i]);
        }
    }
}

void BubbleSort(vector<int>&A,int &compare, int &memaccess){
	int i,j;
    bool flag;//to see if there is a swap in a circle
	int n=A.size();
    for(i=n-1,flag=1;i>0&&flag;i--){
        flag=false;
        for(j=0;j<i;j++){
            compare++;// 记录比较次数
            memaccess+=2;
            if(A[j+1]<A[j]){
                flag=true;
                memaccess+=2;// 记录交换次数
				swap(A[j],A[j+1]);
            }
        }
    }
}

// 合并两个有序子数组
void merge(vector<int>& A, int left, int mid, int right,int &compare, int &memaccess) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++){
        memaccess+=2;
        L[i] = A[left + i];
    }
    for (int j = 0; j < n2; j++){
        memaccess+=2;
        R[j] = A[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        compare++;
        memaccess+=2;
        if (L[i] <= R[j]) {
            memaccess+=2;
            A[k] = L[i];
            i++;
        } else {
            memaccess+=2;
            A[k] = R[j];
            j++;
        }
        k++;
    }

    // 复制剩余元素
    while (i < n1) {
        memaccess+=2;
        A[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        memaccess+=2;
        A[k] = R[j];
        j++;
        k++;
    }
}

// 归并排序的递归函数
void MergeSort(vector<int>& A, int left, int right,int &compare, int &memaccess) {
    if (left < right) {
        int mid = (right + left) / 2;

        MergeSort(A, left, mid, compare, memaccess);
        MergeSort(A, mid + 1, right, compare, memaccess);

        merge(A, left, mid, right, compare, memaccess);
    }
}

void ShellSort(vector<int>&A,int s,int &compare, int &memaccess){
    int i,j,k;
    int temp;
	int n=A.size();
    for(k=s;k>0;k>>=1){
        for(i=k;i<n;i++){
            memaccess++;
            temp=A[i];
            j=i-k;
            while(j>=0){
                compare++;
                if(temp<A[j]){
                    memaccess+=2;
                    A[j+k]=A[j];
                    j-=k;
                }
            }
            memaccess++;
            A[j+k]=temp;
        }
        
    }
}


void QuickSort_Hole(vector<int>&A,int low,int high,int &compare, int &memaccess){
	if(low>=high) return;
    memaccess++;
    int temp=A[low];
    int i,j;
    i=low;
    j=high;
    while(i<j){
        while(i<j){
            compare++;
            memaccess++;
            if(A[j]>temp){
                j--;
            }
        } 
        if(i<j){
            memaccess+=2;
            A[i]=A[j];
            i++;
            }
        while(i<j){
            compare++;
            memaccess++;
            if(A[i]<temp) {
                i++;
            } 
        }
        if(i<j){
            memaccess+=2;
            A[j]=A[i];
            j--;
            }
    }
    memaccess++;
    A[i]=temp;
    QuickSort_Hole(A,low,j-1,compare,memaccess);
    QuickSort_Hole(A,i+1,high,compare,memaccess);
}

void QuickSort_Hoare(vector<int>&A,int low,int high,int &compare, int &memaccess){
	if(low>=high) return;
    memaccess++;
    int temp=A[low];
    int i,j;
    i=low;
    j=high+1;
    while(i<j){
        while(i<j){
            memaccess++;
            if(A[j]<temp){
                compare++;
                j--;
            } 
        }
        while(i<j){
            memaccess++;
            if(A[i]>temp) {
                compare++;
                i++;
            } 
        }
        if(i<j){
            memaccess+=2;
            swap(A[j],A[i]);
            i++;
            j--;
        }
    }
    int q=j;
    QuickSort_Hoare(A,low,q-1,compare,memaccess);
    QuickSort_Hoare(A,q+1,high,compare,memaccess);
}

void QuickSort_Book(vector<int>&A,int low,int high,int &compare, int &memaccess){
    if(low>=high) return;
    memaccess++;
    int temp=A[high];
    int i,j;
    i=low-1;
    for(j=low;j<high;j++){
        memaccess++;
        if(A[j]<=temp){
            i++;
            memaccess+=2;
            swap(A[i],A[j]);
        }
    }
    memaccess+=2;
    swap(A[i+1],A[high]);
    int q=i+1;
    QuickSort_Book(A,low,q-1,compare,memaccess);
    QuickSort_Book(A,q+1,high,compare,memaccess);
}

void BlockQuickSort(){

}

void DualPivotQuickSort(){

}