/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day76subarray-sum-equals-k.cpp
 * @Created Time:2020-05-15 00:10:08
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
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0, ps = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        for (int i = 0; i < n; ++i) {
            ps += nums[i];
            if (m.count(ps - k))
                res += m[ps - k];
            m[ps]++;
        }
        return res;
    }
};
