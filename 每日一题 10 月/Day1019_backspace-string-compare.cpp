/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1019_backspace-string-compare.cpp
 * @Created Time:2020-10-19 12:40:36
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
    bool backspaceCompare(string S, string T) {
        string s, t;
        int n1 = S.size(), n2 = T.size();
        for (int i = 0; i < n1; ++i)
            if (S[i] > 96)
                s += S[i];
            else if (s.size())
                s.pop_back();
        for (int i = 0; i < n2; ++i)
            if (T[i] > 96)
                t += T[i];
            else if (t.size())
                t.pop_back();
        return s == t;
    }
};