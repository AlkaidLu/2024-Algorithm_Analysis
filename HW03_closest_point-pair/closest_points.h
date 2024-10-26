#include<iostream>
#include<vector>
#include<random>
#include<ctime>
#include<cmath>
#include <fstream>
#include<limits>
#include <set>
#include <tuple> 
#include <unordered_set>
using namespace std;

struct Point{
    double x;
    double y;
    Point() : x(0), y(0) {}
    Point(const Point& other) : x(other.x), y(other.y) {} 
    Point& operator=(const Point& other)  {
        if (this != &other) { // 防止自赋值
            x = other.x;
            y = other.y;
        }
        return *this;
    }
    bool operator<(const Point& other) const {
        return tie(x, y) < tie(other.x, other.y);
    }
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
     }
    
    //int index;
};//一个点


vector<Point> EMPTY;

vector<Point> getRandomPoints(int x_low,int x_high,int y_low,int y_high,int n);
vector<Point> MinDistance(vector<Point>&points);
int AdjustArray_byX(vector<Point>&s, int l, int r);
int AdjustArray_byY(vector<Point>&s, int l, int r);
void quick_sort1(vector<Point>& s, int l, int r) ;
void quick_sort2(vector<Point>& s, int l, int r);
vector<Point> quick_sort1(const vector<Point>& input);
vector<Point> quick_sort2(const vector<Point>& input) ;
vector<Point> naiveDivideConquer(const vector<Point>&points,int n);
vector<Point> DivideConquer(vector<Point>&X,vector<Point>&Y,int n);
vector<Point> preprocessedDivideConquer(const vector<Point>&points,int n);

//生成随机的n个点

vector<Point> getRandomPoints(int x_low, int x_high, int y_low, int y_high, int n) {
    vector<Point> points;

    if (n <= 1) {
        printf("Error! Points shouldn't be less than 2.");
        exit(0);
    }

    random_device seed; // 硬件生成随机数种子
    ranlux48 gen(seed()); // 利用种子生成随机数引擎
    uniform_real_distribution<> dis_x(x_low, x_high); // 设置x的范围
    uniform_real_distribution<> dis_y(y_low, y_high); // 设置y的范围

    while (points.size() < static_cast<size_t>(n)) {
        Point p;
        p.x = dis_x(gen);
        p.y = dis_y(gen);
        points.push_back(p);     // 添加到结果向量中
        }
    

    return points;
}

//暴力算法
vector<Point> MinDistance(vector<Point>&points){
    double compare=INFINITY;
    int index1=-1;
    int index2=-1;
    int n=points.size();
    if(n<=1){
        printf("Error! Points shouldn't be less than 2.");
        exit(0);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            //如果是同一个点，跳过
            if (points[i].x == points[j].x && points[i].y == points[j].y) {
                continue;
            }

            double distance=sqrt(pow(points[i].x-points[j].x,2)+pow(points[i].y-points[j].y,2));
            if(distance<compare){
                compare=distance;
                index1=i;
                index2=j;
            }
        }
    }
    vector<Point> p;
    if (index1 != -1 && index2 != -1) {
        p.push_back(points[index1]);
        p.push_back(points[index2]);
    }
    return p;
}

//快速排序调整数组的函数

int AdjustArray_byX(vector<Point>&s, int l, int r) //返回调整后基准数的位置
{
	int i = l, j = r;
	double x = s[l].x; //s[l]即s[i]就是第一个坑
    Point tmp=s[l];
	while (i < j)
	{
		// 从右向左找小于x的数来填s[i]
		while(i < j && s[j].x >= x) 
			j--;  
		if(i < j) 
		{
			swap(s[i] , s[j]); //将s[j]填到s[i]中，s[j]就形成了一个新的坑
			i++;
		}
 
		// 从左向右找大于或等于x的数来填s[j]
		while(i < j && s[i].x < x)
			i++;  
		if(i < j) 
		{
			swap(s[j] , s[i]); //将s[i]填到s[j]中，s[i]就形成了一个新的坑
			j--;
		}
	}
	//退出时，i等于j。将x填到这个坑中。
	s[i] = tmp;
 
	return i;
}


int AdjustArray_byY(vector<Point>&s, int l, int r) //返回调整后基准数的位置
{
	int i = l, j = r;
	double y = s[l].y; //s[l]即s[i]就是第一个坑
    Point tmp=s[l];
	while (i < j)
	{
		// 从右向左找小于x的数来填s[i]
		while(i < j && s[j].y >= y) 
			j--;  
		if(i < j) 
		{
			swap(s[i] , s[j]); //将s[j]填到s[i]中，s[j]就形成了一个新的坑
			i++;
		}
 
		// 从左向右找大于或等于x的数来填s[j]
		while(i < j && s[i].y < y)
			i++;  
		if(i < j) 
		{
			swap(s[j] , s[i]); //将s[i]填到s[j]中，s[i]就形成了一个新的坑
			j--;
		}
	}
	//退出时，i等于j。将x填到这个坑中。
	s[i] = tmp;
 
	return i;
}


void quick_sort1(vector<Point>& s, int l, int r) {
    if (l < r) {
        int i = AdjustArray_byX(s, l, r); // 调整数组
        quick_sort1(s, l, i - 1); // 递归排序左部分
        quick_sort1(s, i + 1, r); // 递归排序右部分
    }
}

void quick_sort2(vector<Point>& s, int l, int r) {
    if (l < r) {
        int i = AdjustArray_byY(s, l, r); // 调整数组
        quick_sort2(s, l, i - 1); // 递归排序左部分
        quick_sort2(s, i + 1, r); // 递归排序右部分
    }
}

