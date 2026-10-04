// 二维前缀和：静态矩阵多次子矩阵求和
// s[i][j] = (1,1)->(i,j) 子矩阵和
// 递推：s[i][j] = a[i][j] + s[i-1][j] + s[i][j-1] - s[i-1][j-1]
// 查询 (x1,y1)->(x2,y2)：s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1]
//   （容斥：大矩形减上条、减左条，左上角被减两次补一次）
// 复杂度：预处理 O(nm)，每次查询 O(1)
// 易错点：数组开 (n+1)x(m+1) 格，第 0 行/列哨兵；和用 long long
// 验证：2026-10-02 练习 100 分；2026-10-04 重做 100 分
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, q;
    if (!(cin >> n >> m >> q)) return 0;
    vector<vector<long long>> s(n + 1, vector<long long>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            long long a;
            cin >> a;
            s[i][j] = a + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1] << '\n';
    }
    return 0;
}
