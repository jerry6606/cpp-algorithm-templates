/*
题目：学生成绩排序
描述：有若干名学生，每名学生有一串学号以及语文、数学、英语三科成绩。总分定义为三科成绩之和。请按以下规则排序：先按总分从高到低；总分相同时，按语文成绩从高到低；前两项都相同时，按学号从小到大（学号按字符串的字典顺序比较）。排序后依次输出每名学生的学号与总分。
输入格式：
第一行包含一个整数 n，表示学生人数。
接下来 n 行，每行包含一个字符串与三个整数，用空格分隔，依次表示学号、语文成绩、数学成绩、英语成绩。学号是不含空格的字符串，可能含有前导 0，必须按字符串处理，不能按整数处理。
输出格式：
输出 n 行，每行包含一个字符串与一个整数，用空格分隔，依次表示学号与总分。按题目规定的顺序输出。
样例输入 1：
4
003 90 70 80
001 90 80 70
004 100 100 100
002 85 90 65
样例输出 1：
004 300
001 240
003 240
002 240
样例输入 2：
2
002 60 60 60
001 90 90 90
样例输出 2：
001 270
002 180
约束与提示：
- 排序中用到的只有总分、语文成绩与学号三项；数学与英语成绩只参与总分的计算，不单独参与比较。
- 比较时注意每一级的方向：总分与语文是降序，学号是升序，不要写反。
*/
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
