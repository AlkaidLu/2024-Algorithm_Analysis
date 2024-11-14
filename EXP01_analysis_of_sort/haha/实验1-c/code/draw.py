import matplotlib.pyplot as plt
import numpy as np
from math import*

x_axis_data = [1000,5000,10000,20000,30000,50000,100000] #x
y_InsertSort = [1.35	,36.95	,196.7	,872	,2464.4	,6383.8	,23744.5] 
y_n=[(i**2/x_axis_data[3]**2)*y_InsertSort[3] for i in x_axis_data]
y_BubbleSort = [3.55	,97.1	,501.55	,2380.15	,6652.6	,18522.1	,66369.4]
y_n1=[(i**2/x_axis_data[3]**2)*y_BubbleSort[3] for i in x_axis_data]

x2=[1000,5000,10000,20000,30000,50000,100000,200000,500000,1000000,2000000,5000000]
y_ShellSort =np.array( [0.15	,1.2	,3.4	,8.15	,15.75	,30.15	,64.15,135.55	,342.55	,847.4	,2063.7	,5460.5])
y_n3=[(i**1.3/x2[5]**1.3)*y_ShellSort[5] for i in x2]
y_MergeSort = np.array([0.25	,1.75	,5.4	,13.4	,24.6	,43.65	,87.55,167.15	,383.6	,852.2	,1921.65	,4747.9])
y_n4=[(i*log2(i)/x2[5]/log2(x2[5]))*y_MergeSort[5] for i in x2]
y_QuickSort = np.array([0.05	,0.35	,1.35	,3.5	,6.95	,12.95	,25.45,54.05	,125.2	,297.5	,792.4	,2559.2])
y_n5=[(i*log2(i)/x2[5]/log2(x2[5]))*y_QuickSort[5] for i in x2]

y_QuickSort1=[0	,0	,0.9	,2.65	,7.5	,14.85	,27.45	,52.4	,126.8	,317.55	,828.85	,2487.8]
y_QuickSort2=[0	,0.95	,2.55	,5	,8.35	,14.85	,29.3	,59.15	,136.5	,314.65	,741.95	,2301.15]
y_QuickSortbook=[0	,0.8	,0.8	,3.2	,6.35	,17.25	,35.3	,74.2	,188.1	,494.55	,1387.7	,5450.85]
y_QuickSortHoare=[0,	0	,0.75	,3.1	,8.55	,14	,27.6	,55.7	,128.3	,276.4	,584	,1381.9]



plt.figure()
plt.plot(x_axis_data, y_InsertSort,label='InsertSort')
plt.plot(x_axis_data,y_n,label="InsertSort_theory")
plt.plot(x_axis_data,y_BubbleSort,label='BubbleSort')
plt.plot(x_axis_data,y_n1,label="BubbleSort_theory")
plt.plot(x_axis_data,y_ShellSort[:7],label='ShellSort')
plt.plot(x_axis_data,y_MergeSort[:7],label='MergeSort')
plt.plot(x_axis_data,y_QuickSort[:7],label='QuickSort')
plt.legend()
plt.title('comparison of several algorithms')
plt.xlabel('number') #x_label
plt.ylabel('time/s')#y_label


plt.figure()
plt.plot(x2,y_ShellSort,label='ShellSort')
plt.plot(x2,y_n3,label="ShellSort_theory")
plt.plot(x2,y_MergeSort,label='MergeSort')
plt.plot(x2,y_n4,label="MergeSort_theory")
plt.plot(x2,y_QuickSort,label='QuickSort')
plt.plot(x2,y_n5,label="QuickSort_theory")
plt.legend()  #显示上面的label
plt.xlabel('number') #x_label
plt.ylabel('time/ms')#y_label

 
plt.figure()
plt.plot(x2,y_QuickSort,label='QuickSort_first')
plt.plot(x2,y_QuickSort1,label='QuickSort_random')
plt.plot(x2,y_QuickSort2,label='QuickSort_mid3')
plt.legend()  #显示上面的label
plt.xlabel('number') #x_label
plt.ylabel('time/ms')#y_label


plt.figure()
plt.plot(x2,y_QuickSort,label='QuickSort')
plt.plot(x2,y_QuickSortbook,label='QuickSort_book')
plt.plot(x2,y_QuickSortHoare,label='QuickSort_Hoare')
plt.legend()  #
plt.title('Comparison of three quicksort algorithms')
plt.xlabel('number') #x_label
plt.ylabel('time/ms')#y_label


#plt.ylim(-1,1)#仅设置y轴坐标范围
plt.show()
