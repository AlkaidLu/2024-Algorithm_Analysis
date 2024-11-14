#include "algorithm.h"
using namespace std;


void Test(SortFunction sortFunc) {
  vector<int> nums(100);
  for (int i = 0; i < 100; i++)
    nums[i] = 100 - i;
  sortFunc(nums);
  int flag = 0;
  for (int i = 0; i < 100; i++) {
    if (nums[i] != i + 1)
      flag = 1;
  }
  if (flag)
    cout << "The code is wrong.\n";
  else
    cout << "The code is correct.\n";
}
