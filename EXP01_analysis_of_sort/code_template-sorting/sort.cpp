#include "sort.h"

using namespace std;

void InsertSort(vector<int>&A){
    int i,j;
    int temp;
	int n=A.size();
    for(i=1;i<n;i++){
        j=i;
        temp=A[i];
        while(j>0&&temp<A[j-1]){
            A[j]=A[j-1];
            j--;
        }
        A[j]=temp;
    }
 }

void SelectSort(vector<int>&A){
	int i,j,k;
	int n=A.size();
    for(i=0;i<n-1;i++){
        k=i;
        for(j=i+1;j<n;j++){
            if(A[j]<A[k])
            k=j;
        }
        if(i!=k){
			swap(A[k],A[i]);
        }
    }
}

void BubbleSort(vector<int>&A){
	int i,j;
    bool flag;//to see if there is a swap in a circle
	int n=A.size();
    for(i=n-1,flag=1;i>0&&flag;i--){
        flag=false;
        for(j=0;j<i;j++){
            if(A[j+1]<A[j]){
                flag=true;
				swap(A[j],A[j+1]);
            }
        }
    }
}

// 合并两个有序子数组
void merge(vector<int>& A, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = A[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    // 复制剩余元素
    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

// 归并排序的递归函数
void MergeSort(vector<int>& A, int left, int right) {
    if (left < right) {
        int mid = (right + left) / 2;

        MergeSort(A, left, mid);
        MergeSort(A, mid + 1, right);

        merge(A, left, mid, right);
    }
}

void QuickSort(vector<int>&A,int low,int high){
	 if(low>=high) return;
    int i,j;
    i=low;
    j=high;
    int temp=A[i];
    while(i<j){
        while(i<j&&A[j]>temp) j--;
        if(i<j){A[i]=A[j];i++;}
        while(i<j&&A[i]<temp) i++;
        if(i<j){A[j]=A[i];j--;}
    }
    A[i]=temp;
    QuickSort(A,low,j-1);
    QuickSort(A,i+1,high);
}

void ShellSort(vector<int>&A,int s){
    int i,j,k;
    int temp;
	int n=A.size();
    for(k=s;k>0;k>>=1){
        for(i=k;i<n;i++){
            temp=A[i];
            j=i-k;
            while(j>=0&&temp<A[j]){
                A[j+k]=A[j];
                j-=k;
            }
            A[j+k]=temp;
        }
        
    }
}