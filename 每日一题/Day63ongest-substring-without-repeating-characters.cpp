/*
 * @Author      :vimday
 * @Desc        :lc day63
 * @Url         :https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
 * @File Name   :Day63ongest-substring-without-repeating-characters.cpp
 * @Created Time:2020-05-02 17:14:47
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
    int lengthOfLongestSubstring(string s) {
        //双指针
        int n = s.size(), m[256], l = 0, r = 0, res = 0;
        memset(m, 0, sizeof m);
        while (r < n) {
            if (m[s[r]] == 0) {
                m[s[r]] = 1;
                res = max(res, ++r - l);
            } else {
                while (l < r) {
                    m[s[l]] = 0;
                    if (s[l] == s[r]) {
                        m[s[l]] = 1;
                        l++;
                        r++;
                        break;
                    }
                    l++;
                }
            }
        }
        return res;
    }
};