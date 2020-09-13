/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0913_word_search.cpp
 * @Created Time:2020-09-13 22:40:57
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
    int d[5] = {-1, 0, 1, 0, -1}, sz, m, n;
    bool exist(vector<vector<char>>& bd, string wd) {
        m = bd.size();
        if (m == 0) return false;
        n = bd[0].size();
        sz = wd.size();
        if (sz == 0) return true;
        vector<vector<bool>> me(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (bd[i][j] == wd[0] && dfs(bd, me, wd, i, j, 0))
                    return true;
        return false;
    }
    bool dfs(vector<vector<char>>& g, vector<vector<bool>>& me, string& s, int i, int j, int t) {
        if (t == sz - 1)
            return true;
        me[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int r = i + d[k], c = j + d[k + 1];
            if (r >= 0 && r < m && c >= 0 && c < n && g[r][c] == s[t + 1] && !me[r][c] && dfs(g, me, s, r, c, t + 1)) {
                me[i][j] = false;
                return true;
            }
        }
        me[i][j] = false;
        return false;
    }
};