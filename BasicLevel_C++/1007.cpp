/*
1007 素数对猜想 （20 point(s)）
让我们定义d​n​​ 为：d​_n​​ =p_​(n+1​​) −p_​n​​ ，其中p_​i​​ 是第i个素数。
显然有d_​1​​ =1，且对于n>1有d_​n​ 是偶数。
“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。
现给定任意正整数N(<10^​5)，请计算不超过N的满足猜想的素数对的个数。

输入格式:
输入在一行给出正整数N。

输出格式:
在一行中输出不超过N的满足猜想的素数对的个数。

输入样例:
20
输出样例:
4
*/

#include <iostream>
#include <string>
using namespace std;

bool isodd(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    freopen("data.txt", "r", stdin);
    int n;
    cin >> n;
    int pre = 2, count = 0;
    for (int i = 3; i <= n; i++)
    {
        if (isodd(i))
        {
            if (i - pre == 2)
            {
                count++;
            }
            pre = i;
        }
    }
    cout << count;
    return 0;
}