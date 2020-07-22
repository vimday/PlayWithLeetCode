/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0723_dp_minimum-path-sum.cpp
 * @Created Time:2020-07-23 00:11:00
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
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 1; i < m; ++i)
            grid[i][0] += grid[i - 1][0];
        for (int i = 1; i < n; ++i)
            grid[0][i] += grid[0][i - 1];
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                grid[i][j] = grid[i][j] + min(grid[i - 1][j], grid[i][j - 1]);

        return grid[m - 1][n - 1];
    }
};