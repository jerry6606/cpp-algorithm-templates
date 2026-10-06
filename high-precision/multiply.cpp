// 高精度乘法（非负大整数，字符串）
// 场景：两个非负大整数相乘；先错位累加各位乘积，最后统一进位
// 复杂度：O(|a| * |b|)，额外空间 O(|a| + |b|)
// 易错点：进位要在乘积累加完后统一处理；任一乘数为 "0" 直接返回 "0"
// 验证：2026-10-06 用户同步代码（修复一处下标有符号比较警告），随机 300 组与 Python 大整数对拍通过
#include <bits/stdc++.h>
using namespace std;

string mp(string s1, string s2) {
    if (s1 == "0" || s2 == "0") return "0";
    int a = (int)s1.size();
    int b = (int)s2.size();
    vector<int> lis1, lis2;
    for (int i = a - 1; i >= 0; i--) {
        lis1.push_back(s1[i] - '0');
    }
    for (int i = b - 1; i >= 0; i--) {
        lis2.push_back(s2[i] - '0');
    }
    vector<int> lis3(a + b, 0);
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            lis3[i + j] += lis1[i] * lis2[j];
        }
    }
    for (int i = 0; i < a + b - 1; i++) {
        lis3[i + 1] += lis3[i] / 10;
        lis3[i] %= 10;
    }
    string res = "";
    int sz = (int)lis3.size();
    for (int i = 0; i < sz; i++) {
        res += char(lis3[i] + '0');
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
    cout << mp(s1, s2) << '\n';
    return 0;
}
