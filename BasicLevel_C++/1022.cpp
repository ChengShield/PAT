/*
1022 D进制的A+B （20 point(s)）
输入两个非负 10 进制整数 A 和 B (≤2^​30​​ −1)，输出 A+B 的 D (1<D≤10)进制数。

输入格式：
输入在一行中依次给出 3 个整数 A、B 和 D。

输出格式：
输出 A+B 的 D 进制数。

输入样例：
123 456 8
输出样例：
1103
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    // freopen("data.txt", "r", stdin);
    long long a, b, d, c;
    cin >> a >> b >> d;
    c = a + b;
    if (c == 0)
    {
        cout << '0';
        return 0;
    }
    vector<int> v;
    while (c != 0)
    {
        v.push_back(c % d);
        c = c / d;
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[v.size() - 1 - i];
    }
    return 0;
}