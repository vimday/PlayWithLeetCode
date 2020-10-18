/*
 * @Author      :vimday
 * @Desc        :lc day 
 * @Url         :https://leetcode-cn.com/problems/longest-palindrome/
 * @File Name   :Day19longest-palindrome.cpp
 * @Created Time:2020-03-19 00:18:32
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
    int longestPalindrome(string s) {
        int m[128] = {};
        for (char &c : s)
            m[c]++;
        int res = 0, mi = 0;
        for (int &i : m)
            if (i & 1) {
                res += i - 1;
                mi = 1;
            } else
                res += i;
        return res + mi;
    }
};