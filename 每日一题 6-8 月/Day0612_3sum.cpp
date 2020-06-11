/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0612_3sum.cpp
 * @Created Time:2020-06-12 00:22:03
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
    vector<vector<int>> threeSum(vector<int>& nums) {
        //排序 -> 双指针
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            //枚举 i 作为第一个数
            if (i > 0 && nums[i] == nums[i - 1]) continue;  //剪枝
            int t = nums[i];
            if (t > 0) break;
            int l = i + 1, r = n - 1;
            while (l < r) {
                if (nums[l] + nums[r] + t < 0)
                    ++l;
                else if (nums[l] + nums[r] + t > 0)
                    --r;
                else {
                    res.push_back({t, nums[l], nums[r]});
                    while (++l < r && nums[l] == nums[l - 1])
                        ;
                    while (--r > l && nums[r] == nums[r + 1])
                        ;
                }
            }
        }
        return res;
    }
};