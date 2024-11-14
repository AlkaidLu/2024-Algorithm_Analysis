import matplotlib.pyplot as plt

Algorithm = ['QuickSort', 'QuickSortRand','QuickSortThree','QuickSortKongXue', 'QuickSortHoare', 'QuickSortLomuto']
# 读取文件
def read_data(file_path):
    scales = []
    run_times, compare_counts, swap_counts = [], [], []
    for i in range(6):
        run_times.append([])
        compare_counts.append([])
        swap_counts.append([])
    with open(file_path, 'r') as file:
        while True:
            # 读取第一行作为横坐标
            line = file.readline().strip()  # 使用strip()去除可能存在的空格或换行符
            if not line:  # 如果第一行就是空行，则直接跳出
                return scales, run_times, compare_counts, swap_counts
            scales.append(int(line))
            # 读取每组数据
            for i in range(6):
                run_times[i].append(float(file.readline()))
                compare_counts[i].append(float(file.readline()))
                swap_counts[i].append(float(file.readline()))



def plot_data(scales, run_times, compare_counts, swap_counts):
    # 创建三个图形
    fig1, ax1 = plt.subplots(figsize=(10, 5))
    fig2, ax2 = plt.subplots(figsize=(10, 5))
    fig3, ax3 = plt.subplots(figsize=(10, 5))

    # 设置x轴为对数刻度
    ax1.set_xscale('log')
    ax2.set_xscale('log')
    ax3.set_xscale('log')

    # 绘制运行时间
    for i in range(6):
        ax1.scatter(scales, run_times[i], label=Algorithm[i])
        ax2.scatter(scales, compare_counts[i], label=Algorithm[i])
        ax3.scatter(scales, swap_counts[i], label=Algorithm[i])

    # 设置图例
    ax1.legend()
    ax2.legend()
    ax3.legend()

    # 设置图表标题和轴标签
    ax1.set_title('Run Times')
    ax1.set_xlabel('Scale (log)')
    ax1.set_ylabel('Time (s)')

    ax2.set_title('Compare Counts')
    ax2.set_xlabel('Scale (log)')
    ax2.set_ylabel('Count')

    ax3.set_title('Swap Counts')
    ax3.set_xlabel('Scale (log)')
    ax3.set_ylabel('Count')

    # 保存图表
    fig1.savefig('run_timesQuick.png')
    fig2.savefig('compare_countsQuick.png')
    fig3.savefig('swap_countsQuick.png')

    # 清除当前图形，避免重复绘制
    plt.clf()
    plt.close('all')

    

# 主函数
def main():
    file_path = 'outputQuick.txt'  # 替换为您的txt文件路径
    scales, run_times, compare_counts, swap_counts = read_data(file_path)
    plot_data(scales, run_times, compare_counts, swap_counts)

if __name__ == '__main__':
    main()
