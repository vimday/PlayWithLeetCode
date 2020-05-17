/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day79maximum-product-subarray.cpp
 * @Created Time:2020-05-18 00:18:58
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
    int maxProduct(vector<int>& nums) {
        //dp
        int n = nums.size();
        if (n == 0) return 0;
        int dp[n][2];
        memset(dp, 0, sizeof dp);
        dp[0][0] = dp[0][1] = nums[0];
        int res = nums[0];
        for (int i = 1; i < n; i++)
            if (nums[i]) {
                int t = nums[i], mx = t * dp[i - 1][0], mn = t * dp[i - 1][1];
                dp[i][0] = max(max(t, mx), mn);
                dp[i][1] = min(min(t, mx), mn);
                if (dp[i][0] > res)
                    res = dp[i][0];
            } else
                res = max(res, 0);
        return res;
    }
};