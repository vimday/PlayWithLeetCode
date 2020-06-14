/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0615_longest-common-prefix.cpp
 * @Created Time:2020-06-15 01:44:14
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
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        if (strs.size() == 1)
            return strs[0];
        string result = "";
        int min = INT_MAX;
        for (int i = 0; i < strs.size(); i++) {
            if (strs[i].size() < min)
                min = strs[i].size();
        }
        for (int j = 0; j < min; j++) {
            char mode = strs[0][j];
            for (int k = 1; k < strs.size(); k++) {
                if (strs[k][j] != mode) {
                    return result;
                }
            }
            string s(1, mode);
            result += s;
        }
        return result;
    }
};