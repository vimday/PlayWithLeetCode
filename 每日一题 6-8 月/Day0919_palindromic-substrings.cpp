/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0919_palindromic-substrings.cpp
 * @Created Time:2020-08-19 00:35:19
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
    int countSubstrings(string s) {
        int res = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            int odd = caco(s, i);
            int even = cace(s, i);
            res += odd + even;
        }
        return res;
    }
    int caco(string& s, int i) {
        int l = i, r = i, cnt = 0, n = s.size();
        while (l >= 0 && r < n && s[l] == s[r]) {
            l--;
            r++;
            cnt++;
        }
        return cnt;
    }
    int cace(string& s, int i) {
        int l = i, r = i + 1, cnt = 0, n = s.size();
        while (l >= 0 && r < n && s[l] == s[r]) {
            l--;
            r++;
            cnt++;
        }
        return cnt;
    }
};