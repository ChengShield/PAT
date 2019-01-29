/*
1017 A除以B （20 point(s)）
本题要求计算 A/B，其中 A 是不超过 1000 位的正整数，B 是 1 位正整数。你需要输出商数 Q 和余数 R，使得 A=B×Q+R 成立。

输入格式：
输入在一行中依次给出 A 和 B，中间以 1 空格分隔。

输出格式：
在一行中依次输出 Q 和 R，中间以 1 空格分隔。

输入样例：
123456789050987654321 7
输出样例：
17636684150141093474 3
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    // freopen("data.txt", "r", stdin);
    string a;
    int b, r = 0, f = 0;
    cin >> a >> b;
    vector<int> v, q;
    for (auto c : a)
    {
        v.push_back(c - '0');
    }
    if (v[0] < b)
        f = 1;
    for (int i = 0; i < v.size(); i++)
    {
        int d = r * 10 + v[i];
        q.push_back(d / b);
        r = d % b;
    }
    bool flag = false;
    for (int i = f; i < q.size(); i++)
    {
        cout << q[i];
        flag = true;
    }
    if (flag == false)
    {
        cout << '0';
    }
    cout << ' ' << r;
    return 0;
}