/*
1010 一元多项式求导 （25 point(s)）
设计函数求一元多项式的导数。

输入格式:
以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过 1000 的整数）。数字间以空格分隔。

输出格式:
以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。注意“零多项式”的指数和系数都是 0，但是表示为 0 0。

输入样例:
3 4 -5 2 6 1 -2 0
输出样例:
12 3 -10 1 6 0
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    freopen("data.txt", "r", stdin);
    vector<int> v, s;
    int i;
    while (cin >> i)
    {
        v.push_back(i);
    }
    int k, n, k1, n1;
    for (int i = 0; i < v.size(); i += 2)
    {
        k = v[i];
        n = v[i + 1];
        k1 = k * n;
        if (n > 0)
            n1 = n - 1;
        else
            n1 = 0;
        if (i == 0 || k1 != 0)
        {
            s.push_back(k1);
            s.push_back(n1);
        }
    }
    for (int i = 0; i < s.size() - 1; i++)
    {
        cout << s[i] << ' ';
    }
    cout << s[s.size() - 1];
    return 0;
}