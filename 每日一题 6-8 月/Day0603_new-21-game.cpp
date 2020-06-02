/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0603_new-21-game.cpp
 * @Created Time:2020-06-03 00:02:34
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
    double new21Game(int N, int K, int W) {
        vector<double> dp(N + 1, 0);
        double sum = 0;  //长度小于等于W的区间的和
        dp[0] = 1;
        if (0 < K) sum += dp[0];

        for (int i = 1; i <= N; i++) {
            dp[i] = sum / W;
            if (i < K)  // 如果i>=K，停止向后传播
                sum += dp[i];
            if (i >= W) {
                sum -= dp[i - W];  //如果i>=W,则i-W状态过期
            }
        }
        double ans = 0;
        for (int i = K; i <= N; i++) ans += dp[i];
        return ans;
    }
    //     double new21Game(int n, int k, int w) {
    //         if(k==1&&w<=n||k==0) return 1.0;
    //         double dp[n+1],sum=0.0;
    //         memset(dp,0,sizeof(dp));
    //         for(int i=1;i<=n;++i){
    //             if(i<=w) dp[i]+=double(1.0/w);
    //             for(int j=i-1;j+w>=i&&j>0;--j)
    //                 if(j<k) dp[i]+=dp[j]*double(1.0/w);
    //             if(i>=k) sum+=dp[i];
    //         }
    //         return sum;

    //     }
};