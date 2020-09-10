/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0910_combination-sum-ii.cpp
 * @Created Time:2020-09-10 23:00:55
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
    //vector<bool> memo;
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.size() == 0) return res;
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        //memo=vector<bool>(n,false);
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
            if (v[i] <= e && (i == b || (i > b && v[i] != v[i - 1]))) {
                //memo[i]=true;
                t.emplace_back(v[i]);
                dfs(v, t, i + 1, e - v[i]);
                t.pop_back();
                //memo[i]=false;
            }
        }
    }
};