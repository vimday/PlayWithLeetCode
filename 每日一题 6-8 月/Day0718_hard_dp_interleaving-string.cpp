/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0718_hard_dp_interleaving-string.cpp
 * @Created Time:2020-07-18 22:16:07
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
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if (m + n != s3.size())
            return false;
        bool dp[m + 1][n + 1];
        memset(dp, 0, sizeof dp);
        for (int i = 0; i <= m; i++)
            for (int j = 0; j <= n; j++)
                if (!i && !j)
                    dp[i][j] = true;
                else if (!i)
                    dp[i][j] = s2[j - 1] == s3[j - 1] && dp[i][j - 1];
                else if (!j)
                    dp[i][j] = s1[i - 1] == s3[i - 1] && dp[i - 1][j];
                else
                    dp[i][j] = (s1[i - 1] == s3[i + j - 1] && dp[i - 1][j]) || (s2[j - 1] == s3[i + j - 1] && dp[i][j - 1]);

        return dp[m][n];
    }
};
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 + n2 != s3.size()) return false;
        vector<bool> dp(n2 + 1);
        for (int i = 0; i <= n1; ++i) {
            for (int j = 0; j <= n2; ++j) {
                if (!i && !j)
                    dp[j] = true;
                else if (!i)
                    dp[j] = dp[j - 1] && s2[j - 1] == s3[j - 1];
                else if (!j)
                    dp[j] = dp[j] && s1[i - 1] == s3[i - 1];
                else
                    dp[j] = (dp[j] && s1[i - 1] == s3[i - 1 + j]) || (dp[j - 1] && s2[j - 1] == s3[i - 1 + j]);
            }
        }
        return dp[n2];
    }
};