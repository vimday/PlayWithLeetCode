/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1119_move-zeros.cpp
 * @Created Time:2020-11-19 10:27:13
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
    void moveZeroes(vector<int>& nums) {
        int idx = 0;
        for (int i : nums)
            if (i)
                nums[idx++] = i;
        int n = nums.size();
        while (idx < n)
            nums[idx++] = 0;
    }
};