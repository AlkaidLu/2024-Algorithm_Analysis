import matplotlib.pyplot as plt
import numpy as np
def read_data(filename):
    data = {}
    with open(filename, 'r') as file:
        for line in file:
            # 提取排序算法、样本规模、比较次数、移动次数和时间信息
            parts = line.split('|')
            algorithm = parts[0].split('-')[0].strip()
            size = int(parts[0].split(':')[1].strip())
            comparisons = float(parts[1].split(':')[1].strip())
            moves = float(parts[2].split(':')[1].strip())
            time = float(parts[3].split(':')[1].replace('s', '').strip())
            
            if algorithm not in data:
                data[algorithm] = {'sizes': [], 'times': [], 'moves': [], 'comparisons': []}
            data[algorithm]['sizes'].append(size)
            data[algorithm]['times'].append(time)
            data[algorithm]['moves'].append(moves)
            data[algorithm]['comparisons'].append(comparisons)
    return data


def plot_data(data):
    fig, axes = plt.subplots(1, 3, figsize=(18, 6))
    
    for algorithm, values in data.items():
        sizes = np.array(values['sizes'])
    

        # 时间折线图
        axes[0].plot(sizes, values['times'], marker='o', label=algorithm)
        axes[0].set_xlabel('Sample Size')
        axes[0].set_ylabel('Time (seconds)')
        axes[0].set_title('Sorting Time Comparison')
        axes[0].legend()
        axes[0].grid(True)
        
        # 比较次数折线图
        axes[1].plot(sizes, values['comparisons'], marker='o', label=algorithm)
        axes[1].set_xlabel('Sample Size')
        axes[1].set_ylabel('Comparisons')
        axes[1].set_title('Sorting Comparisons Comparison')
        axes[1].legend()
        axes[1].grid(True)

        # 移动次数折线图
        axes[2].plot(sizes, values['moves'], marker='o', label=algorithm)
        axes[2].set_xlabel('Sample Size')
        axes[2].set_ylabel('Moves')
        axes[2].set_title('Sorting Moves Comparison')
        axes[2].legend()
        axes[2].grid(True)

    plt.tight_layout(pad=3.0)
    plt.show()

if __name__ == "__main__":
    # 使用你生成的txt文件路径
    filename = './sorting_results.txt'
    data = read_data(filename)
    plot_data(data)