/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1008_reverse-string.cpp
 * @Created Time:2020-10-08 14:15:15
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
    void reverseString(vector<char>& s) {
        int l = -1, h = s.size();
        while (l + 1 < h)
            swap(s[++l], s[--h]);
    }
};