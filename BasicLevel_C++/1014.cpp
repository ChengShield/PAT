/*
1014 福尔摩斯的约会 （20 point(s)）
大侦探福尔摩斯接到一张奇怪的字条：我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm。大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间星期四 14:04，因为前面两字符串中第 1 对相同的大写英文字母（大小写有区分）是第 4 个字母 D，代表星期四；第 2 对相同的字符是 E ，那是第 5 个英文字母，代表一天里的第 14 个钟头（于是一天的 0 点到 23 点由数字 0 到 9、以及大写字母 A 到 N 表示）；后面两字符串第 1 对相同的英文字母 s 出现在第 4 个位置（从 0 开始计数）上，代表第 4 分钟。现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。

输入格式：
输入在 4 行中分别给出 4 个非空、不包含空格、且长度不超过 60 的字符串。

输出格式：
在一行中输出约会的时间，格式为 DAY HH:MM，其中 DAY 是某星期的 3 字符缩写，即 MON 表示星期一，TUE 表示星期二，WED 表示星期三，THU 表示星期四，FRI 表示星期五，SAT 表示星期六，SUN 表示星期日。题目输入保证每个测试存在唯一解。

输入样例：
3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm
输出样例：
THU 14:04
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    freopen("data.txt", "r", stdin);
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    vector<string> v = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    int day, hour, minite = 0;
    bool flag = false;
    for (int i = 0; i < s1.size() && i < s2.size(); i++)
    {
        if (s1[i] == s2[i])
        {
            if (flag == false)
            {
                if ('A' <= s1[i] && s1[i] <= 'G')
                {
                    day = s1[i] - 'A' + 1;
                    flag = true;
                }
            }
            else
            {
                if ('0' <= s1[i] && s1[i] <= '9')
                {
                    hour = s1[i] - '0';
                    break;
                }
                else if ('A' <= s1[i] && s1[i] <= 'N')
                {
                    hour = s1[i] - 'A' + 10;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < s3.size() && i < s4.size(); i++)
    {
        if (s3[i] == s4[i] && (('A' <= s3[i] && s3[i] <= 'Z') || ('a' <= s3[i] && s3[i] <= 'z')))
        {
            minite = i;
            break;
        }
    }
    // minite = 'a';
    // cout << day << ' ' << hour << ' ' << minite;
    cout << v[day - 1] << ' ';
    if (hour < 10)
    {
        cout << '0';
    }
    cout << hour << ':';
    if (minite < 10)
    {
        cout << '0';
    }
    cout << minite;

    return 0;
}