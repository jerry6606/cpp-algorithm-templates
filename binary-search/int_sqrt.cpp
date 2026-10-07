/*
题目：整数平方根
描述：给定一个非负整数 n，求最大的整数 m，使得 m 的平方小于等于 n，也就是求 n 的算术平方根并向下取整。
输入格式：
一行包含一个整数 n。
输出格式：
输出一个整数 m，表示满足条件的最大值。
样例输入 1：
17
样例输出 1：
4
样例输入 2：
1000000000000000000
样例输出 2：
1000000000
约束与提示：
- 数据范围为 0 <= n <= 1e18，答案不超过 1e9。
- 直接计算 mid 的平方可能溢出，程序中改用 mid <= n / mid 的形式比较。
- 本题是二分答案的入门形式：在整数范围内二分候选答案。
*/
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
