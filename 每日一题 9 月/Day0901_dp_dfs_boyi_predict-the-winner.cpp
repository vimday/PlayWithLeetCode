/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0901_dp_dfs_boyi_predict-the-winner.cpp
 * @Created Time:2020-09-01 12:12:09
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
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if (n % 2 == 0) return true;
        int dp[n][n];
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < n; i++)
            dp[i][i] = nums[i];
        //dp[i][j]=max(nums[i]-dp[i+1][j],nums[j]-dp[i][j-1]);
        for (int i = n - 2; i >= 0; --i)
            for (int j = i + 1; j < n; ++j)
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
        return dp[0][n - 1] >= 0;
    }
};

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        mem.resize(n, vector<int>(n, -1));
        sum.resize(n);
        int t = 0;
        for (int i = 0; i < nums.size(); ++i) {
            t += nums[i];
            sum[i] = t;
        }
        int total = sum.back();
        int maxV = helper(nums, 0, n - 1);
        return maxV >= total - maxV;
    }

    int helper(vector<int>& nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }

        if (mem[left][right] != -1)
            return mem[left][right];

        int total = sum[right] - sum[left] + nums[left];
        // 左
        int ans = total - helper(nums, left + 1, right);
        // 右
        ans = max(ans, total - helper(nums, left, right - 1));
        return mem[left][right] = ans;
    }

    vector<vector<int>> mem;
    vector<int> sum;
};
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        mem.resize(n, vector<int>(n, -1));
        return helper(nums, 0, n - 1) >= 0;
    }

    int helper(vector<int>& nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }

        if (mem[left][right] != -1)
            return mem[left][right];

        // 左
        int ans = nums[left] - helper(nums, left + 1, right);
        // 右
        ans = max(ans, nums[right] - helper(nums, left, right - 1));
        return mem[left][right] = ans;
    }

    vector<vector<int>> mem;
};