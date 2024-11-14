#include <iostream>
#include <vector>

using namespace std;

void ShellSort(vector<int>&A,int s){
    int i,j,k;
    int temp;
	int n=A.size();
    for(k=s;k>0;k>>=1){
        for(i=k;i<n;i++){
           
            temp=A[i];
            j=i-k;
            while(j>=0){
               
                if(temp<A[j]){
                  
                    A[j+k]=A[j];
                    j-=k;
                }
                else{
                    break;
                }
            }
          
            A[j+k]=temp;
        }
        
    }
}
int main(){
    vector<int> vec={34, 7, 23, 32, 5, 62, 1, 14, 8, 50};
    int compare = 0, memaccess = 0;
    int s = 5; // ShellSort 的间隔序列

    ShellSort(vec, s);

    cout << "Sorted array: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Number of comparisons: " << compare << endl;
    cout << "Number of memory accesses: " << memaccess << endl;
    return 0;
}