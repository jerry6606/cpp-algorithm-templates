// 整数平方根：最大的 m 使 m*m <= n（0 <= n <= 1e18），二分答案
// 场景：二分答案入门、开方取整
// 复杂度：O(log n)
// 易错点：
//   1) mid*mid 溢出 long long，比较写成 mid <= n / mid
//   2) l 从 1 开始，避开 mid = 0 时 n / mid 除零；n = 0 时循环不进，靠 tar = 0 兜底
//   3) 比较式 = mid 处算出来的 vs 目标，两边一个不能错
// 验证：2026-10-02 Day5 复测 10 组全过（含 n = 0、1、1e18）
#include <bits/stdc++.h>
using namespace std;

long long isqrt(long long x) {
    long long l = 1, r = x;
    long long tar = 0;   // 答案保底：覆盖循环一次都不进的情况
    while (l <= r) {
        long long mid = l + (r - l) / 2;
        if (mid <= x / mid) {
            tar = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return tar;
}

int main() {
    long long n;
    if (!(cin >> n)) return 0;
    cout << isqrt(n) << '\n';
    return 0;
}
