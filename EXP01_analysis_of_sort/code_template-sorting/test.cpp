#include"test.h"

//生成随机数组
vector<int> getRandom(int low, int high ,int n) {
    vector<int> vec;

    if (n <= 1) {
        printf("Error! vector shouldn't be less than 2.");
        exit(0);
    }

    random_device seed; // 硬件生成随机数种子
    ranlux48 gen(seed()); // 利用种子生成随机数引擎
    uniform_real_distribution<> dis(low, high); // 设置的范围


    while (vec.size() < static_cast<size_t>(n)) {
        int p= dis(gen);
        vec.push_back(p);     // 添加到结果向量中
        }
    

    return vec;
}
// 测试函数模板
template <typename SortFunc>
void SortTest(const string& sortName, SortFunc sortFunc, int vector_size, int upbound, ofstream& results_file, ofstream& data_file) {
    double sum_time = 0;
    long long compare = 0, memaccess = 0;
    int num_repeat = 20;

    for (int i = 0; i < num_repeat; i++) {
        vector<int> vec = getRandom(1, upbound, static_cast<int>(vector_size));
        long long local_compare = 0, local_memaccess = 0;
        clock_t start_time, end_time;

        #ifdef DEBUG
         // 写入排序前的数组到结果文件(只是测试正确性)
        if(vector_size<=100){
        results_file << "Before sorting (" << sortName << "): ";
        for (int num : vec) {
            results_file << num << " ";
        }
        results_file << endl;
        }
        #endif
        
        start_time = clock();
        sortFunc(vec, local_compare, local_memaccess);
        end_time = clock();

        double duration = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        sum_time += duration;
        compare += local_compare;
        memaccess += local_memaccess;
        #ifdef DEBUG
        // 写入排序后的数组到结果文件，(只是测试正确性)
        if(vector_size<=100){
        results_file << "After sorting (" << sortName << "): ";
        for (int num : vec) {
            results_file << num << " ";
        }
        results_file << endl << endl;
        }
        #endif
        
    }

    // 写入关键数据到数据文件
    data_file << "Sort Name: " << sortName << endl;
    data_file << "Average Compares: " << compare / num_repeat << endl;
    data_file << "Average Memory Accesses: " << memaccess / num_repeat << endl;
    data_file << "Average Time: " << sum_time / num_repeat << " seconds" << endl << endl;
}

// 排序测试函数
void InsertSortTest(int vector_size, int upbound, ofstream& results_file, ofstream& data_file) {
    SortTest("InsertSort", [](vector<int>& A, long long &compare, long long &memaccess) {
        InsertSort(A, compare, memaccess);
    }, vector_size, upbound, results_file, data_file);
}

void SelectSortTest(int vector_size, int upbound, ofstream& results_file, ofstream& data_file) {
    SortTest("SelectSort", [](vector<int>& A, long long &compare, long long &memaccess) {
        SelectSort(A, compare, memaccess);
    }, vector_size, upbound, results_file, data_file);
}

void BubbleSortTest(int vector_size, int upbound, ofstream& results_file, ofstream& data_file) {
    SortTest("BubbleSort", [](vector<int>& A, long long &compare, long long &memaccess) {
        BubbleSort(A, compare, memaccess);
    }, vector_size, upbound, results_file, data_file);
}

void MergeSortTest(int vector_size, int upbound, ofstream& results_file, ofstream& data_file) {
    SortTest("MergeSort", [](vector<int>& A, long long &compare, long long &memaccess) {
        MergeSort(A, 0, A.size() - 1, compare, memaccess);
    }, vector_size, upbound, results_file, data_file);
}

void ShellSortTest(int vector_size, int upbound, ofstream& results_file, ofstream& data_file) {
    SortTest("ShellSort", [](vector<int>& A, long long &compare, long long &memaccess) {
        ShellSort(A, A.size()/2, compare, memaccess);
    }, vector_size, upbound, results_file, data_file);
}

void QuickSort_HoleTest(int vector_size, int upbound, ofstream& results_file, ofstream& data_file) {
    SortTest("QuickSort_Hole", [](vector<int>& A, long long &compare, long long &memaccess) {
        QuickSort_Hole(A, 0, A.size() - 1, compare, memaccess);
    }, vector_size, upbound, results_file, data_file);
}

void QuickSort_HoareTest(int vector_size, int upbound, ofstream& results_file, ofstream& data_file) {
    SortTest("QuickSort_Hoare", [](vector<int>& A, long long &compare, long long &memaccess) {
        QuickSort_Hoare(A, 0, A.size() - 1, compare, memaccess);
    }, vector_size, upbound, results_file, data_file);
}

void QuickSort_BookTest(int vector_size, int upbound, ofstream& results_file, ofstream& data_file) {
    SortTest("QuickSort_Book", [](vector<int>& A, long long &compare, long long &memaccess) {
        QuickSort_Book(A, 0, A.size() - 1, compare, memaccess);
    }, vector_size, upbound, results_file, data_file);
}

void QuickSort_Hole_Better_SelectionTest(int vector_size, int upbound, ofstream& results_file, ofstream& data_file){
    SortTest("QuickSort_Hole_Better_Selection", [](vector<int>&A,long long &compare, long long &memaccess){
        QuickSort_Hole_Better_Selection(A,0,A.size()-1,compare,memaccess);
    }, vector_size, upbound, results_file, data_file);
}

void BlockQuickSortTest(int vector_size, int upbound, std::ofstream& results_file, std::ofstream& data_file) {
    SortTest("BlockQuickSort", [](std::vector<int>& A, long long &compare, long long &memaccess) {
        BlockQuickSort(A, 0, A.size() - 1, compare, memaccess);
    }, vector_size, upbound, results_file, data_file);
}