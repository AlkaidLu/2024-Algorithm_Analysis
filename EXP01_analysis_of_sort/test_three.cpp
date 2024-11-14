#include<stdio.h>
#include<vector>
#define NUM 2
using namespace std;
int main(){
    vector<int> A={3,2,1};
    int low=0;
    int high=2;
    int mid=1;
    
    if(A[high]<A[low]){
        swap(A[high],A[low]);
    }
    if(A[mid]>A[low]){
        swap(A[mid],A[low]);
    }
    if(A[high]<A[low]){
        swap(A[high],A[low]);
    }
    for(int i=0;i<3;i++){
        printf("%d\t",A[i]);
    }
    printf("\n");
    return 0;
}