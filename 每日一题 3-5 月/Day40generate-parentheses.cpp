/*
 * @Author      :vimday
 * @Desc        :生成n对括号 dp dfs
 * @Url         :https://leetcode-cn.com/problems/generate-parentheses/submissions/
 * @File Name   :Day40generate-parentheses.cpp
 * @Created Time:2020-04-09 00:20:15
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
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        func(res, "", 0, 0, n);
        return res;
    }

    void func(vector<string> &res, string str, int l, int r, int n) {
        if (l > n || r > n || r > l) return;
        if (l == n && r == n) {
            res.push_back(str);
            return;
        }
        func(res, str + '(', l + 1, r, n);
        func(res, str + ')', l, r + 1, n);
        return;
    }
};
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return {};
        if (n == 1) return {"()"};
        vector<vector<string>> dp(n + 1);
        dp[0] = {""};
        dp[1] = {"()"};
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                for (string p : dp[j])
                    for (string q : dp[i - j - 1]) {
                        string str = "(" + p + ")" + q;
                        dp[i].push_back(str);
                    }
            }
        }
        return dp[n];
    }
};
