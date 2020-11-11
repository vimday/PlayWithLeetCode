/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1111_freedom-trail.cpp
 * @Created Time:2020-11-11 13:14:32
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
    int findRotateSteps(string ring, string key) {
        unordered_map<char, vector<int>> me;
        int m = key.size(), n = ring.size();
        // int dp[m][n];memset(dp,0x7f,sizeof dp);
        // int idx=0;
        // for(char &c:ring)
        //     me[c].push_back(idx++);
        // for(int &i:me[key[0]])
        //     dp[0][i]=min(i,n-i);
        // for(int i=1;i<m;i++)
        //     for(int &j:me[key[i]])
        //         for(int &k:me[key[i-1]])
        //             dp[i][j]=min(dp[i][j],dp[i-1][k]+min(abs(k-j),abs(min(k,j)+n-max(k,j))));
        // int res=INT_MAX;
        // for(int &i:me[key[m-1]])
        //     res=min(res,dp[m-1][i]);
        // return res+m;
        int dp[n];
        memset(dp, 0x7f, sizeof dp);
        int idx = 0;
        for (char &c : ring)
            me[c].push_back(idx++);
        for (int &i : me[key[0]])
            dp[i] = min(i, n - i);
        for (int i = 1; i < m; i++) {
            int dp2[n];
            memset(dp2, 0x7f, sizeof dp2);
            for (int &j : me[key[i]])
                for (int &k : me[key[i - 1]])
                    dp2[j] = min(dp2[j], dp[k] + min(abs(k - j), abs(min(k, j) + n - max(k, j))));
            for (int idx = 0; idx < n; idx++)
                dp[idx] = dp2[idx];
        }
        int res = INT_MAX;
        for (int &i : me[key[m - 1]])
            res = min(res, dp[i]);
        return res + m;
    }
};