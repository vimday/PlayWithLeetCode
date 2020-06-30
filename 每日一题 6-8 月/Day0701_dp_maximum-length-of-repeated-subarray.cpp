/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0701_dp_maximum-length-of-repeated-subarray.cpp
 * @Created Time:2020-07-01 00:18:34
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
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size();
        int dp[m + 1][n + 1], res = 0;
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (A[i] == B[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                    if (dp[i + 1][j + 1] > res) res = dp[i + 1][j + 1];
                }
            }
        return res;
    }
};