/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0713_intersection-of-two-arrays-ii.cpp
 * @Created Time:2020-07-13 00:14:18
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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        int n = nums1.size();
        int m = nums2.size();
        int i, j, k;
        i = 0;
        j = 0;
        k = 0;
        while (i < n && j < m) {
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        return res;
    }
};