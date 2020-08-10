/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0811_surrounded-regions.cpp
 * @Created Time:2020-08-11 00:24:25
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
    int v[5] = {-1, 0, 1, 0, -1};
    void solve(vector<vector<char>>& board) {
        m = board.size();
        if (m == 0) return;
        n = board[0].size();
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O')
                dfs(board, i, 0);
            if (board[i][n - 1] == 'O')
                dfs(board, i, n - 1);
        }
        for (int i = 1; i < n - 1; ++i) {
            if (board[0][i] == 'O')
                dfs(board, 0, i);
            if (board[m - 1][i] == 'O')
                dfs(board, m - 1, i);
        }
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (board[i][j] == 'N')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
    }
    void dfs(vector<vector<char>>& g, int i, int j) {
        g[i][j] = 'N';
        for (int k = 0; k < 4; ++k) {
            int r = i + v[k], c = j + v[k + 1];
            if (r >= 0 && r < m && c >= 0 && c < n && g[r][c] == 'O')
                dfs(g, r, c);
        }
    }
};