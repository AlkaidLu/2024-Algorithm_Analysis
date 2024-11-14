#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

/*
function   : 输出一个数组
param nums : 要输出的数组引用
return     : ---
*/
void Out(vector<int> &nums)
{
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << endl;
}
