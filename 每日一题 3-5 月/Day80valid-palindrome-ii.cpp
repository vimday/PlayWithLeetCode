/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day80valid-palindrome-ii.cpp
 * @Created Time:2020-05-19 00:17:40
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
    bool validPalindrome(string s) {
        int n = s.size();
        if (n < 3) return true;
        int i = 0, j = n;
        while (i < j) {
            while (i < j && s[i++] == s[--j])
                ;
            if (i >= j) return true;
            return isp(s, i, j) || isp(s, i - 1, j - 1);
        }
        return false;
    }
    bool isp(string &s, int i, int j) {
        while (i < j && s[i] == s[j]) {
            i++;
            j--;
        };
        if (i >= j) return true;
        return false;
    }
};
