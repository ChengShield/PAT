/*
1021 个位数统计 （15 point(s)）
给定一个 k 位整数 N=d​_(k−1)​​*10^(​k−1)​​ +⋯+d​_1*10​^1​​ +d_​0​​  (0≤d_​i​​ ≤9, i=0,⋯,k−1, d_(​k−1)​​ >0)，
请编写程序统计每种不同的个位数字出现的次数。例如：给定 N=100311，则有 2 个 0，3 个 1，和 1 个 3。

输入格式：
每个输入包含 1 个测试用例，即一个不超过 1000 位的正整数 N。

输出格式：
对 N 中每一种不同的个位数字，以 D:M 的格式在一行中输出该位数字 D 及其在 N 中出现的次数 M。要求按 D 的升序输出。

输入样例：
100311
输出样例：
0:2
1:3
3:1
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    // freopen("data.txt", "r", stdin);
    string s;
    cin >> s;
    vector<int> v(10);
    for (auto c : s)
    {
        v[c - '0']++;
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > 0)
            cout << i << ':' << v[i] << endl;
    }
    return 0;
}