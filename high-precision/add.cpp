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
