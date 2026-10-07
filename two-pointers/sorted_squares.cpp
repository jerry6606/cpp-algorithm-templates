/*
题目：有序数组的平方
描述：给定一个已按升序排列的整数数组，数组中可能含有负数。请把每个元素平方后，再把得到的结果按升序输出。
输入格式：
第一行包含一个整数 n，表示数组长度。
第二行包含 n 个整数，表示已升序排列的数组。
输出格式：
输出一行，包含 n 个整数，用空格分隔，表示平方后并按升序排列的结果。
样例输入 1：
5
-4 -1 0 3 10
样例输出 1：
0 1 9 16 100
样例输入 2：
5
-7 -3 2 3 11
样例输出 2：
4 9 9 49 121
约束与提示：
- 数组元素范围满足 -10000 <= a[i] <= 10000，因此平方结果不超过 1e8，在 int 范围内。超出此范围时 int 平方会溢出，需要改用更大的整数类型。
- 由于负数的平方可能很大，平方后的最大值必然出现在原数组的两端，程序从两端向中间比较并从后向前填写结果。
*/
// 有序数组每个元素平方后按升序输出（对撞双指针）
// 场景：数组已升序且含负数；平方最大值必在两端，从后往前填结果
// 复杂度：O(n)，额外空间 O(n)（结果数组）
// 易错点：写进结果的是平方值不是原数；下标与 size() 比较先转 int
// 验证：2026-10-07 Day9 最终版（LeetCode 977 同型），8 组探针 + 随机 300 组对拍通过
#include <bits/stdc++.h>
using namespace std;

vector<int> sortedSquares(const vector<int>& a) {
    int n = (int)a.size();
    vector<int> res(n);
    int l = 0, r = n - 1, k = n - 1;
    while (l <= r) {
        int ll = a[l] * a[l];
        int rr = a[r] * a[r];
        if (ll < rr) {
            res[k] = rr;
            --r;
        } else {
            res[k] = ll;
            ++l;
        }
        --k;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int> res = sortedSquares(a);
    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << res[i];
    }
    cout << '\n';
    return 0;
}
