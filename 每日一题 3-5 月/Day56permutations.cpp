/*
 * @Author      :vimday
 * @Desc        :全排列
 * @Url         :https://leetcode-cn.com/problems/permutations/
 * @File Name   :Day56permutations.cpp
 * @Created Time:2020-04-25 00:02:41
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
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        per(nums, 0, n);
        return res;
    }
    void per(vector<int>& v, int b, int e) {
        if (b == e) {
            res.push_back(v);
            return;
        }
        for (int i = b; i < e; i++) {
            swap(v[i], v[b]);
            per(v, b + 1, e);
            swap(v[i], v[b]);
        }
    }
};