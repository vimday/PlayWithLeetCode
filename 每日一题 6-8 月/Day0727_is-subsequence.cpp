/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0727_is-subsequence.cpp
 * @Created Time:2020-07-27 00:15:55
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
    bool isSubsequence(string s, string t) {
        int m = s.size();
        if (m == 0)
            return true;
        int idx = 0;

        for (char& c : t)
            if (s[idx] == c)
                if (++idx == m)
                    return true;
        return false;
    }
};
// 一年前的蠢方法
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size(), n = t.size(), k = 0;
        if (m == 0) return true;
        if (n == 0) return false;
        if (m > n) return false;
        for (int i = 0, j = 0; i < m && j < n;) {
            if (s[i] == t[j]) {
                ++i;
                ++j;
                ++k;
            } else
                ++j;
        }
        return k == m;
    }
};