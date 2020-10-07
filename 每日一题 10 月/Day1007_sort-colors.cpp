/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1007_sort-colors.cpp
 * @Created Time:2020-10-07 14:37:47
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
    void sortColors(vector<int>& nums) {
        int z = -1, o = 0, t = nums.size();
        //[0,z] [z+1,o) [t,n)
        while (o < t) {
            if (nums[o] == 0)
                swap(nums[++z], nums[o++]);
            if (o < t && nums[o] == 2)
                swap(nums[o], nums[--t]);
            if (o < t && nums[o] == 1)
                ++o;
        }
    }
};