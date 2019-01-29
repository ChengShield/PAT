/*
1016 部分A+B （15 point(s)）
正整数 A 的“D​A​​ （为 1 位整数）部分”定义为由 A 中所有 D​A​​  组成的新整数 P​A​​ 。
例如：给定 A=3862767，D​A​​ =6，则 A 的“6 部分”P​A​​  是 66，因为 A 中有 2 个 6。
现给定 A、D​A​​ 、B、D​B​​ ，请编写程序计算 P​A​​ +P​B​​ 。

输入格式：
输入在一行中依次给出 A、D​A​​ 、B、D​B​​ ，中间以空格分隔，其中 0<A,B<10^​10​​ 。

输出格式：
在一行中输出 P​A​​ +P​B​​  的值。

输入样例 1：
3862767 6 13530293 3
输出样例 1：
399
输入样例 2：
3862767 1 13530293 8
输出样例 2：
0
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    // freopen("data.txt", "r", stdin);
    string da, db, pa, pb;
    char a, b;
    cin >> da >> a >> db >> b;
    for (auto c : da)
    {
        if (c == a)
            pa += a;
    }
    for (auto d : db)
    {
        if (d == b)
            pb += b;
    }
    // cout << pa << " - " << pb << endl;
    int ia = pa.size() ? stoi(pa) : 0;
    int ib = pb.size() ? stoi(pb) : 0;
    cout << ia + ib;
    return 0;
}