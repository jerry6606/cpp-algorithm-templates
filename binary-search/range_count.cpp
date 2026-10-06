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
