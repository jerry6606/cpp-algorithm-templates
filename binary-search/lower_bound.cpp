// 第一个 >= x 的位置（升序数组，下标 0 起），不存在返回 -1
// 场景：左边界查找、手写 lower_bound
// 复杂度：O(log n)
// 易错点：比较式 = mid 处的值 vs 目标 x（右边写成 mid 就是错）；ans 先初始化 -1
// 验证：2026-09-30 Day3 重练一次通过
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    long long x;
    if (!(cin >> n >> x)) return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int l = 0, r = n - 1, ans = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] >= x) {   // 命中先记下，再往左收
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}
