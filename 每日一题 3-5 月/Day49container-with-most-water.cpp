/*
 * @Author      :vimday
 * @Desc        :lc day49
 * @Url         :https://leetcode-cn.com/problems/container-with-most-water/submissions/
 * @File Name   :Day49container-with-most-water.cpp
 * @Created Time:2020-04-18 00:10:51
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
    int maxArea(vector<int>& height) {
        if (height.size() < 2) return 0;
        int i(0), j = height.size() - 1, res = 0;
        while (i < j) {
            int h = height[i] < height[j] ? height[i] : height[j];
            res = res > h * (j - i) ? res : h * (j - i);
            if (height[i] < height[j])
                ++i;
            else
                --j;
        }
        return res;
    }
};