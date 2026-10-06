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
