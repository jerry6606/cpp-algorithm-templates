// 结构体多级排序（学生成绩）
// 场景：按总分降序、语文降序、学号升序三级比较；比较函数写全每一级
// 复杂度：O(n log n)，额外空间 O(n)（sort 本身 O(log n) 栈）
// 易错点：每一级方向别写反（降序用 >、升序用 <）；最后一级学号是字符串按字典序
// 验证：2026-10-06 用户同步代码（固定数组改 vector 防 n 越界），随机 200 组与 Python 排序对拍通过
#include <bits/stdc++.h>
using namespace std;

struct student {
    string id;
    int chinese, math, english;
    int total;
};

bool cmp(const student& a, const student& b) {
    if (a.total != b.total) return a.total > b.total;
    if (a.chinese != b.chinese) return a.chinese > b.chinese;
    return a.id < b.id;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<student> stu(n);
    for (int i = 0; i < n; i++) {
        cin >> stu[i].id >> stu[i].chinese >> stu[i].math >> stu[i].english;
        stu[i].total = stu[i].chinese + stu[i].english + stu[i].math;
    }
    sort(stu.begin(), stu.end(), cmp);
    for (int i = 0; i < n; i++) {
        cout << stu[i].id << " " << stu[i].total << '\n';
    }
    return 0;
}
