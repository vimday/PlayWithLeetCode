/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1021_long-pressed-name.cpp
 * @Created Time:2020-10-21 11:09:58
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
    bool isLongPressedName(string name, string typed) {
        int n = name.size(), m = typed.size();
        if (n > m)
            return false;
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (name[i] != typed[j])
                return false;
            int pi = i, pj = j;
            while (i + 1 < n && name[i + 1] == name[i]) ++i;
            while (j + 1 < m && typed[j + 1] == typed[j]) ++j;
            if (j - pj < i - pi)
                return false;
            ++i;
            ++j;
        }
        return i == n && j == m;
    }
};