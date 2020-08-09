/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0810_count-binary-substrings.cpp
 * @Created Time:2020-08-10 00:26:36
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
    int countBinarySubstrings(string s) {
        int n = s.size();
        int res = 0, pl = 0, cl = 1;
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i - 1])
                cl++;
            else {
                pl = cl;
                cl = 1;
            }
            if (pl >= cl)
                res++;
        }
        return res;
    }
};