#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>


void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; ++j) {
            if (arr[j] <= pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        int pivotIndex = i + 1;
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}


void insertionSort(std::vector<int>& arr, int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= low && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int partitionBlock(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void blockQuickSort(std::vector<int>& arr, int low, int high, int blockSize) {
    if (low < high) {
        if (high - low > blockSize) {
            int pivot = partitionBlock(arr, low, high);
            blockQuickSort(arr, low, pivot - 1, blockSize);
            blockQuickSort(arr, pivot + 1, high, blockSize);
        } else {
            insertionSort(arr, low, high);
        }
    }
}


void dualPivotPartition(std::vector<int>& arr, int low, int high, int* lp, int* rp) {
    if (arr[low] > arr[high]) {
        std::swap(arr[low], arr[high]);
    }
    int pivot1 = arr[low], pivot2 = arr[high];
    int i = low + 1, lt = low + 1, gt = high - 1;
    while (i <= gt) {
        if (arr[i] < pivot1) {
            std::swap(arr[i++], arr[lt++]);
        } else if (arr[i] > pivot2) {
            std::swap(arr[i], arr[gt--]);
        } else {
            i++;
        }
    }
    std::swap(arr[low], arr[--lt]);
    std::swap(arr[high], arr[++gt]);
    *lp = lt;
    *rp = gt;
}

void dualPivotQuickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int lp, rp;
        dualPivotPartition(arr, low, high, &lp, &rp);
        dualPivotQuickSort(arr, low, lp - 1);
        dualPivotQuickSort(arr, lp + 1, rp - 1);
        dualPivotQuickSort(arr, rp + 1, high);
    }
}



void generateRandomData(std::vector<int>& data, int size, int maxValue) {
    for (int i = 0; i < size; ++i) {
        data.push_back(rand() % maxValue);
    }
}

void runPerformanceTest(int size, int maxValue) {
    std::vector<int> data;
    generateRandomData(data, size, maxValue);

    std::vector<int> dataQuickSort = data;
    std::vector<int> dataBlockQuickSort = data;
    std::vector<int> dataDualPivotQuickSort = data;

    // 经典快速排序
    clock_t start = clock();
    quickSort(dataQuickSort, 0, dataQuickSort.size() - 1);
    clock_t end = clock();
    std::cout << "Classic QuickSort Time: " << double(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

    // BlockQuickSort
    start = clock();
    blockQuickSort(dataBlockQuickSort, 0, dataBlockQuickSort.size() - 1, 16);
    end = clock();
    std::cout << "BlockQuickSort Time: " << double(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

    // DualPivotQuickSort
    start = clock();
    dualPivotQuickSort(dataDualPivotQuickSort, 0, dataDualPivotQuickSort.size() - 1);
    end = clock();
    std::cout << "DualPivotQuickSort Time: " << double(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;
}

int main() {
    srand(time(nullptr));
	
	int size = 50000000; // 五千万个整数
	int maxValue = size>>1; // 最大整数值
    runPerformanceTest(size, maxValue);
	
    size = 100000000; // 1亿个整数
	maxValue = size>>1; // 最大整数值

    runPerformanceTest(size, maxValue);
	
	size = 150000000; //1亿五千万
	maxValue = size>>1;
	runPerformanceTest(size, maxValue);
    return 0;
}
