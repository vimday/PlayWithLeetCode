/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1125_increasing-decreasing-string.cpp
 * @Created Time:2020-11-25 13:46:39
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
    string sortString(string s) {
        int m[26] = {0};
        for (char& c : s)
            m[c - 'a']++;
        int n = s.size(), idx = 0;
        while (idx < n) {
            for (int i = 0; i < 26; ++i)
                if (m[i]-- > 0)
                    s[idx++] = 'a' + i;
            for (int i = 25; ~i; --i)
                if (m[i]-- > 0)
                    s[idx++] = 'a' + i;
        }
        return s;
    }
};