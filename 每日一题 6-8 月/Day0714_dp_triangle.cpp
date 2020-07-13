/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0714_dp_triangle.cpp
 * @Created Time:2020-07-14 00:10:11
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
    int minimumTotal(vector<vector<int>>& tri) {
        for (int i = tri.size() - 2; i >= 0; i--)
            for (int j = 0; j < tri[i].size(); j++)
                tri[i][j] += min(tri[i + 1][j], tri[i + 1][j + 1]);
        return tri[0][0];
        int n = tri.size(), res = INT_MAX;
        if (n == 0) return 0;
        int dp[n];
        dp[0] = tri[0][0];
        for (int i = 1; i < n; ++i) {
            dp[i] = dp[i - 1] + tri[i][i];
            for (int j = i - 1; j > 0; --j)
                dp[j] = min(dp[j - 1], dp[j]) + tri[i][j];
            dp[0] = dp[0] + tri[i][0];
        }
        for (int& i : dp)
            if (i < res)
                res = i;
        return res;
        // int dp[n][n];
        // dp[0][0]=tri[0][0];
        // for(int i=1;i<n;++i){
        //     dp[i][0]=dp[i-1][0]+tri[i][0];
        //     dp[i][i]=dp[i-1][i-1]+tri[i][i];
        //     for(int j=1;j<i;++j)
        //         dp[i][j]=min(dp[i-1][j-1],dp[i-1][j])+tri[i][j];
        // }
        // for(int i=0;i<n;++i)
        //     if(res>dp[n-1][i])
        //         res=dp[n-1][i];
        // return res;
    }
};