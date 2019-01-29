/*
1024 科学计数法 （20 point(s)）
科学计数法是科学家用来表示很大或很小的数字的一种方便的方法，
其满足正则表达式 [+-][1-9].[0-9]+E[+-][0-9]+，
即数字的整数部分只有 1 位，小数部分至少有 1 位，
该数字及其指数部分的正负号即使对正数也必定明确给出。

现以科学计数法的格式给出实数 A，
请编写程序按普通数字表示法输出 A，并保证所有有效位都被保留。

输入格式：
每个输入包含 1 个测试用例，即一个以科学计数法表示的实数 A。
该数字的存储长度不超过 9999 字节，且其指数的绝对值不超过 9999。

输出格式：
对每个测试用例，在一行中按普通数字表示法输出 A，
并保证所有有效位都被保留，包括末尾的 0。

输入样例 1：
+1.23400E-03
输出样例 1：
0.00123400
输入样例 2：
-1.2E+10
输出样例 2：
-12000000000
*/

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    // freopen("data.txt", "r", stdin);
    string s, o, n, e;
    cin >> s;
    if (s[0] == '-')
        o += '-';
    int i = 1;
    while (s[i] != 'E')
    {
        n += s[i++];
    }
    i += 1;
    while (i < s.size())
    {
        e += s[i++];
    }
    if (e[0] == '-')
    {
        e.erase(0, 1);
        int x = stoi(e);
        if (x == 0)
        {
            o += n;
        }
        else
        {
            if (x > 0)
            {
                o += '0';
                o += '.';
            }
            while ((--x) > 0)
                o += '0';
            for (int i = 0; i < n.size(); i++)
            {
                if (n[i] == '.')
                    continue;
                o += n[i];
            }
        }
    }
    else
    {
        e.erase(0, 1);
        int x = stoi(e);
        o += n[0];
        int i = 2;
        while (x--)
        {
            if (i < n.size())
            {
                o += n[i];
                i++;
            }
            else
            {
                o += '0';
            }
        }
        if (i < n.size())
        {
            o += '.';
            for (; i < n.size(); i++)
            {
                o += n[i];
            }
        }
    }
    cout << o;
    return 0;
}