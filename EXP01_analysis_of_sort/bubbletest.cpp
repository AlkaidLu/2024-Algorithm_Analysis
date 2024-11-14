#include <iostream>
#include <vector>

using namespace std;

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

int main(){
    vector<int> vec={5610967, 5825849, 9500078, 5656570, 8829200, 3667302, 5696625, 7387651, 7544428, 8099800, 8530284, 5925926, 5413747};
    int compare = 0, memaccess = 0;

    BubbleSort(vec, compare, memaccess);

    cout << "Sorted array: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Number of comparisons: " << compare << endl;
    cout << "Number of memory accesses: " << memaccess << endl;
    return 0;
}