#include "algorithm.h"
#include "cstdio"
using namespace std;

long int insertSortComparisons = 0;
long int insertSortMoves = 0;
long int bubbleSortComparisons = 0;
long int bubbleSortMoves = 0;
long int mergeSortComparisons = 0;
long int mergeSortMoves = 0;
long int quickSortComparisons = 0;
long int quickSortMoves = 0;
long int shellSortComparisons = 0;
long int shellSortMoves = 0;
long int blockQuickSortBranchPredictions = 0;
long int dualPivotQuickSortRecursionDepth = 0;
long int optimizedQuickSortComparisons = 0;
long int optimizedQuickSortMoves = 0;
long int currentRecursionDepth = 0;
long int logQuickSortBranchPredictions = 0;
long int logQuickSortRecursionDepth = 0;
long int currentLogQuickSortDepth = 0;

void InsertSort(vector<int> &nums) {
  for (int i = 1; i < nums.size(); i++) {
    int j = i, key = nums[j];
    while (j > 0 && nums[j - 1] > key) {
      insertSortComparisons++;
      nums[j] = nums[j - 1];
      insertSortMoves++;
      j--;
    }
    nums[j] = key;
    insertSortMoves++;
  }
}

void BubbleSort(vector<int> &nums) {
  bool swapped;
  for (int i = 0; i < nums.size() - 1; i++) {
    swapped = false;
    for (int j = 0; j < nums.size() - i - 1; j++) {
      bubbleSortComparisons++;
      if (nums[j] > nums[j + 1]) {
        swap(nums[j], nums[j + 1]);
        bubbleSortMoves += 3;
        swapped = true;
      }
    }
    if (!swapped)
      break;
  }
}

void merge(vector<int> &nums, int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;
  vector<int> L(n1), R(n2);
  for (int i = 0; i < n1; i++)
    L[i] = nums[left + i];
  for (int j = 0; j < n2; j++)
    R[j] = nums[mid + 1 + j];
  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    mergeSortComparisons++;
    if (L[i] <= R[j]) {
      nums[k] = L[i];
      i++;
    } else {
      nums[k] = R[j];
      j++;
    }
    mergeSortMoves++;
    k++;
  }
  while (i < n1) {
    nums[k] = L[i];
    i++;
    k++;
    mergeSortMoves++;
  }
  while (j < n2) {
    nums[k] = R[j];
    j++;
    k++;
    mergeSortMoves++;
  }
}

void mergeSortHelper(vector<int> &nums, int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    mergeSortHelper(nums, left, mid);
    mergeSortHelper(nums, mid + 1, right);
    merge(nums, left, mid, right);
  }
}

void MergeSort(vector<int> &nums) { mergeSortHelper(nums, 0, nums.size() - 1); }

void quickSortHelper(vector<int> &nums, int low, int high) {
  if (low < high) {
    int pivot = nums[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
      quickSortComparisons++;
      if (nums[j] < pivot) {
        i++;
        swap(nums[i], nums[j]);
        quickSortMoves += 3;
      }
    }
    swap(nums[i + 1], nums[high]);
    quickSortMoves += 3;
    int pi = i + 1;
    quickSortHelper(nums, low, pi - 1);
    quickSortHelper(nums, pi + 1, high);
  }
}

void QuickSort(vector<int> &nums) { quickSortHelper(nums, 0, nums.size() - 1); }

void ShellSort(vector<int> &nums) {
  int n = nums.size();
  for (int gap = n / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < n; i++) {
      int temp = nums[i];
      int j;
      for (j = i; j >= gap && nums[j - gap] > temp; j -= gap) {
        shellSortComparisons++;
        nums[j] = nums[j - gap];
        shellSortMoves++;
      }
      nums[j] = temp;
      shellSortMoves++;
    }
  }
}

void BLOCKPARTITION(vector<int> &A, int left, int right, int pivot) {
  int B = 128; // 假设B的值为16，可以根据实际情况调整
  vector<int> offsetsL(B, 0), offsetsR(B, 0);
  int startL = 0, startR = 0, numL = 0, numR = 0;

  while (right - left + 1 > 2 * B) {
    if (numL == 0) {
      startL = 0;
      for (int i = 0; i < B; i++) {
        offsetsL[numL] = i;
        numL += (pivot >= A[left + i]);
      }
    }
    if (numR == 0) {
      startR = 0;
      for (int i = 0; i < B; i++) {
        offsetsR[numR] = i;
        numR += (pivot <= A[right - i]);
      }
    }
    int num = min(numL, numR);
    for (int j = 0; j < num; j++) {
      swap(A[left + offsetsL[startL + j]], A[right - offsetsR[startR + j]]);
    }
    numL -= num;
    numR -= num;
    startL += num;
    startR += num;

    if (numL == 0)
      left += B;
    if (numR == 0)
      right -= B;
  }
}

