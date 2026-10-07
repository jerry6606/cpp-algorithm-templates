/*
题目：快速排序
描述：给定一个整数序列，请将它按从小到大的顺序排序后输出。
输入格式：
第一行包含一个整数 n，表示序列长度。
第二行包含 n 个整数，表示待排序的序列。
输出格式：
输出一行，包含 n 个整数，用空格分隔，表示排序后的序列（升序）。
样例输入 1：
5
5 2 4 1 3
样例输出 1：
1 2 3 4 5
样例输入 2：
6
3 -1 3 0 -5 2
样例输出 2：
-5 -1 0 2 3 3
约束与提示：
- 序列中可以包含重复元素与负数。
- 本题要求用快速排序实现，不要直接调用排序函数代替算法本身；平均时间复杂度为 O(n log n)。
*/
// 快速排序（升序）
// 场景：原地排序；用中点值作分界，do-while 推进对撞指针，再递归左右两段
// 复杂度：平均 O(n log n)，最坏 O(n^2)，递归栈 O(log n)（平均）
// 易错点：以 j 划分时递归必须是 [l, j] 与 [j + 1, r]；分界值不要取到会与边界配错的端点
// 验证：2026-10-06 同步用户在 AcWing 学过的代码，随机探针与 std::sort 对拍通过
#include <bits/stdc++.h>
using namespace std;

void quick_sort(vector<int>& q, int l, int r) {
    if (l >= r) return;
    int i = l - 1, j = r + 1;
    int x = q[l + (r - l) / 2];
    while (i < j) {
        do ++i; while (q[i] < x);
        do --j; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> q(n);
    for (int i = 0; i < n; i++) cin >> q[i];

    if (n > 0) quick_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << q[i];
    }
    if (n) cout << '\n';
    return 0;
}
