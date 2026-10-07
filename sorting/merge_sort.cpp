/*
题目：归并排序
描述：给定一个整数序列，请将它按从小到大的顺序排序后输出。本题要求使用归并排序，归并排序是稳定的排序算法：值相等的元素在排序后保持原来的相对顺序。
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
- 本题要求用归并排序实现，时间复杂度为 O(n log n)，需要额外的辅助数组。
*/
// 归并排序（升序，稳定）
// 场景：需要稳定排序，或后续要扩展到逆序对统计；先递归排左右，再用分离双指针合并
// 复杂度：O(n log n)，额外空间 O(n)
// 易错点：合并时 q[i] <= q[j] 要先取左段以保持稳定；tmp 写回时下标必须与原区间对齐
// 验证：2026-10-06 同步用户在 AcWing 学过的代码，随机探针与 std::sort 对拍通过
#include <bits/stdc++.h>
using namespace std;

void merge_sort(vector<int>& q, vector<int>& tmp, int l, int r) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    merge_sort(q, tmp, l, mid);
    merge_sort(q, tmp, mid + 1, r);

    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) tmp[k++] = q[i++];
        else tmp[k++] = q[j++];
    }
    while (i <= mid) tmp[k++] = q[i++];
    while (j <= r) tmp[k++] = q[j++];
    for (int t = l; t <= r; t++) q[t] = tmp[t];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> q(n), tmp(n);
    for (int i = 0; i < n; i++) cin >> q[i];

    if (n > 0) merge_sort(q, tmp, 0, n - 1);
    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << q[i];
    }
    if (n) cout << '\n';
    return 0;
}
