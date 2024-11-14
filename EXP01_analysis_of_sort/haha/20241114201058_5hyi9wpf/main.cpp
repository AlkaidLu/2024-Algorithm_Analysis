#include "algorithm.h"
#include <cstring>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

#define UP_BOUND 123456

void printHelp() {
  cout << "usage: ./main <FUNCTION> [OPTION]\n"
       << "DESCRIPTION:\n"
       << "FUNCTION:\n"
       << "    --function=FUNC\n"
       << "        MUST be given. if not, turn to --help\n"
       << "        choose function FUNC to sort the vector\n"
       << "        FUNC list: InsertSort, BubbleSort, MergeSort, QuickSort, "
          "ShellSort, BlockQuickSort, DualPivotQuickSort, OptimizedQuickSort, "
          "LogQuickSort\n"
       << "OPTION:\n"
       << "    -h, --help\n"
       << "        print this help info and quit\n"
       << "    -t, --test\n"
       << "        run the function Test() to check the FUNC\n"
       << "        this parameter will disable --size and --repeat\n"
       << "    --size=N\n"
       << "        to determine vector_size in main\n"
       << "        the default value is 10000 if not specially given\n"
       << "    --repeat=N\n"
       << "        to determine num_repeat in main\n"
       << "        the default value is 100 if not specially given\n";
}

SortFunction getSortFunction(const string &function) {
  if (function == "InsertSort")
    return InsertSort;
  if (function == "BubbleSort")
    return BubbleSort;
  if (function == "MergeSort")
    return MergeSort;
  if (function == "QuickSort")
    return QuickSort;
  if (function == "ShellSort")
    return ShellSort;
  if (function == "BlockQuickSort")
    return BlockQuickSort;
  if (function == "DualPivotQuickSort")
    return DualPivotQuickSort;
  if (function == "OptimizedQuickSort")
    return OptimizedQuickSort;
  if (function == "LogQuickSort") // 添加 LogQuickSort
    return LogQuickSort;
  return NULL;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printHelp();
    return 1;
  }

  string function;
  int vector_size = 10000;
  int num_repeat = 100;
  bool test_mode = false;

  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
      printHelp();
      return 0;
    } else if (strncmp(argv[i], "--function=", 11) == 0) {
      function = string(argv[i] + 11);
    } else if (strcmp(argv[i], "-t") == 0 || strcmp(argv[i], "--test") == 0) {
      test_mode = true;
    } else if (strncmp(argv[i], "--size=", 7) == 0) {
      vector_size = atoi(argv[i] + 7);
    } else if (strncmp(argv[i], "--repeat=", 9) == 0) {
      num_repeat = atoi(argv[i] + 9);
    }
  }

  if (function.empty()) {
    printHelp();
    return 1;
  }

  SortFunction sortFunc = getSortFunction(function);
  if (!sortFunc) {
    printHelp();
    return 1;
  }

  if (test_mode) {
    Test(sortFunc);
    return 0;
  }

  double sum_time = 0;
  for (int i = 0; i < num_repeat; i++) {
    vector<int> vec(vector_size);
    for (int j = 0; j < vector_size; j++)
      vec[j] = rand() % UP_BOUND;
    clock_t start_time, end_time;
    start_time = clock();

    sortFunc(vec);

    end_time = clock();
    sum_time += (double)(end_time - start_time) / CLOCKS_PER_SEC;
  }

  cout << "The average time is " << sum_time / num_repeat << " s." << endl;

  if (function == "InsertSort") {
    cout << "Comparisons: " << insertSortComparisons / num_repeat
         << ", Moves: " << insertSortMoves / num_repeat << endl;
  } else if (function == "BubbleSort") {
    cout << "Comparisons: " << bubbleSortComparisons / num_repeat
         << ", Moves: " << bubbleSortMoves / num_repeat << endl;
  } else if (function == "MergeSort") {
    cout << "Comparisons: " << mergeSortComparisons / num_repeat
         << ", Moves: " << mergeSortMoves / num_repeat << endl;
  } else if (function == "QuickSort") {
    cout << "Comparisons: " << quickSortComparisons / num_repeat
         << ", Moves: " << quickSortMoves / num_repeat << endl;
  } else if (function == "ShellSort") {
    cout << "Comparisons: " << shellSortComparisons / num_repeat
         << ", Moves: " << shellSortMoves / num_repeat << endl;
  } else if (function == "BlockQuickSort") {
    cout << "Branch Predictions: "
         << blockQuickSortBranchPredictions / num_repeat << endl;
  } else if (function == "DualPivotQuickSort") {
    cout << "Recursion Depth: " << dualPivotQuickSortRecursionDepth / num_repeat
         << endl;
  } else if (function == "OptimizedQuickSort") {
    cout << "Comparisons: " << optimizedQuickSortComparisons / num_repeat
         << ", Moves: " << optimizedQuickSortMoves / num_repeat << endl;
  } else if (function == "LogQuickSort") {
    cout << "Branch Predictions: " << logQuickSortBranchPredictions / num_repeat
         << "\nRecursion Depth: " << logQuickSortRecursionDepth / num_repeat
         << endl;
  }

  return 0;
}
