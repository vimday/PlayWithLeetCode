/*
 * @Author      :vimday
 * @Desc        :lc day51
 * @Url         :https://leetcode-cn.com/problems/number-of-islands/
 * @File Name   :Day51num-of-islands.cpp
 * @Created Time:2020-04-20 00:02:58
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
    int d[5] = {-1, 0, 1, 0, -1}, m, n;
    int numIslands(vector<vector<char>>& g) {
        m = g.size();
        if (m == 0) return 0;
        n = g[0].size();
        int res = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (g[i][j] == '1') {
                    dfs(g, i, j);
                    res++;
                }
        return res;
    }
    void dfs(vector<vector<char>>& g, int i, int j) {
        g[i][j] = 0;
        for (int k = 0; k < 4; k++) {
            int r = i + d[k], c = j + d[k + 1];
            if (r >= 0 && r < m && c >= 0 && c < n && g[r][c] == '1')
                dfs(g, r, c);
        }
    }
};