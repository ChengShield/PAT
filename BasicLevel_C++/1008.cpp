/*
1008 数组元素循环右移问题 （20 point(s)）
一个数组A中存有N（>0）个整数，在不允许使用另外数组的前提下，将每个整数循环向右循环移动M位
（最后M个数循环移至最前面的M个位置）。如果需要考虑程序移动数据的次数尽量少，要如何设计移动的方法？

输入格式:
每个输入包含一个测试用例，第1行输入N（1≤N≤100）和M（≥0）；第2行输入N个整数，之间用空格分隔。

输出格式:
在一行中输出循环右移M位以后的整数序列，之间用空格分隔，序列结尾不能有多余空格。

输入样例:
6 2
1 2 3 4 5 6
输出样例:
5 6 1 2 3 4
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// void reverse(vector<int> &a, int low, int high)
// {
//     int mid = (low + high) / 2;
//     for (int i = low; i <= mid; i++, low++, high--)
//     {
//         int temp = a[low];
//         a[low] = a[high];
//         a[high] = temp;
//     }
// }

int main(int argc, char const *argv[])
{
    freopen("data.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    m %= n;
    if (m > 0)
    {
        reverse(begin(a), begin(a) + n);
        reverse(begin(a), begin(a) + m);
        reverse(begin(a) + m, begin(a) + n);
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
        if (i < n - 1)
            cout << ' ';
    }
    return 0;
}