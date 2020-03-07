#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int tt) {
        int dp[tt+1];memset(dp,0x3f,sizeof dp);dp[0]=0;
        for(int &i:coins)
            for(int j=i;j<tt+1;j++)
                dp[j]=min(dp[j],dp[j-i]+1);
        return dp[tt]==0x3f3f3f3f?-1:dp[tt];
    }
};