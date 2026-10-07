/*
题目：第 k 小数（快速选择）
描述：给定一个整数序列和一个整数 k，请输出序列排序后（升序）的第 k 小数。k 从 1 开始计数，即 k = 1 表示最小值，k = n 表示最大值。本题不必把整个序列完整排序。
输入格式：
第一行包含整数 n 与 k，用空格分隔，n 表示序列长度，保证 1 <= k <= n。
第二行包含 n 个整数，表示给定序列。
输出格式：
输出一个整数，表示升序排序后的第 k 小数。
样例输入 1：
7 3
7 10 4 3 20 15 8
样例输出 1：
7
样例输入 2：
5 5
9 1 8 2 7
样例输出 2：
9
约束与提示：
- 序列中可以包含重复元素；重复元素在排序后各占一个位置，按排序后的位置计数。
- 本题用快速选择实现，每轮只处理包含答案的一侧，期望时间复杂度为 O(n)。
*/
// 快速选择：求升序排序后的第 k 小数（k 从 1 开始）
// 场景：只求第 k 小，不必完整排序；每轮划分后只递归包含答案的一侧
// 复杂度：期望 O(n)，最坏 O(n^2)，递归栈期望 O(log n)
// 易错点：进入右段时目标名次要改成 k - 左段长度；左段长度为 j - l + 1
// 验证：2026-10-06 同步用户在 AcWing 学过的代码，随机探针与排序结果对拍通过
#include <bits/stdc++.h>
using namespace std;

int quick_select(vector<int>& q, int l, int r, int k) {
    if (l == r) return q[l];
    int i = l - 1, j = r + 1;
    int x = q[l + (r - l) / 2];
    while (i < j) {
        do ++i; while (q[i] < x);
        do --j; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    int left_count = j - l + 1;
    if (k <= left_count) return quick_select(q, l, j, k);
    return quick_select(q, j + 1, r, k - left_count);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<int> q(n);
    for (int i = 0; i < n; i++) cin >> q[i];

    cout << quick_select(q, 0, n - 1, k) << '\n';
    return 0;
}
