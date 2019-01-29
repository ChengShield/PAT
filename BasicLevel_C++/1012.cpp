/*
1012 数字分类 （20 point(s)）
给定一系列正整数，请按要求对数字进行分类，并输出以下 5 个数字：

A​1​​  = 能被 5 整除的数字中所有偶数的和；
A​2​​  = 将被 5 除后余 1 的数字按给出顺序进行交错求和，即计算 n​1​​ −n​2​​ +n​3​​ −n​4​​ ⋯；
A​3​​  = 被 5 除后余 2 的数字的个数；
A​4​​  = 被 5 除后余 3 的数字的平均数，精确到小数点后 1 位；
A​5​​  = 被 5 除后余 4 的数字中最大数字。
输入格式：
每个输入包含 1 个测试用例。每个测试用例先给出一个不超过 1000 的正整数 N，随后给出 N 个不超过 1000 的待分类的正整数。数字间以空格分隔。

输出格式：
对给定的 N 个正整数，按题目要求计算 A​1​​ ~A​5​​  并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。

若其中某一类数字不存在，则在相应位置输出 N。

输入样例 1：
13 1 2 3 4 5 6 7 8 9 10 20 16 18
输出样例 1：
30 11 2 9.7 9
输入样例 2：
8 1 2 4 5 6 7 9 16
输出样例 2：
N 11 2 N 9
*/

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    freopen("data.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> v(5), a(5);
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        if (m % 5 == 0 && m % 2 == 0)
        {
            v[0] += m;
            a[0]++;
        }
        if (m % 5 == 1)
        {
            if (a[1] % 2 == 0)
                v[1] += m;
            else
                v[1] -= m;
            a[1]++;
        }
        if (m % 5 == 2)
        {
            v[2]++;
            a[2]++;
        }
        if (m % 5 == 3)
        {
            a[3]++;
            v[3] += m;
        }
        if (m % 5 == 4)
        {
            a[4]++;
            if (m > v[4])
                v[4] = m;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        if (i > 0)
            cout << ' ';
        if (a[i] == 0)
            cout << "N";
        else if (i == 3)
        {
            double x = v[i];
            x = x / a[3];
            cout.setf(ios::fixed);
            cout << setprecision(1) << x;
        }
        else
            cout << v[i];
    }
}