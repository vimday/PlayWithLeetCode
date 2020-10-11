/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :https://leetcode-cn.com/problems/maximum-nesting-depth-of-the-parentheses/
 * @File Name   :A_maximum-nesting-depth-of-the-parentheses.cpp
 * @Created Time:2020-10-11 12:30:05
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
    int maxDepth(string s) {
        int res = 0, n = s.size();
        stack<int> sk;
        sk.push(0);
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == '(')
                res = max(res, ++sk.top());
            else if (c == ')')
                --sk.top();
        }
        return res;
    }
};
class Solution {
public:
    int maxDepth(string s) {
        int mx = 0, cur = 0;
        for (char c : s) {
            if (c == '(')
                cur++;
            else if (c == ')')
                cur--;
            mx = max(mx, cur);
        }
        return mx;
    }
};