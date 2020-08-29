/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0829_TODO_hard_shortest-palindrome.cpp
 * @Created Time:2020-08-29 20:05:53
 * @E-mail      :lwftx@outlook.com
 * @GitHub      :https://github.com/vimday
 */
#include <bits/stdc++.h>
using namespace std;
void debug() {
#ifdef LOCAL
    freopen("E:\\Cpp\\in.txt", "r", stdin);
    freopen("E:\\Cpp\\out.txt", "w", stdout);
#endif
}
class Solution {
public:
    string shortestPalindrome(string ss) {
        if (ss.size() == 0 || ss.size() == 1) {
            return ss;
        }
        string s = "#";
        for (auto c : ss) {
            s.push_back('#');
            s.push_back(c);
        }
        s += "#$";
        int n = s.size();
        int p[n];
        int d = 0, c = 0, ri = 0;  //ri记录最长的以第一个字符开头的回文的右端
        for (int i = 1; i < n - 1; i++) {
            int j = 2 * c - i;
            if (i >= d) {
                p[i] = 0;
            } else {
                p[i] = min(d - i, p[j]);
            }
            while (s[i + 1 + p[i]] == s[i - 1 - p[i]]) {
                p[i]++;
            }
            if (i + p[i] > d) {
                d = i + p[i];
                c = i;
            }
            if (i - p[i] <= 1) {
                ri = max(ri, (i + p[i]) / 2 - 1);
            }
        }
        string temp = ss.substr(ri + 1, n - ri - 1);
        reverse(temp.begin(), temp.end());
        return temp + ss;
    }
};
//tle
class Solution {
public:
    string shortestPalindrome(string s) {
        string rs = s;
        reverse(rs.begin(), rs.end());
        int i = 0, n = s.size();
        while (1) {
            if (rs.substr(i) == s.substr(0, n - i))
                break;
            i++;
        }
        return rs.substr(0, i) + s;
    }
};