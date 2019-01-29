/*
1033 旧键盘打字 （20 point(s)）
旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。
现在给出应该输入的一段文字、以及坏掉的那些键，打出的结果文字会是怎样？

输入格式：
输入在 2 行中分别给出坏掉的那些键、以及应该输入的文字。
其中对应英文字母的坏键以大写给出；每段文字是不超过 10^​5 个字符的串。
可用的字符包括字母 [a-z, A-Z]、数字 0-9、以及下划线 _（代表空格）、,、.、-、+（代表上档键）。
题目保证第 2 行输入的文字串非空。

注意：如果上档键坏掉了，那么大写的英文字母无法被打出。

输出格式：
在一行中输出能够被打出的结果文字。如果没有一个字符能被打出，则输出空行。

输入样例：
7+IE.
7_This_is_a_test.
输出样例：
_hs_s_a_tst
*/

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    string s1, s2;
    getline(cin, s1); // 第一行可能为空, 因此用 getline
    getline(cin, s2);
    set<char> s;
    for (auto c : s1)
    {
        s.insert(c);
        if ('A' <= c && c <= 'Z')
            s.insert((char)c - 'A' + 'a');
        if (c == '+')
        {
            for (int i = 0; i < 26; i++)
            {
                s.insert((char)i + 'A');
            }
        }
    }
    bool flag = false;
    for (auto c : s2)
    {
        if (s.find(c) != s.end())
        {
            continue;
        }
        else
        {
            cout << c;
            flag = true;
        }
    }
    if (flag == false)
    {
        cout << endl;
    }
    return 0;
}