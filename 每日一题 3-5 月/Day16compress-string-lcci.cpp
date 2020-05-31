/*
 * @Author      :vimday
 * @Desc        :lc
 * @Url         :https://leetcode-cn.com/problems/compress-string-lcci/
 * @File Name   :Day16compress-string-lcci.cpp
 * @Created Time:2020-03-16 00:10:47
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
    string compressString(string S) {
        string res;
        int n = S.size();
        for (int i = 0; i < n;) {
            char c = S[i];
            int j = i + 1;
            for (; j < n; j++)
                if (S[j] != S[i])
                    break;
            res.push_back(c);
            res += to_string(j - i);

            i = j;
        }
        return res.size() < n ? res : S;
    }
};