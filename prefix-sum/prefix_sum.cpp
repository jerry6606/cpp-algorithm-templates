// 一维前缀和：静态数组多次区间求和
// s[i] = 前 i 个数之和（s[0] = 0 哨兵）；区间 [l, r] 和 = s[r] - s[l-1]
// 复杂度：预处理 O(n)，每次查询 O(1)
// 易错点：下标从 1 起，数组开 n+1 格；和用 long long；数组会改就不能用这个
// 验证：2026-10-01 练习 1 一次 100 分（样例/单格/负数/大数全过）
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<long long> s(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        s[i] = s[i - 1] + x;
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << s[r] - s[l - 1] << '\n';
    }
    return 0;
}
