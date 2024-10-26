import random as rd
import math
from datetime import datetime


# 随机生成点
def genPoints(
    n: int, x_low: float, x_high: float, y_low: float, y_high: float, seed: int = 114514
) -> list[tuple[float, float]]:
    rd.seed(seed)
    answer = [(rd.uniform(x_low, x_high), rd.uniform(y_low, y_high)) for _ in range(n)]

    # 确保不存在两个点完全相同
    # 大概能确保吧, 假如这都不行那我就去买彩票
    if len(answer) == len(set(answer)):
        return answer
    else:
        return genPoints(n, x_low, x_high, y_low, y_high, seed * 1919810)


# 获取两点距离
def pointDistance(p1: tuple[float, float], p2: tuple[float, float]) -> float:
    x1, y1 = p1
    x2, y2 = p2
    return math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)


# 暴力穷举
def MinDistance_raw(
    P: list[tuple[float, float]], X: list[tuple[float, int]], Y: list[tuple[float, int]]
) -> tuple[tuple[float, float], tuple[float, float], float]:
    answer = (None, None, float("inf"))

    for p1 in P:
        for p2 in P:
            if p1 == p2:
                continue
            distance = pointDistance(p1, p2)
            if distance < answer[2]:
                answer = (p1, p2, distance)

    return answer


# 朴素的分治法
def MinDistance(
    P: list[tuple[float, float]], X: list[tuple[float, int]], Y: list[tuple[float, int]]
) -> tuple[tuple[float, float], tuple[float, float], float]:
    pointSize = len(P)
    # 点数小于3则直接计算
    if pointSize <= 3:
        return MinDistance_raw(P, None, None)
    else:
        # 列表P中的元素为元组，每个元组包含两个float
        # python对元组排序时默认按元组中元素的先后作为优先级
        # 因此直接使用默认排序即可保证以先x后y的优先级排序
        # 相当于排序x y
        P.sort()

        # 左右两部分大小尽可能相等
        l_part = P[: pointSize // 2]
        # lx = [p[0] for p in l_part]
        # ly = [p[1] for p in l_part]

        r_part = P[pointSize // 2 :]
        # rx = [p[0] for p in r_part]
        ry = [p[1] for p in r_part]

        # 由于分割条件是两部分数量相等, 分割点用两部分最接近的两个点的平均值模拟
        middle_coor = (
            (l_part[-1][0] + r_part[0][0]) / 2,
            (l_part[-1][1] + r_part[0][1]) / 2,
        )

        ans_l = MinDistance(l_part, None, None)
        ans_r = MinDistance(r_part, None, None)

        ans = min(ans_l, ans_r, key=lambda a: a[2])
        delta = ans[2]

        # 筛选出在delta范围内的点
        in_delta_l_part = [p for p in l_part if p[0] - middle_coor[0] < delta]
        in_delta_r_part = [p for p in r_part if p[0] - middle_coor[0] < delta]

        # 左侧的每个点
        for lp in in_delta_l_part:
            lpx, lpy = lp
            # 1. zip构造元组: (y与上述点y差的绝对值, 点座标)
            # 2. sorted排序: 按绝对值升序
            # 3. [:6]: 最多取前六个, 不足则有多少取多少
            r_nearest_most_6p = sorted(
                zip([abs(y - lpy) for y in ry], in_delta_r_part), key=lambda t: t[0]
            )[:6]
            for y_diff_abs, rp in r_nearest_most_6p:
                dis = pointDistance(lp, rp)
                if dis < ans[2]:
                    ans = (lp, rp, dis)

        return ans


# 由于需要拆分, x y座标列表必须携带点的索引
def MinDistance_Preprocessing(
    P: dict[int, tuple[float, float]],
    X: list[tuple[float, int]],
    Y: list[tuple[float, int]],
) -> tuple[tuple[float, float], tuple[float, float], float]:
    pointSize = len(P)
    # 点数小于3则直接计算
    if pointSize <= 3:
        return MinDistance_raw(P.values(), None, None)
    else:

        lx = X[: pointSize // 2]
        l_part = {i: P[i] for _, i in lx}
        ly = sorted([(P[i][1], i) for _, i in lx])

        rx = X[pointSize // 2 :]
        r_part = {i: P[i] for _, i in rx}
        ry = sorted([(P[i][1], i) for _, i in rx])

        # 由于分割条件是两部分数量相等, 分割点用两部分最接近的两个点的平均值模拟
        middle_coor = (
            (lx[-1][0] + rx[0][0]) / 2,
            (ly[-1][1] + ry[0][1]) / 2,
        )

        ans_l = MinDistance_Preprocessing(l_part, lx, ly)
        ans_r = MinDistance_Preprocessing(r_part, rx, ry)

        ans = min(ans_l, ans_r, key=lambda a: a[2])
        delta = ans[2]

        # 筛选出在delta范围内的点
        in_delta_l_part = [
            p for _, p in l_part.items() if p[0] - middle_coor[0] < delta
        ]
        in_delta_r_part = [
            p for _, p in r_part.items() if p[0] - middle_coor[0] < delta
        ]

        # 左侧的每个点
        for lp in in_delta_l_part:
            lpx, lpy = lp

            valid_rys = [idx for y, idx in ry if abs(y - lpy) < delta]
            valid_yp = [P[idx] for idx in valid_rys]

            for rp in valid_yp:
                dis = pointDistance(lp, rp)
                if dis < ans[2]:
                    ans = (lp, rp, dis)

        return ans


def main(n: int):
    p = genPoints(710, 1, 10, 1, 10)
    px = [(t[0], i) for i, t in enumerate(p)]
    py = [(t[1], i) for i, t in enumerate(p)]
    px.sort(key=lambda t: t[0])
    py.sort(key=lambda t: t[0])

    t1 = datetime.now()
    print(MinDistance_raw(p, None, None))
    t2 = datetime.now()
    print(MinDistance(p, None, None))
    t3 = datetime.now()
    print(
        MinDistance_Preprocessing({idx: point for idx, point in enumerate(p)}, px, py)
    )
    t4 = datetime.now()
    print(
        f"raw: {(t2 - t1).microseconds}ms\ndivide and conquer: {(t3 - t2).microseconds}ms\npreprocessing: {(t4 - t3).microseconds}ms\n"
    )


if __name__ == "__main__":
    for i in range(10, 700, 70):
        main(i)
