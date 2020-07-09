/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0710_dp_best-time-to-buy-and-sell-stock-with-cooldown.cpp
 * @Created Time:2020-07-10 00:32:07
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
    int maxProfit(vector<int>& ps) {
        int n = ps.size();
        int dp[n + 2][2];
        memset(dp, 0, sizeof dp);
        //0空仓 1 持仓
        dp[0][1] = dp[1][1] = INT_MIN;
        for (int i = 0; i < n; i++) {
            dp[i + 2][0] = max(dp[i + 1][0], dp[i + 1][1] + ps[i]);
            dp[i + 2][1] = max(dp[i + 1][1], dp[i][0] - ps[i]);
        }
        return dp[n + 1][0];
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        int b[n] = {0}, s[n] = {0}, c[n] = {0};
        b[0] = -prices[0];
        for (int i = 1; i < n; ++i) {
            b[i] = max(b[i - 1], c[i - 1] - prices[i]);
            s[i] = max(s[i - 1], b[i - 1] + prices[i]);
            c[i] = max(s[i - 1], c[i - 1]);
        }
        return s[n - 1];
    }
};
class Solution {
public:
    int maxProfit(vector<int>& ps) {
        int n = ps.size();
        int pp0 = 0, pp1 = 0, p0 = 0, p1 = INT_MIN, c0 = 0, c1 = 0;
        // 0 空仓 1 满仓
        for (int& i : ps) {
            c0 = max(p0, p1 + i);
            c1 = max(p1, pp0 - i);
            pp0 = p0;
            pp1 = p1;
            p0 = c0;
            p1 = c1;
        }
        return c0;
    }
};