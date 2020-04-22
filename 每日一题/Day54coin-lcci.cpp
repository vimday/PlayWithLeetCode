/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day54coin-lcci.cpp
 * @Created Time:2020-04-23 00:35:09
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
    const int mod = 1e9 + 7;
    int waysToChange(int n) {
        long dp[n + 1];
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        int m[4] = {1, 5, 10, 25};
        for (int i = 0; i < 4; i++)
            for (int j = m[i]; j <= n; j++) {
                dp[j] += dp[j - m[i]];
                if (dp[j] >= mod)
                    dp[j] -= mod;
            }
        return dp[n];
    }
};