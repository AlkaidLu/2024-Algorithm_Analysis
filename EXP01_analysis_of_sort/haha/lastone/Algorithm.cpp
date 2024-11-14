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
function   : ��������в�������
param nums : Ҫ�������������
return     : ---
*/
void InsertSort(vector<int> &nums, long long &CntCmp, long long &CntSwp)
{	
	for (int i = 1; i < nums.size(); i++)
	{
		int j = i, key = nums[j];
		CntCmp++;
		while (j > 0 && nums[j - 1] > key)
		{
			CntSwp++;
			CntCmp++;
			nums[j] = nums[j - 1];
			j--;
		}
		nums[j] = key;
		CntSwp++;
	}
}

void BubbleSort(vector<int> &nums, long long &CntCmp, long long &CntSwp)
{
	for (int i = 0; i < nums.size() - 1; i++)
	{
		bool flag = false;
		for (int j = 0; j < nums.size() - i - 1; j++)
		{
			CntCmp++;
			if (nums[j] > nums[j + 1])
			{
				CntSwp++;
				swap(nums[j], nums[j + 1]);
				flag = true;
			}
		}
		if(!flag)
		{
			break;
		}
	}
}

int Partition(vector<int> &nums, int left, int right, long long &CntCmp, long long &CntSwp)
{
	int pivot = nums[right];
	int i = left - 1;
	for (int j = left; j < right; j++)
	{
		CntCmp++;
		if (nums[j] < pivot)
		{
			i++;
			swap(nums[i], nums[j]);
			CntSwp++;
		}
	}
	swap(nums[i + 1], nums[right]);
	CntSwp++;
	return i + 1;
}

void QuickSort(vector<int> &nums, int left, int right, long long &CntCmp, long long &CntSwp)
{
	if (left < right)
	{
		int pivot = Partition(nums, left, right, CntCmp, CntSwp);
		QuickSort(nums, left, pivot - 1, CntCmp, CntSwp);
		QuickSort(nums, pivot + 1, right, CntCmp, CntSwp);
	}
}

void Merge(vector<int> &nums, int left, int mid, int right, long long &CntCmp, long long &CntSwp)
{
	vector<int> temp(right - left + 1);
	int i = left, j = mid + 1, k = 0;
	while (i <= mid && j <= right)
	{
		CntCmp++;
		if (nums[i] <= nums[j])
		{
			temp[k++] = nums[i++];
			CntSwp++;
		}
		else
		{
			temp[k++] = nums[j++];
			CntSwp++;
		}
	}
	while (i <= mid)
	{
		temp[k++] = nums[i++];
		CntSwp++;
	}
	while (j <= right)
	{
		temp[k++] = nums[j++];
		CntSwp++;
	}
	for (int i = 0; i < right - left + 1; i++)
	{
		nums[left + i] = temp[i];
		CntSwp++;
	}
}

void MergeSort(vector<int> &nums, int left, int right, long long &CntCmp, long long &CntSwp)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		MergeSort(nums, left, mid, CntCmp, CntSwp);
		MergeSort(nums, mid + 1, right, CntCmp, CntSwp);
		Merge(nums, left, mid, right, CntCmp, CntSwp);
	}
}

void ShellSort(vector<int> &nums, long long &CntCmp, long long &CntSwp)
{
	int n = nums.size();
	int gap = n / 2;
	while (gap > 0)
	{
		for (int i = gap; i < n; i++)
		{
			int j = i;
			int temp = nums[i];
			CntCmp++;
			while (j >= gap && nums[j - gap] > temp)
			{
				nums[j] = nums[j - gap];
				j -= gap;
				CntCmp++;
				CntSwp++;
			}
			nums[j] = temp;
			CntSwp++;
		}
		gap /= 2;
	}
}


