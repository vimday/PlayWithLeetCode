/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0725_hard_binary_dp_split-array-largest-sum.cpp
 * @Created Time:2020-07-25 21:35:52
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
    bool check(vector<int>& nums, int x, int m) {
        long long sum = 0;
        int cnt = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (sum + nums[i] > x) {
                cnt++;
                sum = nums[i];
            } else {
                sum += nums[i];
            }
        }
        return cnt <= m;
    }

    int splitArray(vector<int>& nums, int m) {
        long long left = 0, right = 0;
        for (int i = 0; i < nums.size(); i++) {
            right += nums[i];
            if (left < nums[i]) {
                left = nums[i];
            }
        }
        while (left < right) {
            long long mid = (left + right) >> 1;
            if (check(nums, mid, m)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
class Solution {
public:
    int splitArray(vector<int>& nums, int n) {
        int m = nums.size();
        long ps[m + 1];
        memset(ps, 0, sizeof ps);
        for (int i = 1; i <= m; i++)
            ps[i] = ps[i - 1] + nums[i - 1];
        //vector<vector<int>> dp(m+1,vector<int>(n+1,INT_MAX));
        long dp[m + 1][n + 1];
        memset(dp, 0x3f, sizeof dp);
        // memset(dp,0,sizeof dp[0]);
        // for(int i=1;)
        dp[0][0] = 0;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n && j <= i; j++) {
                for (int k = i - 1; k >= 0; k--)
                    dp[i][j] = min(dp[i][j], max(dp[k][j - 1], ps[i] - ps[k]));
                // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }

        return dp[m][n];
    }
};