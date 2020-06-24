/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0623_3-sum-closest.cpp
 * @Created Time:2020-06-24 14:12:19
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
    int threeSumClosest(vector<int>& nums, int tt) {
        int n = nums.size(), res = INT_MAX, d = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            int t = tt - nums[i];
            int l = i + 1, h = n - 1;
            while (l < h) {
                if (nums[l] + nums[h] == t) return tt;
                if (d > abs(nums[l] + nums[h] - t)) {
                    d = abs(nums[l] + nums[h] - t);
                    res = nums[i] + nums[l] + nums[h];
                }
                if (nums[l] + nums[h] > t)
                    h--;
                else
                    l++;
            }
        }
        return res;
    }
};