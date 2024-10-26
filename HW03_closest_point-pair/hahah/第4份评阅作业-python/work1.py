import random
import math 
import time

lenth = int(input('请输入一个数字，代表了点的数量，该数量大于2：'))
x_high, x_low, y_high,  y_low= map(float,input('请输入四个数字，分别代表x坐标的上、下限，y坐标的上、下限（用空格分隔）：').split())

if x_high <= x_low or y_high <= y_low or lenth <=2:
    print("请不要乱尝试数字！！！")
    exit(0)

xlist = []
ylist = []

def generate_random_points(x_l, x_h, y_l, y_h): ##生成随机数在xlist与ylist中，分别代表着所有的x坐标与y坐标
    for i in range(0,lenth,1):
        xlist.append( random.uniform(x_l, x_h))
        ylist.append( random.uniform(y_l, y_h))

def distance(i,j,x,y): ##计算i，j两点之间的距离的平方，最后在开根号
    return (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j])

def sort(num,x,y): ##进行排序操作，先依照x坐标大小排序，再按照y坐标排序
    for i in range(0,num,1):
        index = i
        for j in range(i+1,num,1):
            if x[j] < x[index] :
                index = j
            elif x[j] == x[index] and y[j] < y[index]:##当x坐标相等时，y坐标小的在前
                index = j
        x[i], x[index] = x[index], x[i]
        y[i], y[index] = y[index], y[i]
    
def baoli(number, x, y): ##暴力算法，观察结果是否正确
    if number == 2:
        return distance(0,1,x,y), [x[0],y[0]] , [x[1],y[1]]
    min1 = 10000
    index1 = 0
    index2 = 0
    for i in range(0,number,1):
        for j in range(0,number,1):
           dis = distance(i,j,x,y)
           if dis != 0 and dis < min1:
               min1 = dis
               index1=i
               index2=j
    return min1 ,[x[index1],y[index1]] , [x[index2],y[index2]]
    
def MinDistance1(number, x, y):#对未进行排序的点组列进行分治法操作
    min1 = 10000
    if number == 3:
        a = distance(0,1,x,y)
        b = distance(1,2,x,y)
        c = distance(0,2,x,y)
        min1 = min(a,b,c)
        if min1 == a:
            return min1, [x[0],y[0]] , [x[1],y[1]]
        if min1 == b:
            return min1, [x[1],y[1]] , [x[2],y[2]]
        if min1 == c:
            return min1, [x[0],y[0]] , [x[2],y[2]]
    elif number == 2:
        return distance(0,1,x,y), [x[0],y[0]] , [x[1],y[1]]
    
    sort(number,x,y)

    num = int(number/2)
    chui = (x[num]+x[num-1])/2
    
    b = MinDistance1( num, x[0:num], y[0:num])
    c = MinDistance1( number-num, x[num:], y[num:])

    min1 = min(b[0],c[0])
    xlimit = []
    ylimit = []
    lent = 0
    for i in range(0,number,1):
        if x[i] <= chui+min1 and x[i] >= chui-min1:
            xlimit.append(x[i])
            ylimit.append(y[i])
            lent += 1
    if lent == 1 or lent == 0:
        if min1 == b[0]:
            return min1, b[1], b[2]
        else:
            return min1, c[1], c[2]
    else:
        a = baoli(lent,xlimit,ylimit)
        min1 = min(min1,a[0])
        if min1 == a[0]:
            return min1, a[1] ,a[2]
        elif min1 == b[0]:
            return min1, b[1], b[2]
        elif min1 == c[0]:
            return min1, c[1], c[2]

def MinDistance2(number, x, y):##改良后的分治法
    min1 = 10000
    if number == 3:
        a = distance(0,1,x,y)
        b = distance(1,2,x,y)
        c = distance(0,2,x,y)
        min1 = min(a,b,c)
        if min1 == a:
            return min1, [x[0],y[0]] , [x[1],y[1]]
        if min1 == b:
            return min1, [x[1],y[1]] , [x[2],y[2]]
        if min1 == c:
            return min1, [x[0],y[0]] , [x[2],y[2]]
    elif number == 2:
        return distance(0,1,x,y), [x[0],y[0]] , [x[1],y[1]]
    
    num = int(number/2)
    chui = (x[num]+x[num-1])/2
    b = MinDistance2( num, x[0:num], y[0:num])
    c = MinDistance2( number-num, x[num:], y[num:])

    min1 = min(b[0],c[0])
    xlimit = []
    ylimit = []
    lent = 0
    for i in range(0,number,1):
        if x[i]<=chui+min1 and x[i] >= chui-min1:
            xlimit.append(x[i])
            ylimit.append(y[i])
            lent += 1
    if lent == 1 or lent == 0:
        if min1 == b[0]:
            return min1, b[1], b[2]
        else:
            return min1, c[1], c[2]
    else:
        a = baoli(lent,xlimit,ylimit)
        min1 = min(min1,a[0])
        if min1 == a[0]:
            return min1, a[1] ,a[2]
        elif min1 == b[0]:
            return min1, b[1], b[2]
        else:
            return min1, c[1], c[2]



generate_random_points(x_low, x_high, y_low, y_high)
#for i in range(0,lenth,1):
#   print('(',xlist[i],',',ylist[i],')\n')

start1 = time.perf_counter()
result1 = baoli(lenth,xlist,ylist)
end1 = time.perf_counter()

print("running time is: ", end1 - start1 ,', min-distance:',result1[0]**(1/2) , ',' ,result1[1], ',' ,result1[2],'\n')

start2 = time.perf_counter()
result2 = MinDistance1(lenth,xlist,ylist)
end2 = time.perf_counter()

print("running time is: ", end2 - start2 ,', min-distance:',result2[0]**(1/2) , ',' ,result2[1], ',' ,result2[2],'\n')

sort(lenth,xlist,ylist)
start3 = time.perf_counter()
result3 = MinDistance2(lenth,xlist,ylist)
end3 = time.perf_counter()

print("running time is: ", end3 - start3 ,', min-distance:',result3[0]**(1/2) , ',' ,result3[1], ',' ,result3[2],'\n')















