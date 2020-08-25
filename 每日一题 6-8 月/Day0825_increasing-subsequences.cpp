/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0825_increasing-subsequences.cpp
 * @Created Time:2020-08-25 22:21:11
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
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return {};
        vector<int> t;
        dfs(nums, 0, n, t);
        //vector<vector<int>> ret(res.begin(),res.end());
        return res;
    }
    void dfs(vector<int>& v, int idx, int sz, vector<int>& t) {
        if (idx == sz && t.size() > 1) {
            res.push_back(t);
            return;
        }
        if (idx >= sz) return;
        if (t.empty() || v[idx] >= t.back()) {
            t.emplace_back(v[idx]);

            dfs(v, idx + 1, sz, t);
            t.pop_back();
        }
        if (t.empty() || v[idx] != t.back())
            dfs(v, idx + 1, sz, t);
    }
};