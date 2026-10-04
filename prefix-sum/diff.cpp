// 一维差分：多次区间加，最后输出整个数组
// d[i] = a[i] - a[i-1]；区间 [l, r] 加 v：d[l] += v，d[r+1] -= v；最后对 d 做前缀和还原
// 复杂度：每次修改 O(1)，还原 O(n)
// 易错点：d 开 n+2 格（r+1 最大到 n+1）；值与增量整条用 long long，别中间掉成 int；
//   只适合"改完再输出"，边改边查要用树状数组/线段树
// 验证：2026-10-04 练习 100 分（大数 4e9 压测过）
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<long long> a(n + 1, 0), d(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[i] = a[i] - a[i - 1];
    }
    while (q--) {
        int l, r;
        long long v;
        cin >> l >> r >> v;
        d[l] += v;
        d[r + 1] -= v;
    }
    long long cur = 0;
    for (int i = 1; i <= n; i++) {
        cur += d[i];
        cout << cur << ' ';
    }
    cout << '\n';
    return 0;
}
