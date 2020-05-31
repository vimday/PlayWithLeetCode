/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day85median-of-two-sorted-arrays.cpp
 * @Created Time:2020-05-24 23:37:41
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
    int m, n;
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //这个边界情况挺多的  整体思想就是二分
        //直接 copy 吧
        m = nums1.size(), n = nums2.size();
        int l = (m + n + 1) / 2, r = (m + n + 2) / 2;
        return (help(nums1, 0, nums2, 0, l) + help(nums1, 0, nums2, 0, r)) / 2.0;
    }
    //从 i,j 开始查找第 k 个数
    int help(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
        if (i >= m) return nums2[j + k - 1];  //第 k 个是从 1 开始数的
        if (j >= n) return nums1[i + k - 1];
        if (k == 1)
            return min(nums1[i], nums2[j]);
        int m1 = (i + k / 2 - 1 < m) ? nums1[i + k / 2 - 1] : INT_MAX;
        int m2 = (j + k / 2 - 1 < n) ? nums2[j + k / 2 - 1] : INT_MAX;
        if (m1 < m2) {
            return help(nums1, i + k / 2, nums2, j, k - k / 2);
        }
        return help(nums1, i, nums2, j + k / 2, k - k / 2);
    }
};