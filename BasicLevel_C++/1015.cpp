/*
1015 德才论 （25 point(s)）
宋代史学家司马光在《资治通鉴》中有一段著名的“德才论”：“是故才德全尽谓之圣人，才德兼亡谓之愚人，
德胜才谓之君子，才胜德谓之小人。凡取人之术，苟不得圣人，君子而与之，与其得小人，不若得愚人。”

现给出一批考生的德才分数，请根据司马光的理论给出录取排名。

输入格式：
输入第一行给出 3 个正整数，分别为：
N（≤10^​5​​ ），即考生总数；
L（≥60），为录取最低分数线，即德分和才分均不低于 L 的考生才有资格被考虑录取；
H（<100），为优先录取线——德分和才分均不低于此线的被定义为“才德全尽”，此类考生按德才总分从高到低排序；
才分不到但德分到线的一类考生属于“德胜才”，也按总分排序，但排在第一类考生之后；
德才分均低于 H，但是德分不低于才分的考生属于“才德兼亡”但尚有“德胜才”者，按总分排序，但排在第二类考生之后；
其他达到最低线 L 的考生也按总分排序，但排在第三类考生之后。

随后 N 行，每行给出一位考生的信息，包括：准考证号 德分 才分，
其中准考证号为 8 位整数，德才分为区间 [0, 100] 内的整数。数字间以空格分隔。

输出格式：
输出第一行首先给出达到最低分数线的考生人数 M，随后 M 行，每行按照输入格式输出一位考生的信息，
考生按输入中说明的规则从高到低排序。当某类考生中有多人总分相同时，按其德分降序排列；若德分也并列，则按准考证号的升序输出。

输入样例：
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60
输出样例：
12
10000013 90 99
10000012 80 100
10000003 85 80
10000011 85 80
10000004 80 85
10000007 90 78
10000006 83 76
10000005 82 77
10000002 90 60
10000014 66 60
10000008 75 79
10000001 64 90
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct stu
{
    int index;
    int merit;
    int talent;
    int total;
    stu() {}
    stu(int in, int me, int ta, int to) : index(in), merit(me), talent(ta), total(to)
    {
    }
};

int cmp(stu s1, stu s2)
{
    if (s1.total == s2.total)
    {
        if (s1.merit == s2.merit)
            return s1.index < s2.index;
        else
            return s1.merit > s2.merit;
    }
    else
    {
        return s1.total > s2.total;
    }
}

int main(int argc, char const *argv[])
{
    // freopen("data.txt", "r", stdin);
    int n, min, pri;
    scanf("%d %d %d", &n, &min, &pri);
    // cin >> n >> min >> pri;
    vector<stu> v[4];
    int index, merit, talent, total;
    int num = 0;
    // stu s;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &index, &merit, &talent);
        // cin >> s.index >> s.merit >> s.talent;
        if (merit < min || talent < min)
            continue;
        total = merit + talent;
        stu s(index, merit, talent, total);
        if (s.merit >= pri && s.talent >= pri)
            v[0].push_back(s);
        else if (s.merit >= pri)
            v[1].push_back(s);
        else if (s.merit >= s.talent)
            v[2].push_back(s);
        else
            v[3].push_back(s);
        num++;
    }
    cout << num << endl;
    for (int i = 0; i < 4; i++)
    {
        sort(begin(v[i]), end(v[i]), cmp);
        for (auto c : v[i])
            cout << c.index << ' ' << c.merit << ' ' << c.talent << endl;
    }
    return 0;
}