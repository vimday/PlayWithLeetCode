/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0911_combination-sum-ii.cpp
 * @Created Time:2020-09-11 09:49:22
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
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> tmp;
        dfs(tmp, 1, n, k);
        return res;
    }
    void dfs(vector<int>& t, int b, int e, int k) {
        if (e == 0 && k == 0) {
            res.emplace_back(t);
            return;
        }
        for (int i = b; i <= 9; ++i) {
            if (i <= e) {
                t.emplace_back(i);
                dfs(t, i + 1, e - i, k - 1);
                t.pop_back();
            }
        }
    }
};