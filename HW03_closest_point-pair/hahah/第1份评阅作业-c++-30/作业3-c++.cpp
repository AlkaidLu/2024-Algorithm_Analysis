#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

int n; // 点的数量
double x_low, x_high, y_low, y_high, pusudis, predis; // 随机生成点的范围
vector<pair<double, double>> a; // 存储二维点对

// 按照 x 坐标进行排序的比较函数
bool cmp_x(pair<double,double> a, pair<double,double> b) {
    return a.first < b.first;
}

// 按照 y 坐标进行排序的比较函数
bool cmp_y(pair<double,double> a, pair<double,double> b) {
    return a.second < b.second;
}

// 按照 x 坐标为主，y 坐标为次的比较函数
bool cmp_xy(pair<double, double> a, pair<double, double> b) {
    if (a.first != b.first)
        return a.first < b.first;  // 先比较 x 坐标
    return a.second < b.second;    // 如果 x 坐标相等，比较 y 坐标
}

// 计算两个点之间的平方距离，避免了计算平方根以节省时间
double dist(pair<double,double> x, pair<double,double> y) {
    return (x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second);
}

// 随机生成 n 个点，范围为 [x_low, x_high] 和 [y_low, y_high]
vector<pair<double,double>> generateRandomNum(int n, double x_low, double x_high, double y_low, double y_high) {
    random_device rd;
    mt19937 gen(rd());  // 随机数生成器
    uniform_real_distribution<double> distx(x_low, x_high); // x 坐标的随机分布
    uniform_real_distribution<double> disty(y_low, y_high); // y 坐标的随机分布
    for (int i = 1; i <= n; i++) {
        a[i].first = distx(gen);  // 生成随机的 x 坐标
        a[i].second = disty(gen); // 生成随机的 y 坐标
    }
    return a;
}

// 暴力查找给定区间 [l, r] 中最近的点对距离
double forceFind(int l, int r) {
    double minn = 1e9;  // 初始化最小距离为一个非常大的数
    for (int i = l; i <= r; i++) {
        for (int j = i + 1; j <= r; j++) {
            if (dist(a[i], a[j]) < minn)
                minn = dist(a[i], a[j]);  // 更新最小距离
        }
    }
    return minn; // 返回最小距离
}

// 分治法查找最近点对，利用分而治之和归并的思想
double pusuFind(int l, int r) {
    if (r - l <= 3) // 当区间内点的数量较少时，使用暴力查找
        return forceFind(l, r);

    int mid = l + ((r - l) >> 1); // 计算中点
    pair<double, double> midPoint = a[mid]; // 获取中点的坐标
    double dis_l = pusuFind(l, mid);        // 递归查找左半部分最近点对
    double dis_r = pusuFind(mid + 1, r);    // 递归查找右半部分最近点对
    double dis = min(dis_l, dis_r);         // 找到左右部分中的最小距离

    // 归并阶段，检查横跨中点的点对是否有更小的距离
    vector<pair<double,double>> hebing;
    for (int i = l; i <= r; i++) {
        if (fabs(a[i].first - midPoint.first) < dis) // 将 x 坐标与中点接近的点加入
            hebing.push_back(a[i]);
    }
    // 对横跨中线的点按照 y 坐标排序
    sort(hebing.begin(), hebing.end(), cmp_y);

    // 检查这些点对的最小距离
    for (int i = 0; i < hebing.size(); i++) {
        for (int j = i + 1; j < hebing.size() && (hebing[j].second - hebing[i].second) < dis; j++) {
            if (dist(hebing[i], hebing[j]) < dis)
                dis = dist(hebing[i], hebing[j]);  // 更新最小距离
        }
    }
    pusudis=dis;
    return dis; // 返回找到的最小距离
}

// 分治法查找最近点对，带预处理步骤（假设有其他的预处理逻辑）
double preFind(int l, int r) {
    if (r - l <= 3) // 当区间内点的数量较少时，使用暴力查找
        return forceFind(l, r);

    int mid = l + ((r - l) >> 1); // 计算中点
    pair<double, double> midPoint = a[mid]; // 获取中点的坐标
    double dis_l = pusuFind(l, mid);        // 递归查找左半部分最近点对
    double dis_r = pusuFind(mid + 1, r);    // 递归查找右半部分最近点对
    double dis = min(dis_l, dis_r);         // 找到左右部分中的最小距离

    // 归并阶段，检查横跨中点的点对是否有更小的距离
    vector<pair<double,double>> hebing;
    for (int i = l; i <= r; i++) {
        if (abs(a[i].first - midPoint.first) < dis) // 将 x 坐标与中点接近的点加入
            hebing.push_back(a[i]);
    }

    // 检查这些点对的最小距离
    for (int i = 0; i < hebing.size(); i++) {
        for (int j = i + 1; j < hebing.size() && (hebing[j].second - hebing[i].second) < dis; j++) {
            if (dist(hebing[i], hebing[j]) < dis)
                dis = dist(hebing[i], hebing[j]);  // 更新最小距离
        }
    }
    predis =dis;
    return dis; // 返回找到的最小距离
}

int main() {
    cout<<"input n,x_low,x_high,y_low,y_high:";
    // 读取点的数量以及 x 和 y 的随机生成范围
    cin >> n >> x_low >> x_high >> y_low >> y_high;
    // 调整向量大小以容纳 n 个点
    a.resize(n + 1);

    // 生成随机点
    a = generateRandomNum(n, x_low, x_high, y_low, y_high);
    // 按 x 坐标排序后进行 pusuFind 查找
    sort(a.begin() + 1, a.begin() + n + 1, cmp_x);
    auto start = high_resolution_clock::now(); // 记录开始时间
    pusuFind(1, n);  // 执行 pusuFind 算法
    auto end = high_resolution_clock::now();   // 记录结束时间
    auto duration = duration_cast<microseconds>(end - start); // 计算运行时间
    cout << "pusuFind time taken:" << duration.count() / 1000.0 << "ms" << endl;
    cout << "Shortest distance:" << pusudis << endl;

    // 按 x 和 y 排序后进行 preFind 查找
    sort(a.begin() + 1, a.begin() + n + 1, cmp_xy);
    start = high_resolution_clock::now();  // 记录开始时间
    preFind(1, n);  // 执行 preFind 算法
    end = high_resolution_clock::now();    // 记录结束时间
    duration = duration_cast<microseconds>(end - start); // 计算运行时间
    cout << "preFind time taken:" << duration.count() / 1000.0 << "ms" << endl;
    cout << "Shortest distance:" << predis << endl;

    return 0;
}
