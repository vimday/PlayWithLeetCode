/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0920_subsets.cpp
 * @Created Time:2020-09-20 17:15:02
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
    int n;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> t;
        n = nums.size();
        dfs(nums, t, 0);
        return res;
    }
    void dfs(vector<int>& nums, vector<int>& t, int b) {
        if (t.size() <= n)
            res.push_back(t);
        for (int i = b; i < n; i++) {
            t.push_back(nums[i]);
            dfs(nums, t, i + 1);
            t.pop_back();
        }
    }
};