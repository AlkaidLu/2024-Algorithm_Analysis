
import random
import time
import matplotlib.pyplot as plt
import numpy as np

def generate_points(n, x_low, x_high, y_low, y_high):
    return [(random.uniform(x_low, x_high), random.uniform(y_low, y_high)) for _ in range(n)]
#计算欧几里得距离
def distance(p1, p2):
    return ((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2) ** 0.5

def simpleDac(points):
    min_dist = float('inf')

    #点的数量小于等于3时暴力计算
    if len(points) <= 3:
        for i in range(len(points)):
            for j in range(i + 1, len(points)):
                min_dist = min(min_dist, distance(points[i], points[j]))
        return min_dist

    #按照X坐标对点进行排序
    points = sorted(points, key=lambda x: x[0])

    mid = len(points) // 2
    left_points = points[:mid]
    right_points = points[mid:]

    # 递归地在左半和右半计算最小距离
    left_min_dist = simpleDac(left_points)
    right_min_dist = simpleDac(right_points)

    #当前最小距离为左右两部分的最小值，并计算中间线坐标
    min_dist = min(left_min_dist, right_min_dist)
    mid_line = (points[mid-1][0] + points[mid][0]) / 2



    # 筛选出横跨mid_line且横坐标差小于min_dist的点
    # 按照Y坐标对mid_points进行排序
    mid_points = [point for point in points if abs(point[0] - mid_line) < min_dist]
    
    mid_points = sorted(mid_points, key=lambda x: x[1])
    for i in range(len(mid_points)):
        for j in range(i + 1, min(i + 8, len(mid_points))):
            min_dist = min(min_dist, distance(mid_points[i], mid_points[j]))

    return min_dist

def preprocessedDac(points):
    min_dist = float('inf')

    if len(points) <= 3:
        for i in range(len(points)):
            for j in range(i + 1, len(points)):
                min_dist = min(min_dist, distance(points[i], points[j]))
        return min_dist

    
    points = sorted(points, key=lambda x: x[0])# 对点集按X坐标进行排序
    return preMindist(points)


def preMindist(points):
    min_dist = float('inf')

    if len(points) <= 3:
        for i in range(len(points)):
            for j in range(i + 1, len(points)):
                min_dist = min(min_dist, distance(points[i], points[j]))
        return min_dist

    # mid: 中间点的索引
    mid = len(points) // 2
    left_points = points[:mid]
    right_points = points[mid:]
    mid_line = (points[mid-1][0] + points[mid][0]) / 2


    # 筛选出横跨mid_line且横坐标差小于左右中点差的点
    # 按照Y坐标对mid_points进行排序
    mid_points = [point for point in points if abs(point[0] - mid_line) < points[mid][0] - points[mid-1][0]]
    mid_points = sorted(mid_points, key=lambda x: x[1])

    #递归计算距离
    left_min_dist = preMindist(left_points)
    right_min_dist = preMindist(right_points)


    min_dist = min(left_min_dist, right_min_dist)
    for i in range(len(mid_points)):
        for j in range(i + 1, min(i + 8, len(mid_points))):
            min_dist = min(min_dist, distance(mid_points[i], mid_points[j]))

    return min_dist

def runTime(func, points):
    start_time = time.time()  # 记录开始时间
    func(points)  # 调用函数
    # 结束时间减去开始时间得到运行时间
    return time.time() - start_time

def main():
    # 不同样本数量的测试
    n_values = [1000, 2000, 5000, 10000, 50000, 100000]
    num_tests = 10  # 每个样本的规模实例数量

    simpleTimes = []  # 存储朴素分治法的平均运行时间
    preTimes = []  # 存储预处理分治法的平均运行时间

    for n in n_values:
        naive_total_time = 0  # 朴素分治法总时间
        preprocessed_total_time = 0  # 预处理分治法总时间

        # 对当前样本数量进行多次测试
        for _ in range(num_tests):
            points = generate_points(n, 0, 1000, 0, 1000)  # 生成随机点

            # 计算朴素分治法的运行时间
            naive_time = runTime(simpleDac, points)
            # 计算预处理分治法的运行时间
            preprocessed_time = runTime(preprocessedDac, points)

            naive_total_time += naive_time
            preprocessed_total_time += preprocessed_time

        # 计算平均运行时间
        naive_average_time = naive_total_time / num_tests
        preAveTime = preprocessed_total_time / num_tests
        print(f"当前点个数{n};\n朴素分治：{naive_average_time}，预处理分治：{preAveTime}")
        simpleTimes.append(naive_average_time)
        preTimes.append(preAveTime)
    
    #利用matplotlib库绘制图像
    plt.plot(n_values, simpleTimes, label='Naive')
    plt.plot(n_values, preTimes, label='Preprocessed')

    naive_std = np.std(simpleTimes)
    preprocessed_std = np.std(preTimes)
    plt.fill_between(n_values, np.array(simpleTimes) - 3 * naive_std, np.array(simpleTimes) + 3 * naive_std, color='lightblue')
    plt.fill_between(n_values, np.array(preTimes) - 3 * preprocessed_std, np.array(preTimes) + 3 * preprocessed_std, color='orange')
    plt.errorbar(n_values, simpleTimes, yerr=naive_std, fmt='o', capsize=5, label='Naive')
    plt.errorbar(n_values, preTimes, yerr=preprocessed_std, fmt='o', capsize=5, label='Preprocessed')

    plt.xlabel('样例点个数')  
    plt.ylabel('平均运行时间 (s)')  
    plt.legend()  
    plt.show() 

if __name__ == '__main__':
    main() 
