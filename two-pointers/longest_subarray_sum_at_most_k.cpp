/*
题目：和不超过 K 的最长子数组（正数数组）
描述：给定一个全部由正整数组成的数组和一个整数 K，请找出和小于等于 K 的连续子数组，并输出其中最长的长度。连续子数组是指数组中一段连续的元素。如果不存在和小于等于 K 的非空子数组（例如所有元素都大于 K），则最长长度为 0，程序也输出 0。
输入格式：
第一行包含整数 n 与 K，用空格分隔，n 表示数组长度，K 表示和的上限。
第二行包含 n 个整数，表示数组。保证数组元素全部为正整数。
输出格式：
输出一个整数，表示和不超过 K 的最长连续子数组的长度。
样例输入 1：
4 5
3 1 2 1
样例输出 1：
3
样例输入 2：
5 10
5 4 3 2 1
样例输出 2：
4
约束与提示：
- 本模板成立的前提是数组元素全部为正数：此时扩大右端只会让窗口和增大，缩小左端只会让窗口和减小，才能用滑动窗口。
- 如果数组中允许出现负数，窗口和不再具有这种单调性，不能直接套用本模板。
*/
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
