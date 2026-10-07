/*
题目：高精度加法
描述：给定两个非负整数，请输出它们的和。这两个整数可能非常大，超出 64 位整数的表示范围，不能直接用普通整数类型存储与相加。整数以十进制字符串形式给出。
输入格式：
输入包含两个非负整数，分别占一行（也可以用空格分隔）。每个整数不含符号，不含空格；除整数 0 本身外，不含前导 0。
输出格式：
输出一个整数，表示两数之和。结果不含前导 0；和为 0 时输出 0。
样例输入 1：
123456789
987654321
样例输出 1：
1111111110
样例输入 2：
99999999999999999999
1
样例输出 2：
100000000000000000000
约束与提示：
- 两个加数可以长达数千位，程序按十进制逐位相加并处理进位，时间复杂度与较长加数的位数成正比。
- 输入均为非负数；带负号的情形不在本模板范围内。
*/
// 高精度加法（非负大整数，字符串）
// 场景：两个非负整数位数超出 long long 时，逐位相加并处理进位
// 复杂度：O(max(|a|, |b|))，额外空间 O(max(|a|, |b|))
// 易错点：结果先按低位到高位拼接，最后要 reverse；末尾多余的 0 要在 reverse 前去掉
// 验证：2026-10-06 用户同步代码，随机 300 组 + 边界组与 Python 大整数对拍通过
#include <bits/stdc++.h>
using namespace std;

string add(string s1, string s2) {
    int a = (int)s1.size() - 1;
    int b = (int)s2.size() - 1;
    int carry = 0;
    string res = "";
    while (a >= 0 || b >= 0 || carry) {
        int x = 0;
        int y = 0;
        if (a >= 0) {
            x = s1[a] - '0';
            a--;
        }
        if (b >= 0) {
            y = s2[b] - '0';
            b--;
        }
        int sum = x + y + carry;
        res += char(sum % 10 + '0');
        carry = sum / 10;
    }
    while (res.size() > 1 && res.back() == '0') {
        res.pop_back();
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    if (!(cin >> s1 >> s2)) return 0;
    cout << add(s1, s2) << '\n';
    return 0;
}
