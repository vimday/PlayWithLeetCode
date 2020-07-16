/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0717_binary_search-insert-position.cpp
 * @Created Time:2020-07-17 00:12:18
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
    int searchInsert(vector<int>& nums, int t) {
        int r = nums.size(), l = 0;
        while (l < r) {
            int m = l + (r - l >> 1);
            t < nums[m] ? r = m : l = m + 1;
        }
        return l == 0 ? 0 : nums[--l] == t ? l : l + 1;
    }
};