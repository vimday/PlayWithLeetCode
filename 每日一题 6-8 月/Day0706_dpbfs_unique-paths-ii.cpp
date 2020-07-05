/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0706_dpbfs_unique-paths-ii.cpp
 * @Created Time:2020-07-06 00:11:31
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
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int m = obs.size();
        if (m == 0) return 0;
        int n = obs[0].size();
        if (obs[0][0] == 1 || obs[m - 1][n - 1] == 1) return 0;
        long long dp[n + 1];
        memset(dp, 0, sizeof dp);
        //dp[n]=1;
        for (int i = n - 1; i >= 0; --i)
            if (obs[m - 1][i])
                break;
            else
                dp[i] = 1;
        for (int i = m - 2; i >= 0; i--)
            for (int j = n - 1; j >= 0; j--)
                if (obs[i][j] == 0)
                    dp[j] += dp[j + 1];
                else
                    dp[j] = 0;
        return dp[0];
        // long long dp[m+1][n+1]; memset(dp,0,sizeof dp);
        // dp[m-1][n-1]=1;
        // for(int i=m-1;i>=0;i--)
        //     for(int j=n-1;j>=0;--j){
        //         if(obs[i][j]==0){
        //             dp[i][j]=max(dp[i+1][j]+dp[i][j+1],dp[i][j]);
        //         }
        //     }
        // return dp[0][0];
        // queue<pair<int,int>> q;
        // q.push({0,0});
        // int res=0;
        // while(!q.empty()){
        //     auto t=q.front();q.pop();
        //     int x=t.first,y=t.second;
        //     if(x==m-1&&y==n-1){
        //         res++;
        //         continue;
        //     }
        //     if(x+1<m&&obs[x+1][y]==0)
        //         q.push({x+1,y});
        //     if(y+1<n&&obs[x][y+1]==0)
        //         q.push({x,y+1});
        // }
        //return res;
    }
};