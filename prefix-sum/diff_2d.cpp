// 二维差分：多次子矩阵加，最后输出整个矩阵
// 子矩阵 (x1,y1)->(x2,y2) 加 v（四角）：
//   d[x1][y1] += v；d[x2+1][y1] -= v；d[x1][y2+1] -= v；d[x2+1][y2+1] += v
// 最后对 d 做二维前缀和还原
// 复杂度：每次修改 O(1)，还原 O(nm)
// 易错点：d 开 (n+2)x(m+2) 格（x2+1、y2+1 最大到 n+1、m+1）；四角符号别写错
// 验证：2026-10-04 练习 100 分（样例/右下角单格/q=0 全过）
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, q;
    if (!(cin >> n >> m >> q)) return 0;
    vector<vector<long long>> a(n + 1, vector<long long>(m + 1, 0));
    vector<vector<long long>> d(n + 2, vector<long long>(m + 2, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            d[i][j] = a[i][j] - a[i - 1][j] - a[i][j - 1] + a[i - 1][j - 1];
        }
    }
    while (q--) {
        int x1, y1, x2, y2;
        long long v;
        cin >> x1 >> y1 >> x2 >> y2 >> v;
        d[x1][y1] += v;
        d[x2 + 1][y1] -= v;
        d[x1][y2 + 1] -= v;
        d[x2 + 1][y2 + 1] += v;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = d[i][j] + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