void blockQuickSortHelper(vector<int> &nums, int left, int right) {
  if (left < right) {
    int pivot = nums[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
      blockQuickSortBranchPredictions++;
      if (nums[j] <= pivot) {
        i++;
        swap(nums[i], nums[j]);
      }
    }
    swap(nums[i + 1], nums[right]);
    int pi = i + 1;
    BLOCKPARTITION(nums, left, pi - 1, nums[left]);
    BLOCKPARTITION(nums, pi + 1, right, nums[right]);
    blockQuickSortHelper(nums, left, pi - 1);
    blockQuickSortHelper(nums, pi + 1, right);
  }
}

int partitionBlock(std::vector<int> &arr, int low, int high) {
  int pivot = arr[high];
  int i = low - 1;
  for (int j = low; j < high; ++j) {
    blockQuickSortBranchPredictions++;
    if (arr[j] < pivot) {
      ++i;
      std::swap(arr[i], arr[j]);
    }
  }
  std::swap(arr[i + 1], arr[high]);
  return i + 1;
}

void insertionSort(std::vector<int> &arr, int low, int high) {
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

void blockQuickSort(std::vector<int> &arr, int low, int high, int blockSize) {
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

void BlockQuickSort(vector<int> &nums) {
  blockQuickSortBranchPredictions = 0;
  blockQuickSort(nums, 0, nums.size() - 1, 16);
}

void dualPivotQuickSortHelper(vector<int> &nums, int left, int right) {
  if (left < right) {
    currentRecursionDepth++;
    dualPivotQuickSortRecursionDepth =
        max(dualPivotQuickSortRecursionDepth, currentRecursionDepth);

    if (nums[left] > nums[right])
      swap(nums[left], nums[right]);

    int pivot1 = nums[left], pivot2 = nums[right];
    int i = left + 1, j = right - 1, k = left + 1;

    while (k <= j) {
      if (nums[k] < pivot1) {
        swap(nums[k], nums[i]);
        i++;
      } else if (nums[k] > pivot2) {
        swap(nums[k], nums[j]);
        j--;
        k--;
      }
      k++;
    }
    i--;
    j++;

    swap(nums[left], nums[i]);
    swap(nums[right], nums[j]);

    dualPivotQuickSortHelper(nums, left, i - 1);
    dualPivotQuickSortHelper(nums, i + 1, j - 1);
    dualPivotQuickSortHelper(nums, j + 1, right);

    currentRecursionDepth--;
  }
}

void DualPivotQuickSort(vector<int> &nums) {
  dualPivotQuickSortRecursionDepth = 0;
  currentRecursionDepth = 0;
  dualPivotQuickSortHelper(nums, 0, nums.size() - 1);
}

int medianOfThree(vector<int> &nums, int a, int b, int c) {
  if (nums[a] < nums[b]) {
    if (nums[b] < nums[c])
      return b;
    if (nums[a] < nums[c])
      return c;
    return a;
  } else {
    if (nums[a] < nums[c])
      return a;
    if (nums[b] < nums[c])
      return c;
    return b;
  }
}

void optimizedQuickSortHelper(vector<int> &nums, int left, int right,
                              int threshold) {
  if (left + threshold <= right) {
    int pivotIndex = medianOfThree(nums, left, right, (left + right) / 2);
    swap(nums[pivotIndex], nums[right]);
    int pivot = nums[right];
    int i = left - 1;
    for (int j = left; j < right; ++j) {
      optimizedQuickSortComparisons++;
      if (nums[j] < pivot) {
        ++i;
        swap(nums[i], nums[j]);
        optimizedQuickSortMoves += 3;
      }
    }
    swap(nums[i + 1], nums[right]);
    optimizedQuickSortMoves += 3;
    int pi = i + 1;
    optimizedQuickSortHelper(nums, left, pi - 1, threshold);
    optimizedQuickSortHelper(nums, pi + 1, right, threshold);
  } else {
    insertionSort(nums, left, right);
  }
}

void OptimizedQuickSort(vector<int> &nums) {
  optimizedQuickSortComparisons = 0;
  optimizedQuickSortMoves = 0;
  optimizedQuickSortHelper(nums, 0, nums.size() - 1, 64);
}

void logQuickSortHelper(vector<int> &nums, int low, int high) {
  if (low < high) {
    currentLogQuickSortDepth++;
    logQuickSortRecursionDepth =
        max(logQuickSortRecursionDepth, currentLogQuickSortDepth);

    int pivot = nums[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
      logQuickSortBranchPredictions++;
      if (nums[j] < pivot) {
        i++;
        swap(nums[i], nums[j]);
      }
    }
    swap(nums[i + 1], nums[high]);
    int pi = i + 1;

    logQuickSortHelper(nums, low, pi - 1);
    logQuickSortHelper(nums, pi + 1, high);

    currentLogQuickSortDepth--;
  }
}

void LogQuickSort(vector<int> &nums) {
  logQuickSortBranchPredictions = 0;
  logQuickSortRecursionDepth = 0;
  currentLogQuickSortDepth = 0;

  logQuickSortHelper(nums, 0, nums.size() - 1);
}
