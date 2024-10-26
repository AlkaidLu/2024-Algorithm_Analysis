import time
import numpy as np
import matplotlib.pyplot as plt
from math import *

#输入
flag=1
while flag:
    
    tests = [int(s) for s in input("请输入测试问题规模").split()]
    flag=0
    for n in tests:
        if n <= 1:
            print("n的值必须大于1，请重新输入")
            flag=1
            break

flag2=1
while flag2:
    x_low = int(input("输入x坐标的下限"))
    x_high = int(input("输入x坐标的上限"))
    y_low = int(input("输入y坐标的下限"))
    y_high = int(input("输入y坐标的上限"))
    flag2=0
    if x_low >= x_high or y_low >= y_high:
        print("下限必须小于上限，请重新输入")
        flag2=1

#对每个问题规模随机生成n个边界范围内的随机点
def Random_Point(n,x_low,x_high,y_low,y_high):
    x_array =list(np.random.randint(low = x_low ,high = x_high,size = (n,)))
    y_array = list(np.random.randint(low = y_low ,high = y_high,size = (n,)))
    return x_array,y_array

#计算朴素两点间距离
def Distance(x1,x2,y1,y2):
    d =sqrt(pow(x1 - x2,2)+pow(y1 - y2,2))
    return d

#排序
def Y_Xsort(x_array,y_array):
    YX = zip(x_array,y_array)
    #根据x坐标排序  
    sorted_points = sorted(YX, key=lambda point: point[0])
    x_array1 = []
    y_array1  = []
    #将排序好的横纵坐标分别放入对应数组
    for point in sorted_points:
        x_array1.append(point[0])
        y_array1.append(point[1])
    return x_array1,y_array1

#朴素分治法计算最小距离；n为问题规模,x_array和y_array分别为横纵坐标数组
def MinDistance(points,x_array,y_array):
    #对于n=2和3时暴力求解
    n = len(points)
    if n == 2:
        return Distance(x_array[0],x_array[1],y_array[0],y_array[1])
    if n == 3:
        return min(Distance(x_array[0],x_array[1],y_array[0],y_array[1]),
                   Distance(x_array[0],x_array[2],y_array[0],y_array[2]),
                   Distance(x_array[1],x_array[2],y_array[1],y_array[2]),)
    # n大于3时，先排序，再划分
    if n > 3:
        x_array1, y_array1 = Y_Xsort(x_array, y_array)
        xL = x_array1[:floor(n / 2)]
        xR = x_array1[floor(n / 2):]
        yL = y_array1[:floor(n / 2)]
        yR = y_array1[floor(n / 2):]
        pointsL = list(zip(xL,yL))
        pointsR = list(zip(xR,yR))
        #左右最小距离
        Lmin = MinDistance(pointsL,xL,yL)
        Rmin = MinDistance(pointsR,xR,yR)

        Delt = min(Lmin, Rmin) 
        # 寻找在距离分界点左右Delt的点集
        xDeltL = []
        yDeltL = []
        for q in range(len(xL)):
            if abs(xL[len(xL) - q - 1] - xR[0]) <= Delt :
                xDeltL.append(xL[len(xL) - q - 1])
                yDeltL.append(yL[len(xL) - q - 1])
            else:
                break
        xDeltR = []
        yDeltR = []
        for m in range(len(xR)):
            if abs(xR[ m ] - xR[0]) <= Delt :
                xDeltR.append(xR[ m ])
                yDeltR.append(yR[ m ])
            else:
                break
        # 对上述找出的范围内的点集对y坐标排序
        x = xDeltL+xDeltR
        y = yDeltL+yDeltR        
        x1,y1 = Y_Xsort(y,x)
        # 对y坐标从左到右依次计算与右面两个的距离，取最小值
        for s in range(len(y1)-2):
            l1 = Distance(x1[s], x1[s+1], y1[s], y1[s+1])
            l2 = Distance(x1[s], x1[s+2], y1[s], y1[s+2])
            Delt = min(Delt, l1,l2) 
        # 判断倒数第二个点与最后一个点的距离      
        mindistance = min(Delt,Distance(x1[len(y1)-2], x1[len(y1)-1], y1[len(y1)-2], y1[len(y1)-1]))
        
        return mindistance



def distance2(x1, x2):  # 定义函数distance2计算预处理分治算法中两点间距离
    r = sqrt(pow(x1[1] - x2[1], 2) + pow(x1[0] - x2[0], 2))
    return r

