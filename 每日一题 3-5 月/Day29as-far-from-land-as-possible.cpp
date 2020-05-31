/*
 * @Author      :vimday
 * @Desc        :多源最短路径
 * @Url         :https://leetcode-cn.com/problems/as-far-from-land-as-possible/submissions/
 * @File Name   :Day29as-far-from-land-as-possible.cpp
 * @Created Time:2020-03-29 00:09:06
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
    int d[5] = {-1, 0, 1, 0, -1};
    int maxDistance(vector<vector<int>>& g) {
        int m = g.size();
        queue<array<int, 2>> q;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
                if (g[i][j])
                    q.push({i, j});
        int n = q.size(), res = -1;
        if (n == 0 || n == m * m) return -1;
        while (!q.empty()) {
            n = q.size();
            res++;
            while (n--) {
                auto p = q.front();
                q.pop();
                int i = p[0], j = p[1];
                for (int k = 0; k < 4; k++) {
                    int r = i + d[k], c = j + d[k + 1];
                    if (r >= 0 && r < m && c >= 0 && c < m && g[r][c] == 0) {
                        g[r][c] = 1;
                        q.push({r, c});
                    }
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    int d[5] = {-1, 0, 1, 0, -1};
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1) return -1;
        int res = -1;
        int memo[n][n];
        memset(memo, 0, sizeof memo);
        queue<array<int, 2>> q;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                    int cs = 0;
                    memo[i][j] = 1;
                    //vector<vector<int>> tm(n,vector<int>(n,0));
                    bool f = false;  //tm[i][j]=1;
                    while (!q.empty()) {
                        int sz = q.size();
                        while (sz--) {
                            auto t = q.front();
                            q.pop();
                            int x = t[0], y = t[1];
                            for (int k = 0; k < 4; ++k) {
                                int r = x + d[k], c = y + d[k + 1];
                                if (r >= 0 && c >= 0 && r < n && c < n) {
                                    if (grid[r][c] == 1 && !f) {
                                        cs += abs(r - i) + abs(c - j);
                                        //cout<<cs;
                                        f = true;
                                        if (cs > res) res = cs;
                                        break;
                                    } else if (grid[r][c] == 0 && memo[r][c] == 0 && !f) {
                                        q.push({r, c});
                                        memo[r][c] = 1;
                                    }
                                }
                            }
                        }
                    }
                    memset(memo, 0, sizeof(memo));
                }
            }
        return res;
    }
};
