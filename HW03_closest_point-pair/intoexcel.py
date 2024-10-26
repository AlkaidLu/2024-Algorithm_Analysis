import re
import pandas as pd

# 正则表达式来匹配每一轮的数据
pattern = re.compile(
    r"In cycle (\d+\.\d+):[\s\S]*?"  # 用 [\s\S]*? 匹配任意字符，包括换行符
    r"There are (\d+) points[\s\S]*?"
    r"Time of naive Divide and Conquer is: (\d+)[\s\S]*?"
    r"Time of preprocessed Divide and Conquer is: (\d+)[\s\S]*?"
)

# 输入文本 (可以从文件或其他来源加载)
with open('results.txt', 'r') as file:
    data = file.read()

    # 用正则表达式找到所有匹配的部分
    matches = pattern.findall(data)

    if not matches:
        print("No matches found. Please check the input data format.")
    else:
        print(f"Found {len(matches)} matches.")

    # 将匹配结果放入一个列表中
    result = []
    for match in matches:
        cycle = float(match[0])
        points = int(match[1])
        time_naive_dc = int(match[2])
        time_preprocessed_dc = int(match[3])
        result.append([cycle, points, time_naive_dc, time_preprocessed_dc])

    # 创建 DataFrame
    df = pd.DataFrame(result, columns=['Cycle', 'Points', 'Time Naive DC', 'Time Preprocessed DC'])

    try:
        # 将 DataFrame 导出到 Excel
        df.to_excel('output.xlsx', index=False)
        print("Data successfully written to output.xlsx")
    except Exception as e:
        print(f"Failed to write to Excel: {e}")