#预处理的分治法
def MinDistance_plus(points,x_array,y_array):
    n = len(points)
    #对于n=2和3时暴力求解
    if n == 2:
        return Distance(x_array[0],x_array[1],y_array[0],y_array[1])
    if n == 3:
        return min(Distance(x_array[0],x_array[1],y_array[0],y_array[1]),
                   Distance(x_array[0],x_array[2],y_array[0],y_array[2]),
                   Distance(x_array[1],x_array[2],y_array[1],y_array[2]),)
    
    if n > 3:
        #拆分
        x_array1 = sorted(x_array)
        
        xL = x_array1[:floor(n/2)]
        xR = x_array1[floor(n/2):]
        yL=[]
        yR=[]
        PL=[]
        PR=[]
        for (x,y) in points:
            if x in xL:
                yL.append(y)
                PL.append((x,y))
            else:
                yR.append(y)
                PR.append((x,y))
        yL = sorted(yL)
        yR = sorted(yR)
          # 将原点集分成两个子集
        Lmin = MinDistance(PL,xL,yL)
        Rmin = MinDistance(PR,xR,yR)
        Delt = min(Lmin, Rmin)  # 不断用递归得到左右两点集的最小值
        xDeltL = []
        yDeltL = []
        for q in range(len(xL)):
            if abs(xL[len(xL) - q - 1] - xR[0]) <= Delt :
                xDeltL.append(xL[len(xL) - q - 1])
                yDeltL.append(yL[len(xL) - q - 1])
            else:
                break
        xDeltR = []
        yDeltR = []
        for m in range(len(xR)):
            if abs(xR[ m ] - xR[0]) <= Delt :
                xDeltR.append(xR[ m ])
                yDeltR.append(yR[ m ])
            else:
                break
        # 对上述找出的范围内的点集对y坐标排序
        x = xDeltL+xDeltR
        y = yDeltL+yDeltR        
        x1,y1 = Y_Xsort(y,x)
        # 对y坐标从左到右依次计算与右面两个的距离，取最小值
        for s in range(len(y1)-2):
            l1 = Distance(x1[s], x1[s+1], y1[s], y1[s+1])
            l2 = Distance(x1[s], x1[s+2], y1[s], y1[s+2])
            Delt = min(Delt, l1,l2) 
        # 判断倒数第二个点与最后一个点的距离      
        mindistance = min(Delt,Distance(x1[len(y1)-2], x1[len(y1)-1], y1[len(y1)-2], y1[len(y1)-1]))
        
        return mindistance




timings_divide_and_conquer = []
timings_preprocess_divide_and_conquer = []

#测试运行
calculate_std_dev_list = []
Average_list = []
x_axis = tests
#测试朴素分治法
for n in tests:
    time_list = []
    #每个测试集分别运行20次
    for j in range(20):
        start = time.perf_counter()
        x_array, y_array = Random_Point(n,x_low,x_high,y_low,y_high)
        points=list(zip(x_array,y_array))
        MinDistance(points,x_array, y_array)
        end = time.perf_counter()
        time_list.append((end-start))
    mean_time = np.mean(time_list)
    std_dev = np.std(time_list)
    timings_divide_and_conquer.append((mean_time, std_dev))




#测试预处理的分治法
for n in tests:
    time_list = []
    #每个测试集分别运行20次
    for j in range(20):
        start = time.perf_counter()    
        x_array, y_array = Random_Point(n,x_low,x_high,y_low,y_high)
        points=list(zip(x_array,y_array))
        MinDistance_plus(points,x_array,y_array)
        end = time.perf_counter()
        time_list.append((end-start))
    mean_time_plus = np.mean(time_list)
    std_dev_plus = np.std(time_list)
    timings_preprocess_divide_and_conquer.append((mean_time_plus, std_dev_plus))

plt.figure()
timings_non_process = np.array(timings_divide_and_conquer)
timings_process = np.array(timings_preprocess_divide_and_conquer)
plt.errorbar(tests, timings_non_process[:, 0], yerr=timings_non_process[:, 1], label='Nonprocessed', fmt='o-', capsize=5)
plt.errorbar(tests, timings_process[:, 0], yerr=timings_process[:, 1], label='Preprocessed', fmt='o-', capsize=5)
plt.xlabel('Number of Points')
plt.ylabel('Time taken')
plt.title('Comparison of Non Processed Divide and Conquer vs Preprocessed Divide and Conquer Algorithms')
plt.legend()
plt.xscale('log')
plt.yscale('log')
plt.show()
