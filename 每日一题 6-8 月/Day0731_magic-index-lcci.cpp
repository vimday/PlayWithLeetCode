/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0731_magic-index-lcci.cpp
 * @Created Time:2020-07-31 00:19:27
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
    int findMagicIndex(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
            if (nums[i] == i)
                return i;
        return -1;
    }
};