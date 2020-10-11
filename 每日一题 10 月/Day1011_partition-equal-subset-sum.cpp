/*
 * @Author      :vimday
 * @Desc        :01背包
 * @Url         :https://leetcode-cn.com/problems/partition-equal-subset-sum/
 * @File Name   :Day1011_partition-equal-subset-sum.cpp
 * @Created Time:2020-10-11 18:34:45
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
    bool canPartition(vector<int>& nums) {
        int n = 0;
        for (int& i : nums)
            n += i;
        if (n & 1)
            return false;
        n >>= 1;
        bool dp[n + 1];
        memset(dp, 0, sizeof dp);
        dp[0] = true;
        for (int v : nums)
            for (int j = n; j >= v; j--)
                dp[j] |= dp[j - v];

        return dp[n];
    }
};
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size() < 2) return false;

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;

        bitset<10001> bits(1);
        for (auto n : nums) bits |= bits << n;
        return bits[sum >> 1];
    }
};