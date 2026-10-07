/*
题目：删除有序数组中的重复项
描述：给定一个已按升序排列的整数数组，请删去其中的重复元素，使每个不同的值只保留一个，并保持原有相对顺序，然后输出去重后的数组。注意：本题程序输出的是去重后的数组本身，而不是只输出长度。
输入格式：
第一行包含一个整数 n，表示数组长度。
第二行包含 n 个整数，表示已升序排列的数组。
输出格式：
输出一行，包含去重后的全部元素，用空格分隔。如果 n = 0，则输出为空（程序不输出任何内容）。样例均取 n >= 1 的情形。
样例输入 1：
10
0 0 1 1 1 2 2 3 3 4
样例输出 1：
0 1 2 3 4
样例输入 2：
3
1 1 2
样例输出 2：
1 2
约束与提示：
- 数组已按升序给出，相同的值必然相邻，因此只需与已保留的最后一个元素比较即可判断是否重复。
- 程序在原数组上原地去重，额外空间为 O(1)。
*/
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
