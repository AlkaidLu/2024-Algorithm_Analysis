#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <string>
#include <cstring>
#include <random>
using namespace std;
/*
function   : ��������в�������
param nums : Ҫ�������������
return     : ---
*/
void Prt(vector<int>& nums)
{
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;
}
//last element as pivot
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

//rand element as pivot
int PartitionRand(vector<int> &nums, int left, int right, long long &CntCmp, long long &CntSwp)
{
    int rand_idx = rand() % (right - left + 1) + left;
    swap(nums[right], nums[rand_idx]);
    CntSwp++;
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

void QuickSortRand(vector<int> &nums, int left, int right, long long &CntCmp, long long &CntSwp)
{
	if (left < right)
	{
		int pivot = PartitionRand(nums, left, right, CntCmp, CntSwp);
		QuickSortRand(nums, left, pivot - 1, CntCmp, CntSwp);
		QuickSortRand(nums, pivot + 1, right, CntCmp, CntSwp);
	}
}

//the midnum of the last three elements as pivot
int PartitionThree(vector<int> &nums, int left, int right, long long &CntCmp, long long &CntSwp)
{
	if(right - left + 1 >= 3)
	{
		if(nums[right] > nums[right - 1] && nums[right-1] > nums[right-2])
		{
			swap(nums[right-1], nums[right]); 
			CntSwp++;
			CntCmp+=1;
		}
		else if(nums[right-2] > nums[right - 1] && nums[right-1] > nums[right])
		{
			swap(nums[right-1], nums[right]);
			CntSwp++;
			CntCmp+=2;
		}
		else if(nums[right] > nums[right-2] && nums[right-2] > nums[right-1])
		{
			swap(nums[right-2], nums[right]);
			CntSwp++;
			CntCmp+=3;
		}
		else if(nums[right-1] > nums[right-2] && nums[right-2] > nums[right])
		{
			swap(nums[right-2], nums[right]);
			CntSwp++;
			CntCmp+=4;
		}
	}
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

void QuickSortThree(vector<int> &nums, int left, int right, long long &CntCmp, long long &CntSwp)
{
	if (left < right)
	{
		int pivot = PartitionThree(nums, left, right, CntCmp, CntSwp);
		QuickSortThree(nums, left, pivot - 1, CntCmp, CntSwp);
		QuickSortThree(nums, pivot + 1, right, CntCmp, CntSwp);
	}
}

//the method of kong xue 
void QuickSortKongXue(vector<int> &nums, int left, int right, long long &CntCmp, long long &CntSwp)
{
	if(left >= right)
	{
		return ;
	}
	int pivot = nums[left];
	int l = left;
	int r = right;
	while(l < r)
	{
		CntCmp++;
		while(l < r && nums[r] > pivot)
		{
			r--;
			CntCmp++;
		}
		if(l < r)
		{
			nums[l] = nums[r];
			CntSwp++;
			l++;
		}
		CntCmp++;
		while(l < r && nums[l] < pivot)
		{
			l++;
			CntCmp++;
		}
		if(l < r)
		{
			nums[r] = nums[l];
			CntSwp++;
			r--;
		}
	}
	nums[l] = pivot;
	CntSwp++;
	QuickSortKongXue(nums, left, l-1, CntCmp, CntSwp);
	QuickSortKongXue(nums, l+1, right, CntCmp, CntSwp);
}

//the original quicksort algorithm(Hoare partition)
void QuickSortHoare(vector<int> &nums, int left, int right, long long &CntCmp, long long &CntSwp)
{
	if(left >= right)
	{
		return;
	}
	int pivot = nums[left];
	int l = left + 1;
	int r = right;

	while(l <= r)  // 修改为 l <= r
	{
		while(l <= r && nums[l] <= pivot)  // 修改条件
		{
			l++;
			CntCmp++;
		}
		CntCmp++;
		while(l <= r && nums[r] > pivot)  // 修改条件
		{
			r--;
			CntCmp++;
		}
		if(l < r)
		{
			swap(nums[l], nums[r]);
			CntSwp++;
		}
	}

	swap(nums[left], nums[r]);  // 移动 pivot 到合适位置
	CntSwp++;

	QuickSortHoare(nums, left, r - 1, CntCmp, CntSwp);
	QuickSortHoare(nums, r + 1, right, CntCmp, CntSwp);
}


//Lomuto QuickSort
void QuickSortLomuto (vector<int> &nums, int left, int right, long long &CntCmp, long long &CntSwp)
{
	if(left >= right)
	{
		return ;
	}
	int prev = left;
	int pcur = left + 1;
	int key = nums[left];
	CntCmp++;
	while(pcur <= right)
	{
		CntCmp++;
		if(nums[pcur] < key && ++prev != pcur)
		{
			swap(nums[prev], nums[pcur]);
			CntSwp++;
		}
		pcur++;
	}
	swap(nums[left], nums[prev]);
	CntSwp++;
	QuickSortLomuto(nums, left, prev-1, CntCmp, CntSwp);
	QuickSortLomuto(nums, prev+1, right, CntCmp, CntSwp);
}