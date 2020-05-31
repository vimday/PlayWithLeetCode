/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day87find-the-duplicate-number.cpp
 * @Created Time:2020-05-26 18:26:59
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
    int findDuplicate(vector<int>& nums) {
        int s = nums[0], f = nums[nums[0]];
        while (s != f) {
            s = nums[s];
            f = nums[nums[f]];
        }
        f = 0;
        while (s != f) {
            s = nums[s];
            f = nums[f];
        }
        return s;
    }
};
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 1, h = n;
        while (l < h) {
            int mi = l + (h - l >> 1);
            int cnt = 0;
            for (int i = 0; i < n; ++i)
                if (nums[i] <= mi)
                    cnt++;
            //cnt<=mi?l=mi+1:h=mi;//l为保证cnt>mi的第一个元素
            mi < cnt ? h = mi : l = mi + 1;
        }
        return l;
    }
};