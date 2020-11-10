/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1110_next-permutation.cpp
 * @Created Time:2020-11-10 13:49:21
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
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        bool sd = false;
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                int idx = i + 1;
                for (int j = n - 1; j > i + 1; --j) {
                    if (nums[j] > nums[i]) {
                        idx = j;
                        break;
                    }
                }
                swap(nums[i], nums[idx]);
                //sort(nums.begin()+i+1,nums.end());
                int s = i + 1, e = n - 1;
                while (s < e)
                    swap(nums[s++], nums[e--]);
                sd = true;
                break;
            }
        }
        if (!sd) {
            int i = 0, j = n - 1;
            while (i < j)
                swap(nums[i++], nums[j--]);
        }
    }
};
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(begin(nums), end(nums));
    }
};