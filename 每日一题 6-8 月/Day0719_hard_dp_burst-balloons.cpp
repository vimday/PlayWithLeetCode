/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :https://qoogle.top/leetcode-312-burst-balloons/
 * @File Name   :Day0719_hard_dp_burst-balloons.cpp
 * @Created Time:2020-07-19 01:24:15
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
    int maxCoins(vector<int>& nums) {
        int n = nums.size() + 2;
        vector<int> v(n, 1);
        for (int i = 1; i < n - 1; i++)
            v[i] = nums[i - 1];
        int dp[n][n];
        memset(dp, 0, sizeof dp);
        //dp[i][j]表示 （i,j）内的最大得分
        for (int d = 2; d < n; d++)
            for (int i = 0; i + d < n; i++) {
                int j = i + d;
                for (int k = i + 1; k < j; k++)
                    dp[i][j] = max(dp[i][j], dp[i][k] + v[i] * v[k] * v[j] + dp[k][j]);
            }
        return dp[0][n - 1];
    }
};

//bf bt
class Solution {
private:
    void helper(vector<int>& nums, int coins, int& ans) {
        // boundary
        if (nums.size() == 0) {
            ans = max(ans, coins);
            return;
        }
        // search
        for (int i = 0; i < nums.size(); ++i) {
            int tmp = nums[i];
            int delta = nums[i] * (i - 1 < 0 ? 1 : nums[i - 1]) * (i + 1 > nums.size() - 1 ? 1 : nums[i + 1]);
            nums.erase(nums.begin() + i);
            helper(nums, coins + delta, ans);
            nums.insert(nums.begin() + i, tmp);
        }
    }

public:
    int maxCoins(vector<int>& nums) {
        int ans = 0;
        helper(nums, 0, ans);
        return ans;
    }
};

// memory dp

class Solution {
private:
    vector<vector<int>> dp;
    int helper(vector<int>& nums, int i, int j) {
        // boundary
        if (i > j) return 0;
        if (dp[i][j] > 0) return dp[i][j];

        // search
        for (int k = i; k <= j; ++k) {
            int left = helper(nums, i, k - 1);
            int right = helper(nums, k + 1, j);
            int delta = nums[k] * nums[i - 1] * nums[j + 1];
            dp[i][j] = max(dp[i][j], left + right + delta);
        }
        return dp[i][j];
    }

public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        dp = vector<vector<int>>(n + 2, vector<int>(n + 2, 0));
        int ans = helper(nums, 1, n);
        return ans;
    }
};

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp = vector<vector<int>>(n + 2, vector<int>(n + 2, 0));
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        for (int len = 1; len <= n; ++len) {
            // i <= n - len (n - 1) + 1
            for (int i = 1; i <= n - len + 1; ++i) {
                int j = i + len - 1;
                for (int k = i; k <= j; ++k) {
                    dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + nums[k] * nums[i - 1] * nums[j + 1]);
                }
            }
        }

        return dp[1][n];
    }
};