// 你可以将原先的快速排序函数修改为调用新的快速排序函数
vector<Point> quick_sort1(const vector<Point>& input) {
    vector<Point> s = input; // 创建一个拷贝用于排序
    quick_sort1(s, 0, s.size() - 1); // 调用排序
    return s;
}

vector<Point> quick_sort2(const vector<Point>& input) {
    vector<Point> s = input; // 创建一个拷贝用于排序
    quick_sort2(s, 0, s.size() - 1); // 调用排序
    return s;
}

//朴素的分治法
vector<Point> naiveDivideConquer(const vector<Point>&points,int n){
    //递归出口
    if(n<=3){
        return MinDistance(const_cast<vector<Point>&>(points));
    }
    else{
        //对X和Y排序
        vector<Point> X=quick_sort1(points);
        vector<Point> Y=quick_sort2(points);
        //声明储存结果的几个变量
        double delta_L,delta_R;
        Point p1,p2,p3,p4;
        //构造函数需要的变量
        vector<Point> PL=vector<Point>(X.begin(),X.begin()+n/2);
        vector<Point> PR=vector<Point>(X.begin()+n/2,X.end());
        //递归
        vector<Point> L_result=naiveDivideConquer(PL,n/2);
        vector<Point> R_result=naiveDivideConquer(PR,n-n/2);
        //把结果放进变量里
        p1=L_result[0];
        p2=L_result[1];
        p3=R_result[0];
        p4=R_result[1];
        delta_L=sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
        delta_R=sqrt(pow(p3.x-p4.x,2)+pow(p3.y-p4.y,2));
        
        //得到delta
        double delta=min(delta_L,delta_R);
        double midX=X[n/2].x;

        vector<Point> some;
            for(int i=0;i<n;i++){
                if(Y[i].x<midX+delta&&Y[i].x>midX-delta)
                    if(some.empty() || !(some.back() == Y[i]))
                        some.push_back(Y[i]);
            }

        double min_distance=delta;
        int index1=-1;
        int index2=-1;
       
        //开始比较异侧点
        int max=some.size();
        for(int i=0;i<max;i++){
            for(int j=i+1;j<max&&j<i+6;j++){//根据分析可知，这样的j不会超过6个
                if(abs(some[i].y-some[j].y)<=delta&&abs(some[j].x-some[i].x)<=delta)
                {
                    double newdistance=sqrt(pow(some[i].x-some[j].x,2)+pow(some[i].y-some[j].y,2));
                    if(newdistance<min_distance){
                        min_distance=newdistance;
                        index1=i;
                        index2=j;
                    }
                }
            }
        }
        if(index1!=-1&&index2!=-1){
            vector<Point> p;
            p.push_back(some[index1]);
            p.push_back(some[index2]);
            return p;
        }
        else if(delta_L<delta_R){
            return L_result;
        }
        else if(delta_L>=delta_R){
            return R_result;
        }
        else{
            printf("error,empty vector");
            return EMPTY;
        }
    }
}

//预处理后的分治法
vector<Point> DivideConquer(vector<Point>&X,vector<Point>&Y,int n){
    //递归出口
    if(n<=3) return MinDistance(X);
    else{
        //声明储存结果的几个变量
        double delta_L,delta_R;
        Point p1,p2,p3,p4;
        //构造函数需要的变量
        int mid=n/2;
        vector<Point> PXL=vector<Point>(X.begin(),X.begin()+mid);
        vector<Point> PXR=vector<Point>(X.begin()+mid,X.end());

      
        double midX = X[mid].x;
        vector<Point> PYL, PYR;

        for (int i = 0; i < n; i++) {
            if (Y[i].x<midX) {
                PYL.push_back(Y[i]);  // 如果 Y[i] 在 PXL 中，将其添加到 PYL
            } else {
                PYR.push_back(Y[i]);  // 否则添加到 PYR
            }
        }
        //递归
        vector<Point> L_result=DivideConquer(PXL,PYL,mid);
        vector<Point> R_result=DivideConquer(PXR,PYR,n-mid);
        
        //把结果放进变量里
        p1=L_result[0];
        p2=L_result[1];
        p3=R_result[0];
        p4=R_result[1];
        delta_L=sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
        delta_R=sqrt(pow(p3.x-p4.x,2)+pow(p3.y-p4.y,2));
        
        //得到delta
        double delta=min(delta_L,delta_R);
        

        vector<Point> some;
            for(int i=0;i<n;i++){
                if(Y[i].x<midX+delta&&Y[i].x>midX-delta)
                    if(some.empty() || !(some.back() == Y[i]))
                        some.push_back(Y[i]);
            }

        double min_distance=delta;
        int index1=-1;
        int index2=-1;
       
        //开始比较异侧点
        int max=some.size();
        for(int i=0;i<max;i++){
            for(int j=i+1;j<max&&j<i+6;j++){//根据分析可知，这样的j不会超过6个
                if(abs(some[i].y-some[j].y)<=delta&&abs(some[j].x-some[i].x)<=delta)
                {
                    double newdistance=sqrt(pow(some[i].x-some[j].x,2)+pow(some[i].y-some[j].y,2));
                    if(newdistance<min_distance){
                        min_distance=newdistance;
                        index1=i;
                        index2=j;
                    }
                }
            }
        }
        if(index1!=-1&&index2!=-1){
            vector<Point> p;
            p.push_back(some[index1]);
            p.push_back(some[index2]);
            return p;
        }
        else if(delta_L<delta_R){
            return L_result;
        }
        else if(delta_L>=delta_R){
            return R_result;
        }
        else{
            printf("error,empty vector");
            return EMPTY;
        }
    }
}

vector<Point> preprocessedDivideConquer(const vector<Point>&points,int n){
    vector<Point> X=quick_sort1(points);
    vector<Point> Y=quick_sort2(points);
    return DivideConquer(X,Y,n);
}