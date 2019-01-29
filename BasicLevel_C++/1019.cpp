/*
1019 数字黑洞 （20 point(s)）
给定任一个各位数字不完全相同的 4 位正整数，如果我们先把 4 个数字按非递增排序，再按非递减排序，
然后用第 1 个数字减第 2 个数字，将得到一个新的数字。
一直重复这样做，我们很快会停在有“数字黑洞”之称的 6174，这个神奇的数字也叫 Kaprekar 常数。

例如，我们从6767开始，将得到

7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
7641 - 1467 = 6174
... ...
现给定任意 4 位正整数，请编写程序演示到达黑洞的过程。

输入格式：
输入给出一个 (0,10^​4​​ ) 区间内的正整数 N。

输出格式：
如果 N 的 4 位数字全相等，则在一行内输出 N - N = 0000；
否则将计算的每一步在一行内输出，直到 6174 作为差出现，输出格式见样例。
注意每个数字按 4 位数格式输出。

输入样例 1：
6767
输出样例 1：
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174

输入样例 2：
2222
输出样例 2：
2222 - 2222 = 0000
*/

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int cmp1(int a, int b)
{
    return a > b;
}

int cmp2(int a, int b)
{
    return a < b;
}

int vtoi(vector<int> v)
{
    return v[0] * 1000 + v[1] * 100 + v[2] * 10 + v[3];
}

void itov(int x, vector<int> &v)
{
    int d = 1000;
    for (int i = 0; i < 4; i++)
    {
        v[i] = x / d;
        x %= d;
        d /= 10;
    }
}

int main(int argc, char const *argv[])
{
    // freopen("data.txt", "r", stdin);
    string s;
    cin >> s;
    vector<int> v;
    for (int i = 0; i < 4 - s.size(); i++)
        v.push_back(0);
    for (int i = 0; i < s.size(); i++)
        v.push_back(s[i] - '0');
    int a1, a2, b;
    do
    {
        sort(begin(v), end(v), cmp1);
        a1 = vtoi(v);
        sort(begin(v), end(v), cmp2);
        a2 = vtoi(v);
        b = a1 - a2;
        cout << setfill('0') << setw(4) << a1 << " - " << setfill('0') << setw(4) << a2;
        cout << " = " << setfill('0') << setw(4) << b << endl;
        itov(b, v);
    } while (b != 0 && b != 6174);

    return 0;
}