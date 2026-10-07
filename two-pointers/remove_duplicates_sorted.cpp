// 删除升序数组中的重复项，返回去重后的长度（快慢双指针，原地）
// 场景：数组已升序；slow 指向已保留的最后一个元素，fast 向右探路
// 复杂度：O(n)，额外空间 O(1)
// 易错点：不要用 INT_MIN 当哨兵（首元素为 INT_MIN 会漏）；下标与 size() 比较先转 int
// 验证：2026-10-07 Day9 最终版（LeetCode 26 同型），8 组探针 + 随机 300 组对拍通过
#include <bits/stdc++.h>
using namespace std;

int removeDuplicatesSorted(vector<int>& a) {
    if (a.empty()) return 0;
    int l = 0;
    int cnt = 1;
    for (int r = 1; r < (int)a.size(); ++r) {
        if (a[r] != a[l]) {
            ++l;
            a[l] = a[r];
            ++cnt;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int len = removeDuplicatesSorted(a);
    for (int i = 0; i < len; ++i) {
        if (i) cout << ' ';
        cout << a[i];
    }
    if (len) cout << '\n';
    return 0;
}
