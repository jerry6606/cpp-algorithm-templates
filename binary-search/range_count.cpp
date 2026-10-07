/*
题目：统计落在区间内的元素个数
描述：给定一个升序数组和一个闭区间 [L, R]，统计数组中有多少个元素落在该区间内，即有多少个元素同时满足大于等于 L 且小于等于 R。
输入格式：
第一行包含一个整数 n，表示数组长度。
第二行包含 n 个整数，表示升序数组 a[0] 到 a[n-1]。
第三行包含整数 L 与 R，用空格分隔，表示查询区间 [L, R]，保证 L <= R。
输出格式：
输出一个整数，表示落在区间 [L, R] 内的元素个数。
样例输入 1：
7
1 2 3 3 3 5 8
3 5
样例输出 1：
4
样例输入 2：
7
1 2 3 3 3 5 8
4 4
样例输出 2：
0
约束与提示：
- 数组已按升序给出，程序分别二分找到第一个大于等于 L 的位置与最后一个小于等于 R 的位置，再用位置之差计数。
- 区间内没有元素时答案为 0。
- 时间复杂度为 O(log n)。
*/
// 统计升序数组中落在 [L, R] 内的元素个数（下标 0 起）
// 场景：区间计数；找第一个 >= L 与最后一个 <= R 的位置，再用位置差计数
// 复杂度：O(log n)
// 易错点：l、r 只表示下标，a[mid] 只和固定目标比较；找不到时第一个 >= L 返回 n、最后一个 <= R 返回 -1
// 验证：2026-10-06 Day8 区间计数，14 组探针通过
#include <bits/stdc++.h>
using namespace std;

int first_ge(const vector<long long>& a, long long x) {
    int l = 0, r = (int)a.size() - 1;
    int ans = (int)a.size();
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] >= x) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

int last_le(const vector<long long>& a, long long x) {
    int l = 0, r = (int)a.size() - 1;
    int ans = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] <= x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    long long L, R;
    cin >> L >> R;

    cout << last_le(a, R) - first_ge(a, L) + 1 << '\n';
    return 0;
}
