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
