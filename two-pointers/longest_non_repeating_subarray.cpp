// 最长连续不重复子序列的长度（滑动窗口 + cnt 计数）
// 场景：元素值在 0..100000；right 入窗计数，某值计数 > 1 时从左端踢人直到不重复
// 复杂度：O(n)，额外空间 O(值域)
// 易错点：cnt 下标是元素值不是位置；踢人用 while 且踢的是左端 cnt[a[l]]--；值超范围先扩 cnt 或改 unordered_map
// 验证：2026-10-07 Day9 复测最终版（AcWing 799），判分包 9 组 + 性能探针 + 随机 200 组对拍通过
#include <bits/stdc++.h>
using namespace std;

const int MAXV = 1000006;
int cnt[MAXV];

int longestNonRepeatingSubarray(const vector<int>& a) {
    int maxlen = 0;
    for (int l = 0, r = 0; r < (int)a.size(); ++r) {
        cnt[a[r]]++;
        while (cnt[a[r]] > 1) {
            cnt[a[l]]--;
            ++l;
        }
        maxlen = max(maxlen, r - l + 1);
    }
    return maxlen;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    cout << longestNonRepeatingSubarray(a) << '\n';
    return 0;
}
