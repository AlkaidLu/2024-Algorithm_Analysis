#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

// Hoare 快速排序算法


void QuickSort_Hoare(vector<int>&A,int low,int high,long long &compare, long long &memaccess){
	if(low>=high) return;
    memaccess++;
    int temp=A[low];
    int i,j;
    i=low;
    j=high;
    while(i<j){
        while(i<j){
            memaccess++;
            compare++;
            if(A[j]>=temp){
                j--;
            } 
            else{
                break;
            }
        }
        while(i<j){
            memaccess++;
            compare++;
            if(A[i]<=temp) {
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
    swap(A[low],A[j]);
    int q=j;
    QuickSort_Hoare(A,low,q-1,compare,memaccess);
    QuickSort_Hoare(A,q+1,high,compare,memaccess);
}


 /*
void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

int HoareSort(int* arr, int left, int right) {
	int keyi = left;    //默认基准值key索引是在数组的首元素位置
 
	while (left < right) {
		//注：在外层while中，left与right是不断变化的，
        //必须保证里层的while中的每一次循环都要符合
		// left<right,因为left可能有与right相遇或者错过的情况，
        //不允许有这种情况发生，否则会出错！！！
	
		//right先走
		while (left < right && arr[right] >= arr[keyi]) {
			--right;
		}
		//走到right停下来了，left再走
		while (left < right && arr[left] <= arr[keyi]) {
			++left;
		}
 
		//这时，left与right都找到了比Key大的比key小的，跳出了循环，然后就开始互换元素
		if (left < right) {
			Swap(&arr[left], &arr[right]);
		}
		//互换完后再找，直到left>=right跳出大循环，
        //然后把left与right相遇点的位置与keyi互换即可
	}
 
    //此时left已经>=right了，即left和right位置重合了——相遇了
	int meeti = left;
    //将key索引和相遇位置索引的值进行交换，key就到了中间，此时key索引左边的子序列所有值永远
    //都比key索引处的值的小，key索引右边的子序列所有值也永远都比key索引处的值大
	Swap(&arr[meeti], &arr[keyi]);
	return meeti;
    //注意：该函数只是执行了一轮快排，还得继续定义剩下的key左序列和key右序列的基准值排列
}
 
void QuickSort(int* arr, int left,int right) {
	if (left >= right) {
		return;
	}
	int keyi = HoareSort(arr, left, right);
	//递归，通过确定keyi的最终位置，将整个数组从中间分开，
    //keyi左边的为一组,keyi右边的为另一组
	//左边一组继续通过HoareSort进行寻找，排序。。。
    //右边也是如此，最后形成完整的有序数组
	QuickSort(arr, left, keyi - 1);
	QuickSort(arr, keyi + 1, right);


}


void QuickSort_Book(vector<int>&A,int low,int high,long long &compare, long long &memaccess){
    if(low>=high) return;
    memaccess++;
    int temp=A[high];
    int i,j;
    i=low-1;
    for(j=low;j<high;j++){
        memaccess++;
        compare++;
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
*/
// 测试函数
void testQuickSort_Hoare() {
    // 创建一个随机数组
    int n = 20;  // 数组大小
    //int A[n];
    vector<int> A(n);
    srand(time(0));  // 设置随机种子
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 100;  // 生成 0 到 99 之间的随机数
    }

    // 输出原始数组
    cout << "Original array: ";
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;

    // 重置计数器
    long long compare = 0;
    long long memaccess = 0;

    // 排序数组
    QuickSort_Hoare(A, 0, 19,compare,memaccess);

    // 输出排序后的数组
    cout << "Sorted array: ";
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;

    // 输出比较和内存访问的次数
    cout << "Number of comparisons: " << compare << endl;
    cout << "Number of memory accesses: " << memaccess << endl;
}

int main() {
    testQuickSort_Hoare();
    return 0;
}
