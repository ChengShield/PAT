/*
1018 锤子剪刀布 （20 point(s)）
大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：

FigCJB.jpg

现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。

输入格式：
输入第 1 行给出正整数 N（≤10^​5​​ ），即双方交锋的次数。随后 N 行，每行给出一次交锋的信息，
即甲、乙双方同时给出的的手势。C 代表“锤子”、J 代表“剪刀”、B 代表“布”，
第 1 个字母代表甲方，第 2 个代表乙方，中间有 1 个空格。

输出格式：
输出第 1、2 行分别给出甲、乙的胜、平、负次数，数字间以 1 个空格分隔。
第 3 行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有 1 个空格。
如果解不唯一，则输出按字母序最小的解。

输入样例：
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J
输出样例：
5 3 2
2 3 5
B B
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int cto3(char c)
{
    switch (c)
    {
    case 'B':
        return 0;
    case 'C':
        return 1;
    case 'J':
        return 2;
    default:
        break;
    }
    return -1;
}

char i3toc(int i)
{

    switch (i)
    {
    case 0:
        return 'B';
    case 1:
        return 'C';
    case 2:
        return 'J';
    default:
        return '\0';
        break;
    }
}

int judge(int a1, int a2)
{
    if (a1 == a2)
        return 0;
    else if ((a1 + 1) % 3 == a2)
        return 1;
    else
        return -1;
}

int main(int argc, char const *argv[])
{
    // freopen("data.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> v1(3), v2(3), s1(3), s2(3);
    char c1, c2;
    for (int i = 0; i < n; i++)
    {
        cin >> c1 >> c2;
        int r = judge(cto3(c1), cto3(c2));
        if (r < 0)
        {
            v1[2] += 1;
            v2[0] += 1;
            s2[cto3(c2)] += 1;
        }
        else if (r == 0)
        {
            v1[1] += 1;
            v2[1] += 1;
        }
        else
        {
            v1[0] += 1;
            v2[2] += 1;
            s1[cto3(c1)] += 1;
        }
    }
    for (int i = 0; i < v1.size(); i++)
    {
        if (i > 0)
        {
            cout << ' ';
        }
        cout << v1[i];
    }
    cout << endl;
    for (int i = 0; i < v2.size(); i++)
    {
        if (i > 0)
        {
            cout << ' ';
        }
        cout << v2[i];
    }
    cout << endl;
    int max1 = s1[0] >= s1[1] ? (s1[0] >= s1[2] ? 0 : 2) : (s1[1] >= s1[2] ? 1 : 2);
    int max2 = s2[0] >= s2[1] ? (s2[0] >= s2[2] ? 0 : 2) : (s2[1] >= s2[2] ? 1 : 2);
    cout << i3toc(max1) << ' ' << i3toc(max2);
    return 0;
}