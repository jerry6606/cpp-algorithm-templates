/*
题目：判断子序列
描述：给定字符串 s 与字符串 t，判断 s 是否为 t 的子序列。子序列的定义是：从 t 中删去零个或若干个字符，并保持其余字符的相对顺序不变，如果能得到 s，则 s 是 t 的子序列。字符比较是区分大小写的精确匹配。
输入格式：
输入依次包含字符串 s 与字符串 t（先 s 后 t）。两个字符串均不含空格，可以用空格或换行分隔；按样例的写法，第一行是 s，第二行是 t。程序按先 s 后 t 的顺序读取。
输出格式：
如果 s 是 t 的子序列，输出 true；否则输出 false。输出为全小写，不要加引号。
样例输入 1：
abc
ahbgdc
样例输出 1：
true
样例输入 2：
axc
ahbgdc
样例输出 2：
false
约束与提示：
- 空字符串的情形无法通过本程序的输入方式给出，本题中 s 与 t 均为非空字符串。
- 本题用两个指针分别扫描 s 与 t，时间复杂度为 O(|t|)，其中 |t| 表示 t 的长度。
*/
// 判断 s 是否为 t 的子序列（分离双指针）
// 场景：两个字符串各放一个指针；匹配时两边都前进，不匹配时只前进 t 的指针
// 复杂度：O(|t|)，额外空间 O(1)
// 易错点：只有 s[i] == t[j] 时才推进 i；j 每轮都必须前进
// 验证：2026-10-06 Antigravity 同步实战（LeetCode 392 同型），8 组探针通过
#include <bits/stdc++.h>
using namespace std;

bool isSubsequence(const string& s, const string& t) {
    size_t i = 0, j = 0;
    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) ++i;
        ++j;
    }
    return i == s.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    if (!(cin >> s >> t)) return 0;
    cout << (isSubsequence(s, t) ? "true" : "false") << '\n';
    return 0;
}
