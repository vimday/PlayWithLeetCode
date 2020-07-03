/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0704_dpstack_longest-valid-parentheses.cpp
 * @Created Time:2020-07-04 00:56:04
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
    int longestValidParentheses(string s) {
        stack<int> sk;
        sk.push(-1);  //栈底的保险永远存着当前有效字符串的前一个字符
        int res = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == '(')
                sk.push(i);
            else {
                sk.pop();
                if (sk.size()) {
                    int pre = sk.top();
                    res = max(res, i - pre);
                } else
                    sk.push(i);
            }
        }
        return res;
    }
};
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), res = 0;
        int dp[n + 1];
        memset(dp, 0, sizeof dp);

        //dp[i]为 已 s[i-1]为结尾的最长有小括号长度
        for (int i = 1; i < n; i++) {
            char c = s[i];
            if (c == ')') {
                if (s[i - 1] == '(')
                    res = max(dp[i + 1] = dp[i - 1] + 2, res);
                else {
                    int pre = i - dp[i] - 1;
                    if (pre >= 0 && s[pre] == '(')
                        res = max(dp[i + 1] = dp[i] + 2 + dp[pre], res);
                }
            }
        }
        return res;
    }
};