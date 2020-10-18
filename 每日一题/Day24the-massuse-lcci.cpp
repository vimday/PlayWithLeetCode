/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day24the-massuse-lcci.cpp
 * @Created Time:2020-03-24 00:31:09
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
    int massage(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int dp[n][2] = {};
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = nums[i] + dp[i - 1][0];
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};
// class Solution {
//     public int massage(int[] nums) {
//         int n = nums.length;
//         if (n == 0) {
//             return 0;
//         }
//         if (n == 1) {
//             return nums[0];
//         }
//         int[] dp = new int[n];
//         dp[0] = nums[0];
//         dp[1] = Math.max(nums[0], nums[1]);
//         for (int i = 2; i < n; i++) {
//             dp[i] = Math.max(dp[i - 1], dp[i - 2] + nums[i]);
//         }
//         return dp[n - 1];
//     }
// }

// class Solution {
//     public int massage(int[] nums) {
//         int a = 0, b = 0;
//         for (int i = 0; i < nums.length; i++) {
//             int c = Math.max(b, a + nums[i]);
//             a = b;
//             b = c;
//         }
//         return b;
//     }
// }