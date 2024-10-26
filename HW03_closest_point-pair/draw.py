import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# 读取Excel文件
df = pd.read_excel('output.xlsx')

# 计算按点数量分组的平均时间和标准差
grouped = df.groupby('Points').agg({
    'Time Naive DC': ['mean', 'std'],
    'Time Preprocessed DC': ['mean', 'std']
}).reset_index()

# 提取各列
points = grouped['Points']
mean_naive_dc = grouped['Time Naive DC']['mean']
std_naive_dc = grouped['Time Naive DC']['std']
mean_preprocessed_dc = grouped['Time Preprocessed DC']['mean']
std_preprocessed_dc = grouped['Time Preprocessed DC']['std']

# 计算理论时间复杂度
# 选择合适的范围以确保与点数一致
n_values = np.array(points)
theoretical_preprocessed = (1/4)*n_values * np.log2(n_values)  # O(n log n)
theoretical_preprocessed_squared_log = (1/4)*n_values * (np.log2(n_values)**2)  # O(n (log n)^2)

# 绘制图像
plt.figure(figsize=(10, 6))

# 画两条折线图并加上标准差作为误差条
plt.errorbar(points, mean_naive_dc, yerr=std_naive_dc, fmt='-o', label='Naive Divide and Conquer', capsize=5)
plt.errorbar(points, mean_preprocessed_dc, yerr=std_preprocessed_dc, fmt='-s', label='Preprocessed Divide and Conquer', capsize=5)

# 绘制理论时间复杂度曲线
plt.plot(points, theoretical_preprocessed, 'g--', label='O(n log n)', linewidth=2)  # O(n log n) 理论曲线
plt.plot(points, theoretical_preprocessed_squared_log, 'm--', label='O(n (log n)^2)', linewidth=2)  # O(n (log n)^2) 理论曲线

# 设置图像的标题和轴标签
plt.title('Time vs. Points (with Standard Deviation)')
plt.xlabel('Number of Points')
plt.ylabel('Time')
plt.xscale('log')  # 如果你希望x轴按对数刻度显示，使用log刻度
plt.legend()

plt.savefig('output.png')  # 将图像保存为文件
# 显示图像
plt.show()
