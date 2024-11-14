#include "sort.h"
#include "test.h"
#include<random>

using namespace std;

#define NUM 5




int main(){
    int vector_size[NUM] = {100,1000,5000,10000,100000};
    ofstream results_file("sorting_results.txt");
    ofstream data_file("sorting_data.txt");
    for(int i=0;i<NUM;i++){
        int vecsize=vector_size[i];
        int upbound=1000000;
        data_file << "vector_size: " << vecsize << endl;
        printf("Round %d\n",i+1);
        InsertSortTest(vecsize, upbound, results_file, data_file);
        printf("OK\n");
        SelectSortTest(vecsize, upbound, results_file, data_file);
        printf("OK\n");
        BubbleSortTest(vecsize, upbound, results_file, data_file); 
        printf("OK\n");
        MergeSortTest(vecsize, upbound, results_file, data_file);
        printf("OK\n");
        ShellSortTest(vecsize, upbound, results_file, data_file);
        printf("OK\n");
        QuickSort_HoleTest(vecsize, upbound, results_file, data_file);
        printf("OK\n");
        QuickSort_HoareTest(vecsize, upbound, results_file, data_file);
        printf("OK\n");
        QuickSort_BookTest(vecsize, upbound, results_file, data_file);
        printf("OK\n");
        QuickSort_Hole_Better_SelectionTest(vecsize, upbound,results_file, data_file);
        printf("OK\n");
        BlockQuickSortTest(vecsize, upbound,results_file, data_file);
        printf("OK\n");
    }

    results_file.close();
    data_file.close();

    return 0;
}
