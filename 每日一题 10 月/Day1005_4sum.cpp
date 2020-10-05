/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1005_4sum.cpp
 * @Created Time:2020-10-05 13:45:14
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
    vector<vector<int>> fourSum(vector<int>& nums, int tt) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
            if (i == 0 || nums[i] != nums[i - 1])
                for (int j = i + 1; j < n; ++j)
                    if (j == i + 1 || nums[j] != nums[j - 1]) {
                        int t = tt - nums[i] - nums[j];
                        int l = j + 1, h = n - 1;
                        while (l < h) {
                            if (nums[l] + nums[l + 1] > t || nums[h] + nums[h - 1] < t) break;
                            if (nums[l] + nums[h] == t) {
                                res.push_back({nums[i], nums[j], nums[l], nums[h]});
                                while (l < h && nums[l + 1] == nums[l]) l++;
                                while (l < h && nums[h - 1] == nums[h]) h--;
                                l++;
                                h--;
                            } else if (nums[l] + nums[h] < t) {
                                while (l < h && nums[l + 1] == nums[l]) l++;
                                l++;
                            } else {
                                while (l < h && nums[h - 1] == nums[h]) h--;
                                h--;
                            }
                        }
                    }
        return res;
    }
};