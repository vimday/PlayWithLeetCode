/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1001_dp_UlBDOe.cpp
 * @Created Time:2020-10-01 22:55:47
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
    int minimumOperations(string ls) {
        int n = ls.size();
        int dp[n + 1][3];
        memset(dp, 0x7f, sizeof dp);
        dp[0][0] = 0;
        for (int i = 0; i < n;)
            if (ls[i++] == 'r') {
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
                dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]);
            } else {
                dp[i][0] = dp[i - 1][0] + 1;
                if (i != 1)
                    dp[i][1] = dp[i - 1][0];
                dp[i][1] = min(dp[i][1], dp[i - 1][1]);
                dp[i][2] = min(dp[i - 1][2], dp[i - 1][1]) + 1;
            }
        return dp[n][2];
    }
};