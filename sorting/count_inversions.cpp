/*
题目：逆序对数量
描述：给定一个整数序列，统计其中逆序对的数量。逆序对是指一对下标 i 与 j，满足 i 在 j 前面（i < j）且第 i 个元素大于第 j 个元素。这里的下标先后指元素在输入序列中的原始位置。
输入格式：
第一行包含一个整数 n，表示序列长度。
第二行包含 n 个整数，表示给定序列。
输出格式：
输出一个整数，表示逆序对的总数。
样例输入 1：
5
2 4 1 3 5
样例输出 1：
3
样例输入 2：
5
5 4 3 2 1
样例输出 2：
10
约束与提示：
- 值相等的两个元素不构成逆序对。
- 当序列完全逆序时逆序对数量达到 n(n-1)/2，可能很大，程序中使用 long long 存储。本题在归并排序的合并阶段顺带统计。
*/
// 归并排序求逆序对数量
// 场景：在归并合并阶段统计跨左右两段的逆序对；取右段元素时批量加上 mid - i + 1
// 复杂度：O(n log n)，额外空间 O(n)
// 易错点：答案可达 n*(n-1)/2，必须用 long long；只有 q[i] > q[j] 时才结算，相等不算逆序
// 验证：2026-10-06 同步用户在 AcWing 学过的代码，随机探针与暴力统计对拍、n=70000 全逆序通过
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL merge_count(vector<int>& q, vector<int>& tmp, int l, int r) {
    if (l >= r) return 0;
    int mid = l + (r - l) / 2;
    LL ans = merge_count(q, tmp, l, mid) + merge_count(q, tmp, mid + 1, r);

    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) {
            tmp[k++] = q[i++];
        } else {
            ans += mid - i + 1;
            tmp[k++] = q[j++];
        }
    }
    while (i <= mid) tmp[k++] = q[i++];
    while (j <= r) tmp[k++] = q[j++];
    for (int t = l; t <= r; t++) q[t] = tmp[t];
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> q(n), tmp(n);
    for (int i = 0; i < n; i++) cin >> q[i];

    LL ans = n > 0 ? merge_count(q, tmp, 0, n - 1) : 0;
    cout << ans << '\n';
    return 0;
}
