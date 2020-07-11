/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0712_hard_dp_dungeon-game.cpp
 * @Created Time:2020-07-12 00:10:44
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
    int calculateMinimumHP(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        int dp[n + 1];
        memset(dp, 0x7f, sizeof dp);
        dp[n - 1] = g[m - 1][n - 1] > 0 ? 0 : -g[m - 1][n - 1];
        for (int i = m - 1; ~i; --i)
            for (int j = n - 1; ~j; --j)
                if (i != m - 1 || j != n - 1)
                    dp[j] = max(min(dp[j], dp[j + 1]) - g[i][j], 0);
        return dp[0] + 1;
        // int dp[m+1][n+1];
        // memset(dp,0x7f,sizeof dp);dp[m][n-1]=0;
        // for(int i=m-1;~i;--i)
        //     for(int j=n-1;~j;--j)
        //         dp[i][j]=max(min(dp[i+1][j],dp[i][j+1])-g[i][j],0);
        // return dp[0][0]+1;
    }
};