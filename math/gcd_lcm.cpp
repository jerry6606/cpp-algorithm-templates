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
    cout << lcm(a, b) << '\n';
    return 0;
}
