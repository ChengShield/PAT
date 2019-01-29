/*
1030 完美数列 （25 point(s)）
给定一个正整数数列，和正整数 p，设这个数列中的最大值是 M，最小值是 m，如果 M≤mp，则称这个数列是完美数列。

现在给定参数 p 和一些正整数，请你从中选择尽可能多的数构成一个完美数列。

输入格式：
输入第一行给出两个正整数 N 和 p，其中 N（≤10^​5​​ ）是输入的正整数的个数，p（≤10^​9​​ ）是给定的参数。
第二行给出 N 个正整数，每个数不超过 10^​9​​ 。

输出格式：
在一行中输出最多可以选择多少个数可以用它们组成一个完美数列。

输入样例：
10 8
2 3 20 4 5 1 6 7 8 9
输出样例：
8
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int n;
    long long p;
    cin >> n >> p;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(begin(v), end(v));
    int result = 0; // , temp = 0;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + result; j < v.size(); j++)
        {
            if (v[j] <= v[i] * p)
            {
                result = j - i + 1;
            }
            else
            {
                break;
            }
        }
    }
    cout << result;
    return 0;
}