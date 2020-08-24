/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0824_repeated-substring-pattern.cpp
 * @Created Time:2020-08-24 23:08:35
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
    bool repeatedSubstringPattern(string s) {
        string str = s + s;
        str = str.substr(1, str.size() - 2);
        if (str.find(s) == -1)
            return false;
        return true;
    }
};