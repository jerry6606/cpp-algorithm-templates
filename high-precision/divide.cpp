// 高精度除法（非负大整数，输出商和余数，字符串）
// 场景：大整数除以大整数；逐位试商，每位用减法数出商的数字
// 复杂度：O(|a| * 商每位减法次数)，额外空间 O(|a|)
// 易错点：除数不能为 "0"；当前被除数片段 cur 每步只新带入一位，商每位必在 0..9 内
// 验证：2026-10-06 用户同步代码，随机 300 组商与余数和 Python 大整数对拍通过
#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b) {
    if (a.size() != b.size()) {
        return a.size() > b.size();
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

string chu(string a, string b, string &r) {
    int a1 = (int)a.size();
    int i = 0;
    string res;
    string cur;
    while (i < a1) {
        cur += a[i];
        i++;
        while (cur.size() > 1 && cur.front() == '0') {
            cur.erase(cur.begin());
        }
        int cnt = 0;
        while (cmp(cur, b)) {
            cur = jian(cur, b);
            cnt++;
        }
        res += char(cnt + '0');
    }
    while (res.size() > 1 && res.front() == '0') {
        res.erase(res.begin());
    }
    r = cur;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b, r;
    if (!(cin >> a >> b)) return 0;
    cout << chu(a, b, r) << '\n';
    cout << r << '\n';
    return 0;
}
