// 和不超过 k 的最长连续子数组长度（滑动窗口，数组元素必须为正数）
// 场景：right 向右扩大窗口；窗口和 > k 时移动 left，直到重新合法；合法后更新长度
// 复杂度：O(n)，额外空间 O(1)
// 易错点：元素可为负数时窗口和没有单调性，不能直接套此模板；maxLen 初值为 0
// 验证：2026-10-06 Antigravity 同步实战最终版逻辑，8 组探针通过
#include <bits/stdc++.h>
using namespace std;

int longestSubarraySumAtMostK(const vector<int>& a, long long k) {
    int left = 0;
    int maxLen = 0;
    long long sum = 0;

    for (int right = 0; right < (int)a.size(); ++right) {
        sum += a[right];
        while (sum > k && left <= right) {
            sum -= a[left];
            ++left;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    if (!(cin >> n >> k)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << longestSubarraySumAtMostK(a, k) << '\n';
    return 0;
}
