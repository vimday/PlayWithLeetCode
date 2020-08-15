/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0816_flood-fill.cpp
 * @Created Time:2020-08-16 00:13:19
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
    int dp[5] = {-1, 0, 1, 0, -1};
    int m, n;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) return image;
        m = image.size();
        n = image[0].size();
        int cc = image[sr][sc];
        dfs(image, sr, sc, newColor, cc);
        return image;
    }
    void dfs(vector<vector<int>>& g, int i, int j, int c, int cc) {
        g[i][j] = c;
        for (int k = 0; k < 4; ++k) {
            int x = i + dp[k], y = j + dp[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && g[x][y] == cc)
                dfs(g, x, y, c, cc);
        }
    }
};