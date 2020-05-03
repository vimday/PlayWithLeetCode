/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day64maximux-subarray.cpp
 * @Created Time:2020-05-03 01:24:48
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
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int res = nums[0], t = 0;
        for (int& i : nums) {
            t += i;
            res = max(res, t);
            if (t < 0)
                t = 0;
        }
        return res;
    }
};
