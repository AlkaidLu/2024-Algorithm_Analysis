#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

// 用于计时
#define GET_TIME(now) { \
    struct timeval t; \
    gettimeofday(&t, NULL); \
    now = t.tv_sec + t.tv_usec/1000000.0; \
}

//初始化及其他辅助函数
void my_alloc(int**num, long n);
void my_free(int**num);
void my_init(int*num, long n);
void show(int *num, long n);

//七个排序函数
void insertSort(int *arr, long n,int*cmp, int*move);
void bubbleSort(int *arr, long n,int*cmp, int*move);
void quickSort1(int *a, long n, long begin, long end, int*cmp, int*move);
void quickSort2(int *a, long n, long begin, long end, int*cmp, int*move);
void quickSort3(int *a, long n, long begin, long end, int*cmp, int*move);
void mergeSort(int*arr, long n,int*cmp, int*move);
void shellSort(int*arr, long n,int*cmp, int*move);
void quickSortPlus(int *a, long n, long begin, long end, int*cmp, int*move);

//三种快排的单趟排序函数
long HoareSort(int*a, long begin, long end, int*cmp, int*move);
long DigHoleSort(int*a, long begin, long end, int*cmp, int*move);
long PBIndexSort(int*a, long begin, long end, int*cmp, int*move);
long GetMidIndex(int*a, long begin, long end, int*cmp, int*move);

//交换两数
void swap(int*a, int*b);


int main(int*argc, char**argv)
{
    srand(time(NULL));
    char func_name[8][16]={"insertSort\0", "bubbleSort\0", "quickSort1\0", 
                            "quickSort2\0", "quickSort3\0", "mergeSort\0", "shellSort\0", "quickSortPlus\0"};
    int**num, cmp[8], move[8];  //  待排序的数据，比较次数，移动次数
    double runtime[8], start[8], end[8];  //  运行时间，开始时间，结束时间
    long n;  //  排序的数据规模
    n=atol(argv[1]);  //  读取输入
    printf("n=%ld\n", n);

    //分配空间及数据初始化
    num=(int**)malloc(sizeof(int**)*8);
    my_alloc(&(num[0]), n);
    my_init(num[0], n);
    for (int i=1;i<8;i++)
    {
        my_alloc(&(num[i]),n);
        memcpy(num[i], num[0], n*4);
        cmp[i]=move[i]=0;
    }

    //分别运行七种排序算法，记录运行时间、比较次数和数据移动次数
    GET_TIME(start[0]);
    insertSort(num[0], n,cmp, move);
    GET_TIME(end[0]);

    GET_TIME(start[1]);
    bubbleSort(num[1], n,cmp+1, move+1);
    GET_TIME(end[1]);

    GET_TIME(start[2]);
    quickSort1(num[2], n, 0, n-1, cmp+2, move+2);
    GET_TIME(end[2]);

    GET_TIME(start[3]);
    quickSort2(num[3], n, 0, n-1, cmp+3, move+3);
    GET_TIME(end[3]);

    GET_TIME(start[4]);
    quickSort3(num[4], n, 0, n-1, cmp+4, move+4);
    GET_TIME(end[4]);

    GET_TIME(start[5]);
    mergeSort(num[5], n, cmp+5, move+5);
    GET_TIME(end[5]);

    GET_TIME(start[6]);
    shellSort(num[6], n, cmp+6, move+6);
    GET_TIME(end[6]);

	GET_TIME(start[7]);
	quickSortPlus(num[7], n, 0, n-1, cmp+7, move+7);
	GET_TIME(end[7]);


    //输出结果（运行时间、比较次数和数据移动次数）
    for (int i=0;i<8;i++)
    {
        //if(i!=2 && i!=3 && i!=4)
        runtime[i]=end[i]-start[i];
        printf("func: %s\t, time: %lf\t, compare: %d\t, movement: %d\t\n", func_name[i], runtime[i], cmp[i], move[i]);
    }

    //释放空间
    for (int i=0;i<8;i++)
        free(num[i]);
    free(num);

    return 0;



}

//输出数组
void show(int *num, long n)
{
    printf("array:\n");
    for (long i=0;i<n;i++)
        printf("%d ", num[i]);
    printf("\n");
}

//分配数组空间
void my_alloc(int**num, long n)
{
    (*num)=(int*)malloc(sizeof(int)*n);
    // return num;
}

