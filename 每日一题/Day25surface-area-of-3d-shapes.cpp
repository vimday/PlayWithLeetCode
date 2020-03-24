/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day25surface-area-of-3d-shapes.cpp
 * @Created Time:2020-03-25 00:42:48
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
    int surfaceArea(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size(), res = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (g[i][j] == 0)
                    continue;
                int ch = g[i][j];
                res += ch * 4 + 2;
                if (j < n - 1) {
                    int nh = g[i][j + 1];
                    res -= 2 * min(ch, nh);
                }
                if (i < m - 1) {
                    int nh = g[i + 1][j];
                    res -= 2 * min(ch, nh);
                }
            }
        return res;
    }
};

class Solution {
public:
    int d[5] = {-1, 0, 1, 0, -1};
    int surfaceArea(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size(), res = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (g[i][j]) {
                    int h = g[i][j];
                    res += 2;
                    for (int k = 0; k < 4; k++) {
                        int r = i + d[k], c = j + d[k + 1];
                        if (r >= 0 && r < m && c >= 0 && c < n && g[r][c]) {
                            res += max(0, h - g[r][c]);
                        } else
                            res += h;
                    }
                }
        return res;
    }
};