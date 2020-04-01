/*
 * @Author      :vimday
 * @Desc        :括号匹配
 * @Url         :https://leetcode-cn.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/submissions/
 * @File Name   :Day40maximum-nesting-depth-of-two-valid-parentheses-strings.cpp
 * @Created Time:2020-04-01 00:27:18
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
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> res(n);
        for (int i = 1; i < n; i++) {
            if (seq[i] == seq[i - 1])
                res[i] = 1 ^ res[i - 1];
            else
                res[i] = res[i - 1];
        }
        return res;
    }
};