//随机生成数据
void my_init(int *num, long n)
{
    for (long i=0;i<n;i++)
        num[i]=rand()%(1<<31-2);
}

//释放数组空间
void my_free(int **num)
{
    free(*num);
    (*num)=NULL;
}

//插入排序
void insertSort(int *arr, long n, int*cmp, int*move) 
{
    long i, j;
    int key;

    *cmp=*move=0;

    for (i = 1; i < n; i++) 
    {
        key = arr[i];
        for (j = i - 1; j >= 0; j--) 
        {
            if (arr[j] > key) 
            {
                arr[j + 1] = arr[j];
                (*cmp)=(*cmp)+1;
                (*move)=(*move)+1;
            }
            else break;
        }
        arr[j+1] = key;
        (*move)=(*move+1);
    }

}

//冒泡排序
void bubbleSort(int *arr, long n, int*cmp, int*move) 
{
    int i, j;

    (*cmp)=(*move)=0;

    for (i = 0; i < n -1; i++) 
    {
        for (j = 0; j < n - i -1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (*cmp)++;
                (*move)++;
            }
        }
    }

}

//快速排序1
void quickSort1(int *a, long n, long begin, long end, int*cmp, int*move)
{	
    if (begin >= end)
		return;
	long meeti = HoareSort(a, begin, end, cmp, move);
	quickSort1(a, n, begin, meeti - 1, cmp, move);
	quickSort1(a, n, meeti + 1, end, cmp, move);  
}

//1单趟排序
long HoareSort(int*a, long begin, long end, int*cmp, int*move)
{
	int key = begin;
	long left = begin, right = end;
	while (left < right)
	{
        (*cmp)=(*cmp)+1;
		while (left < right && a[right] >= a[key])
        {
            right--;
            (*cmp)=(*cmp)+1;
        }	
		while (left < right && a[left] <= a[key])
        {
            left++;
            (*cmp)=(*cmp)+1;      
        }
		swap(&a[right], &a[left]);
        (*move)=(*move)+1;
	}
	long meeti = left;
	swap(&a[meeti], &a[key]);
    (*move)=(*move)+1;
	return meeti;
}

//快速排序2
void quickSort2(int *a, long n, long begin, long end, int*cmp, int*move)
{
	if (begin >= end)
		return;
	long meeti = DigHoleSort(a, begin, end, cmp, move);
	quickSort2(a, n, begin, meeti - 1, cmp, move);
	quickSort2(a, n, meeti + 1, end, cmp, move);
}

//2单趟排序
long DigHoleSort(int*a, long begin, long end, int*cmp, int*move)
{
	int key = a[begin];
	long left = begin, right = end;
	while (left < right)
	{
        (*cmp)=(*cmp)+1;
		//右边找小值
		while (left < right && a[right] >= key)
        {
            (*cmp)=(*cmp)+1;
            right--;
        }
		//放到左边坑位中，右边形成新的坑
		a[left] = a[right];
        (*move)=(*move)+1;
		
		//左边找大值
		while (left < right && a[left] <= key)
        {
            (*cmp)=(*cmp)+1;
            left++;
        }
		//放到右边坑位中，左边形成新的坑
		a[right] = a[left];
        (*move)=(*move)+1;
	}
	long meeti = left;
	a[meeti] = key;
	return left;
}

//快速排序3
void quickSort3(int *a, long n, long begin, long end, int*cmp, int*move)
{
	if (begin >= end)
		return;
	//int meeti = HoareSort(a, begain, end);
	//int meeti = DigHoleSort(a, begain, end);
	int meeti = PBIndexSort(a, begin, end, cmp, move);
	quickSort3(a, n, begin, meeti - 1, cmp, move);
	quickSort3(a, n, meeti + 1, end, cmp, move);
}

//3单趟排序
long PBIndexSort(int*a, long begin, long end, int*cmp, int*move)
{
	long key = begin;
	//定义两个指针，一前一后
	long prev = begin, cur = begin + 1;
	while (cur <= end)
	{
        (*cmp)=(*cmp)+1;
		//如果cur位置值比key小则与perv前一个值进行交换
		if (a[cur] < a[key] && ++prev != cur)
		{
            (*cmp)=(*cmp)+1;
			swap( &a[cur], &a[prev] );
            (*move)=(*move)+1;
		}
		cur++;
	}
	//将key放在prev位置
	swap(&a[prev], &a[begin]);
    (*move)=(*move)+1;
	return prev;
}

