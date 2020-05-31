/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day55nixushu.cpp
 * @Created Time:2020-04-24 00:02:53
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
static auto x = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    int cnt;
    int tmp[25005];
    void help(vector<int>& nums, int l, int h) {
        if (l >= h - 1) return;
        int mi = l + (h - l >> 1);
        help(nums, l, mi);
        help(nums, mi, h);

        for (int i = 0; i < mi - l; i++)
            tmp[i] = nums[i + l];
        //merge tmp[0...mi-l) nums[mi,h) ->nums[l,h)
        int i = 0, j = mi, k = l;
        while (i < mi - l && j < h) {
            if (tmp[i] <= nums[j])
                nums[k++] = tmp[i++];
            else {
                // cnt+=j-mi+1;
                cnt += mi - i - l;
                nums[k++] = nums[j++];
            }
        }
        while (i < mi - l) nums[k++] = tmp[i++];
    }
    int reversePairs(vector<int>& nums) {
        help(nums, 0, nums.size());
        return cnt;
    }
};