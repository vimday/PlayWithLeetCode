/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0830_reverse-words-in-a-string-iii.cpp
 * @Created Time:2020-08-30 16:40:47
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
    string reverseWords(string s) {
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') continue;
            int l = i, r = i;
            while (r < n && s[++r] != ' ')
                ;
            i = r;
            r--;
            while (l < r) swap(s[l++], s[r--]);
        }
        return s;
    }
};