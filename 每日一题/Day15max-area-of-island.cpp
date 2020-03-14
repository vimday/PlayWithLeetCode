/*
 * @Author      :vimday
 * @Desc        :lc 695岛屿最大面积
 * @Url         :https://leetcode-cn.com/problems/max-area-of-island/
 * @File Name   :Day15max-area-of-island.cpp
 * @Created Time:2020-03-15 00:16:40
 * @E-mail      :lwftx@outlook.com
 * @GitHub      :https://github.com/vimday
 */
#include <bits/stdc++.h>
using namespace std;
void debug()
{
#ifdef LOCAL
    freopen("E:\\Cpp\\in.txt", "r", stdin);
    freopen("E:\\Cpp\\out.txt", "w", stdout);
#endif
}
class Solution
{
public:
    int m, n, d[5] = {-1, 0, 1, 0, -1};
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        m = grid.size();
        if (m == 0)
            return 0;
        n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j])
                    res = max(res, dfs(grid, i, j));
        return res;
    }
    int dfs(vector<vector<int>> &g, int i, int j)
    {
        g[i][j] = 0;
        int cs = 1;
        for (int k = 0; k < 4; k++)
        {
            int r = i + d[k], c = j + d[k + 1];
            if (r >= 0 && r < m && c >= 0 && c < n && g[r][c])
                cs += dfs(g, r, c);
        }
        return cs;
    }
};