/*
题目：高精度减法
描述：给定两个非负整数 a 与 b，请输出 a - b 的结果。结果可能为负数，此时按通常写法在前面加负号。这两个整数可能非常大，超出 64 位整数的表示范围。整数以十进制字符串形式给出。
输入格式：
输入包含两个非负整数 a 与 b，分别占一行（也可以用空格分隔）。每个整数不含符号，不含空格；除整数 0 本身外，不含前导 0。
输出格式：
输出一个整数，表示 a - b。结果为负数时先输出负号再输出绝对值；结果不含前导 0；结果为 0 时输出 0，不要输出 -0。
样例输入 1：
1000
1
样例输出 1：
999
样例输入 2：
123
456
样例输出 2：
-333
约束与提示：
- 程序先比较 a 与 b 的大小，再用较大数减较小数逐位借位，最后根据比较结果决定是否加负号。
- 输入的 a 与 b 本身均为非负数，负号只出现在结果中。
*/
// 高精度减法（大整数，可为负，字符串）
// 场景：非负大整数相减，结果可为负；先比较大小再用大数减小数逐位借位
// 复杂度：O(max(|a|, |b|))，额外空间 O(max(|a|, |b|))
// 易错点：输入默认无前导零（"0" 除外）；借位 carry 跨位传递别漏
// 验证：2026-10-06 用户同步代码，随机 300 组（含负结果）与 Python 大整数对拍通过
#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b) {
    if (a.size() != b.size()) {
        return a.size() >= b.size();
    }
    return a >= b;
}

string jian(string a, string b) {
    int a1 = (int)a.size() - 1;
    int b1 = (int)b.size() - 1;
    int carry = 0;
    string res;
    while (a1 >= 0 || b1 >= 0) {
        int x = 0;
        int y = 0;
        if (a1 >= 0) {
            x = a[a1] - '0';
            a1--;
        }
        if (b1 >= 0) {
            y = b[b1] - '0';
            b1--;
        }
        x = x - carry;
        int sum;
        if (x < y) {
            x += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        sum = x - y;
        res += char(sum + '0');
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
    if (cmp(s1, s2)) {
        cout << jian(s1, s2) << '\n';
    } else {
        cout << "-" << jian(s2, s1) << '\n';
    }
    return 0;
}
