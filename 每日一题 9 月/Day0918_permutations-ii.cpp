/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0918_permutations-ii.cpp
 * @Created Time:2020-09-18 10:36:53
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
    vector<vector<int>> ans;

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        perm(nums, 0, nums.size() - 1);
        return ans;
    }

    void perm(vector<int> nums, int left, int right) {
        if (left == right)
            ans.push_back(nums);
        else {
            for (int i = left; i <= right; i++) {
                if (i != left && nums[left] == nums[i]) continue;  // 去重
                swap(nums[left], nums[i]);
                perm(nums, left + 1, right);
            }
        }
    }
};