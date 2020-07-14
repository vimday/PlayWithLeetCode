/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0715_dp_dfs_unique-binary-search-trees.cpp
 * @Created Time:2020-07-15 00:24:19
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
    int numTrees(int n) {
        int dp[n + 1];
        memset(dp, 0, sizeof dp);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; ++i)
            for (int j = 1; j <= i; ++j)
                dp[i] += dp[j - 1] * dp[i - j];
        return dp[n];
    }
};
class Solution {
public:
    vector<vector<int>> memo;
    int numTrees(int n) {
        if (n < 1) return 0;
        memo = vector<vector<int>>(n + 2, vector<int>(n + 2, 0));
        return gst(1, n);
    }

    int gst(int l, int n) {
        if (l > n) return 1;
        int res = 0;
        for (int i = l; i <= n; ++i) {
            int left = memo[l][i - 1] ? memo[l][i - 1] : memo[l][i - 1] = gst(l, i - 1);
            int right = memo[i + 1][n] ? memo[i + 1][n] : memo[i + 1][n] = gst(i + 1, n);
            res += left * right;
        }
        return res;
    }
};