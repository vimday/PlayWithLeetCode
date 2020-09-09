/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0909_combination-sum.cpp
 * @Created Time:2020-09-09 22:59:12
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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //并不是完全背包问题 完全背包是求总数用的
        if (candidates.size() == 0) return {};
        vector<int> tmp;
        dfs(candidates, tmp, 0, target);
        return res;
    }

    void dfs(vector<int>& v, vector<int>& t, int b, int e) {
        if (e == 0) {
            res.emplace_back(t);
            return;
        }
        int n = v.size();
        for (int i = b; i < n; ++i) {
            if (v[i] <= e) {
                t.emplace_back(v[i]);
                dfs(v, t, i, e - v[i]);
                t.pop_back();
            }
        }
    }
};