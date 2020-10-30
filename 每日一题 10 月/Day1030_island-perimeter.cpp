/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1030_island-perimeter.cpp
 * @Created Time:2020-10-30 11:01:51
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
    int m, n;
    int get(vector<vector<int>>& g, int i, int j) {
        int ret = 0;
        if (i == 0 || g[i - 1][j] == 0) ++ret;
        if (j == 0 || g[i][j - 1] == 0) ++ret;
        if (i == m - 1 || g[i + 1][j] == 0) ++ret;
        if (j == n - 1 || g[i][j + 1] == 0) ++ret;
        return ret;
    }
    int islandPerimeter(vector<vector<int>>& g) {
        m = g.size(), n = g[0].size();
        int res = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (g[i][j])
                    res += get(g, i, j);
        return res;
    }
};