/*
1013 数素数 （20 point(s)）
令 P​i​​  表示第 i 个素数。现任给两个正整数 M≤N≤10^​4​​ ，请输出 P​M​​  到 P​N​​  的所有素数。

输入格式：
输入在一行中给出 M 和 N，其间以空格分隔。

输出格式：
输出从 P​M​​  到 P​N​​  的所有素数，每 10 个数字占 1 行，其间以空格分隔，但行末不得有多余空格。

输入样例：
5 27
输出样例：
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isOdd(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    freopen("data.txt", "r", stdin);
    int min, max, count = 0;
    cin >> min >> max;
    vector<int> v;
    int i = 2;
    while (true)
    {
        if (isOdd(i))
        {
            count++;
            if (min <= count && count <= max)
                v.push_back(i);
            if (count > max)
                break;
        }
        i++;
    }
    for (int i = 0; i < v.size() - 1; i++)
    {
        cout << v[i];
        if (i % 10 == 9)
            cout << endl;
        else
            cout << ' ';
    }
    cout << v[v.size() - 1];
    return 0;
}