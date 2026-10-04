// 一维前缀异或：静态数组多次区间异或
// s[i] = a[1]^a[2]^...^a[i]；区间 [l, r] 异或 = s[r] ^ s[l-1]（异或的逆运算是它自己）
// 复杂度：预处理 O(n)，每次查询 O(1)
// 易错点：构造和查询的运算符必须配套（都用 ^，不能一个 ^ 一个 -）；数组开 n+1 格
// 验证：2026-10-02 重做 100 分（含 l>1 区间）
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<int> s(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        s[i] = s[i - 1] ^ a;
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << (s[r] ^ s[l - 1]) << '\n';
    }
    return 0;
}
