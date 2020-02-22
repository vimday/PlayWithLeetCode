#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int mod=1e9+7;
    int countOrders(int n) {
        long dp[n+1]={};dp[1]=1;
        for(int i=2;i<=n;i++){
            long pre=dp[i-1],sz=2*(i-1);
            dp[i]=pre*(sz+1)*(sz+2)/2%mod;
            
        }
            
        return dp[n];
    }
};