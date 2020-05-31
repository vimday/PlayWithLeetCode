/*
 * @Author      :vimday
 * @Desc        :lc day58
 * @Url         :https://leetcode-cn.com/problems/search-in-rotated-sorted-array/submissions/
 * @File Name   :Day58search-in-rotated-sorted-array.cpp
 * @Created Time:2020-04-27 00:48:19
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
    int search(vector<int>& nums, int tt) {
        int n = nums.size(), l = 0, h = n;
        while (l < h) {
            int mi = l + (h - l >> 1);
            (nums[0] <= tt) ^ (tt <= nums[mi]) ^ (nums[0] > nums[mi]) ? l = mi + 1 : h = mi;
        }
        return l < n ? nums[l] == tt ? l : -1 : -1;
    }
};