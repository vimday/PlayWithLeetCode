/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0920_dfs_minesweeper.cpp
 * @Created Time:2020-08-20 00:07:26
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
    int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    vector<vector<char>> updateBoard(vector<vector<char>>& bd, vector<int>& ck) {
        m = bd.size();
        n = bd[0].size();
        if (bd[ck[0]][ck[1]] == 'M') {
            bd[ck[0]][ck[1]] = 'X';
            return bd;
        }
        dfs(bd, ck[0], ck[1]);
        return bd;
    }
    void dfs(vector<vector<char>>& bd, int i, int j) {
        int b = 0;
        for (int k = 0; k < 8; ++k) {
            int r = i + dx[k], c = j + dy[k];
            if (r >= 0 && r < m && c >= 0 && c < n)
                if (bd[r][c] == 'M')
                    b++;
        }
        bd[i][j] = b == 0 ? 'B' : '0' + b;
        if (b == 0)
            for (int k = 0; k < 8; ++k) {
                int r = i + dx[k], c = j + dy[k];
                if (r >= 0 && r < m && c >= 0 && c < n)
                    if (bd[r][c] == 'E')
                        dfs(bd, r, c);
            }
    }
};