/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day69maximal-square.cpp
 * @Created Time:2020-05-08 00:12:27
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
    int maximalSquare(vector<vector<char>>& ma) {
        int m = ma.size();
        if (m == 0) return 0;
        int n = ma[0].size(), res = 0, t = 0;
        //int dp[m+1][n+1]={};
        /**
        dp[i][j]表示以第i行第j列为右下角所能构成的最大正方形边长, 则递推式为: 
        dp[i][j] = 1 + min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]);
        **/
        int dp[n + 1] = {}, pre = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (ma[i][j] == '1') {
                    t = dp[j + 1];
                    dp[j + 1] = 1 + min(dp[j], min(pre, dp[j + 1]));
                    res = max(res, dp[j + 1]);
                    pre = t;
                } else {
                    dp[j + 1] = 0;
                    pre = t;
                }
        //{int t=0;res=max(res,dfs(ma,i,j,t));}
        // {
        //     dp[i+1][j+1]=1+min(dp[i][j],min(dp[i+1][j],dp[i][j+1]));
        //     res=max(res,dp[i+1][j+1]);
        // }
        return res * res;
    }
    int dfs(vector<vector<char>>& ma, int i, int j, int& t) {
        int m = ma.size(), n = ma[0].size();
        for (int d = 1; d <= t; ++d) {
            if (ma[i][j - d] == '0' || ma[i - d][j] == '0')
                return t * t;
        }
        t++;
        if (i + 1 < m && j + 1 < n && ma[i + 1][j + 1] == '1') {
            dfs(ma, i + 1, j + 1, t);
        }
        return t * t;
    }
};