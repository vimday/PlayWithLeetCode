/*
 * @Author      :vimday
 * @Desc        :day 52
 * @Url         :https://leetcode-cn.com/problems/count-number-of-nice-subarrays/
 * @File Name   :Day52.cpp
 * @Created Time:2020-04-21 00:29:18
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
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), m[n + 1], cs = 0, res = 0;
        memset(m, 0, sizeof m);
        m[0] = 1;
        for (int& i : nums) {
            if (i % 2)
                cs++;
            if (cs - k >= 0)
                res += m[cs - k];
            m[cs]++;
        }
        return res;
        // vector<int> v;int n=nums.size();
        // for(int i=0;i<n;i++)
        //     if(nums[i]%2)
        //         v.push_back(i);
        // if(v.size()<k)
        //     return 0;
        // int sz=v.size(),res=0;
        // for(int i=0;i<sz-k+1;i++)
        // {
        //     int j=i+k-1;
        //     int l=i==0?v[i]+1:v[i]-v[i-1];
        //     int r=j==(sz-1)?(n-v[j]):(v[j+1]-v[j]);
        //     res+=l*r;
        // }
        // return res;
    }
};