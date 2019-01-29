/*
1006 换个格式输出整数 （15 point(s)）
让我们用字母 B 来表示“百”、字母 S 表示“十”，用 12...n 来表示不为零的个位数字 n（<10），换个格式来输出任一个不超过 3 位的正整数。例如 234 应该被输出为 BBSSS1234，因为它有 2 个“百”、3 个“十”、以及个位的 4。

输入格式：
每个测试输入包含 1 个测试用例，给出正整数 n（<1000）。

输出格式：
每个测试用例的输出占一行，用规定的格式输出 n。

输入样例 1：
234
输出样例 1：
BBSSS1234
输入样例 2：
23
输出样例 2：
SS123

Author: CHEN, Yue
Organization: 浙江大学
Time Limit: 400 ms
Memory Limit: 64 MB
Code Size Limit: 16 KB
*/

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    freopen("data.txt", "r", stdin);
    int n;
    cin >> n;
    int b = n / 100;
    for (int i = 0; i < b; i++)
    {
        cout << 'B';
    }
    n = n % 100;
    int s = n / 10;
    for (int i = 0; i < s; i++)
    {
        cout << 'S';
    }
    n = n % 10;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1;
    }
    return 0;
}