//归并排序
void mergeSort(int* arr, long n, int*cmp, int*move)
{

    (*cmp)=(*move)=0;


	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	long gap = 1;
	long i = 0;
	long j = 0;
	while (gap < n)
	{
        (*cmp)++;
		for (i = 0; i < n; i += 2*gap)
		{
			//[ i , i+gap-1][i+gap,i+2*gap-1]
			long begin1 = i;
			long end1 = i + gap - 1;
			long begin2 = i + gap;
			long end2 = i + 2*gap-1 ;
			j = i;

			//1. end1 begin2 end2 越界
			if (end1 >= n)//end2是下标的存在 ，最多取到 n-1
			{
				break;
			}
			//2.  begin2 end2 越界
			else if (begin2 >= n)
			{
				break;
			}
			//3. end2 越界
			else if (end2 >= n)
			{
				end2 = n - 1;
			}
			while (begin1 <= end1 && begin2 <= end2)
			{
                (*cmp)+=2;
				if (arr[begin1] <= arr[begin2])
				{
					tmp[j++] = arr[begin1++];
                    (*cmp)++;
                    (*move)++;
				}
				else
				{
					tmp[j++] = arr[begin2++];
                    (*cmp)++;
                    (*move)++;
				}
			}
			while (begin1 <= end1)
			{
                (*cmp)++;
				tmp[j++] = arr[begin1++];
                (*move)++;
			}
			while (begin2 <= end2)
			{
                (*cmp)++;
				tmp[j++] = arr[begin2++];
                (*move)++;
			}
			//归并一部分，拷贝一部分
			memcpy(arr+i, tmp+i, sizeof(int) * (end2-i+1));
		}
		gap *= 2;
	}
	free(tmp);
	tmp = NULL;


}  //  move???

//希尔排序
void shellSort(int*arr, long n, int*cmp, int*move)
{
    (*cmp)=(*move)=0;
	int gap = n;
	while (gap > 1)
	{
		//  gap /= 2;
        (*cmp)++;
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int x = arr[end + gap];
			while (end >= 0)
			{
                (*cmp)+=2;
				if (arr[end] > x)
				{
					arr[end + gap] = arr[end];
                    (*move)++;
					end -= gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = x;
            (*move)++;
		}
	}
}

//交换
void swap(int *p1,int *p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}


void quickSortPlus(int *a, long n, long left, long right, int*cmp, int*move)
{

	if(left >= right)
	{
		return;
	}
	
	int index=GetMidIndex(a, left, right, cmp, move);
	swap(&a[left],&a[index]);//交换一下，防止key取到最小值或者最大值
	
	//下面逻辑不变，和挖坑法的一样
	int bagin=left,end=right;
	int pivot=bagin;//坑
	int key=a[bagin]; //关键字
	
	while(bagin < end)
	{
		//1.右边找小的放到左边
		(*cmp)=(*cmp)+1;
		while(bagin < end && a[end] >= key)
		{
			(*cmp)=(*cmp)+1;
			end--;
		}
		//小的放到左边的坑里
		a[pivot]=a[end];
		pivot=end;
		(*move)=(*move)+1;
		//2.左边找大的放到右边
		while(bagin < end && a[bagin] <= key)
		{
			(*cmp)=(*cmp)+1;
			bagin++;
		}
		//大的放到右边的新坑里
		a[pivot]=a[bagin];
		pivot=bagin;
		(*move)=(*move)+1;
	}
	pivot=bagin;//pivot=end;
	a[pivot]=key;
	(*move)=(*move)+1;
	
	//[left,right]
	//[left,pivot-1] pivot [pivot+1,right]
	//如果左 右子区间有序整体就有序了 -> 分治递归
	quickSortPlus(a, n, left, pivot-1, cmp, move);
	quickSortPlus(a, n, pivot+1, right, cmp, move);
}

long GetMidIndex(int*a, long left, long right, int*cmp, int*move)
{
	int mid=(left+right)>>1;//int mid=(left+right)/2;
	if(a[left] < a[mid])
	{
		if(a[mid] < a[right])
		{
			return mid;
		}
		else 
		{
			if(a[left] > a[right])
			{
				return left;
			}
			else
			{
				return right;
			}
		}
	}
	else
	{
		if(a[mid] > a[right])
		{
			return mid;
		}
		else
		{
			if(a[left] < a[right])
			{
				return left;
			}
			else
			{
				return right;
			}
		}
	}
}