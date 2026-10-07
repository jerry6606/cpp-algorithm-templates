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
