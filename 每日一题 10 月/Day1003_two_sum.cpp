/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1003_two_sum.cpp
 * @Created Time:2020-10-03 20:20:39
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
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            if (m.count(target - nums[i]))
                return {m[target - nums[i]], i};
            else
                m[nums[i]] = i;
        return {};
    }
};