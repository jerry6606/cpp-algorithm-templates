/*
题目：最大公约数与最小公倍数
描述：给定两个正整数 a 与 b，请依次输出它们的最大公约数与最小公倍数。
输入格式：
一行包含整数 a 与 b，用空格分隔。
输出格式：
输出共两行：第一行是 a 与 b 的最大公约数，第二行是 a 与 b 的最小公倍数。
样例输入 1：
12 18
样例输出 1：
6
36
样例输入 2：
7 5
样例输出 2：
1
35
约束与提示：
- 数据范围为 1 <= a, b <= 1e9，最小公倍数可能达到 1e18 量级，程序中使用 long long 存储。
- 最小公倍数按 a 除以最大公约数再乘 b 的顺序计算（先除后乘），避免中间结果溢出。
- 修正说明：本文件原先的 main 只输出最小公倍数，与文件名和本题题意（同时求最大公约数与最小公倍数）不一致。本次已将 main 修正为先输出最大公约数、再输出最小公倍数（共两行），样例与说明均按修正后的输出核对。函数 gcd 与 lcm 本身未改动。
*/
// 最大公约数与最小公倍数（欧几里得算法）
// 场景：gcd 用辗转相除；lcm = a / gcd(a, b) * b，先除后乘防溢出
// 复杂度：O(log min(a, b))，额外空间 O(1)
// 易错点：lcm 必须先除后乘；用 long long 承接，int 在 a、b 到 1e6 量级就会溢出为负数
// 验证：2026-10-06 用户同步代码（int 升 long long 修复溢出），随机 200 组与 Python math.gcd 对拍通过
#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

long long lcm(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    return a / gcd(a, b) * b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b;
    if (!(cin >> a >> b)) return 0;
    cout << gcd(a, b) << '\n';
    cout << lcm(a, b) << '\n';
    return 0;
}
