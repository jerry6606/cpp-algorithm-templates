/*
题目：最长连续不重复子序列
描述：给定一个整数序列，请找出其中最长的一段连续元素，使得这段元素互不重复，并输出这段的长度。这里的连续是指在原序列中相邻的一段，对应 AcWing 799 的题意。
输入格式：
第一行包含一个整数 n，表示序列长度。
第二行包含 n 个整数，表示给定序列。
输出格式：
输出一个整数，表示最长连续不重复段的长度。
样例输入 1：
5
1 2 2 3 5
样例输出 1：
3
样例输入 2：
6
1 1 2 3 4 5
样例输出 2：
5
约束与提示：
- 序列元素满足 0 <= a[i] <= 100000，程序按元素的值开计数数组（数组实际开到 1000006）；如果元素超出此范围或为负数，需要把计数改为哈希表等方式，不能直接套用。
- 本题用滑动窗口维护一段始终不含重复元素的区间，时间复杂度为 O(n)。
*/
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
