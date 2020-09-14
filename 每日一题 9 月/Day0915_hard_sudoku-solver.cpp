/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0915_hard_sudoku-solver.cpp
 * @Created Time:2020-09-15 00:18:12
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
    void solveSudoku(vector<vector<char>>& board) {
        bool grid[9][9] = {false};
        bool row[9][9] = {false};
        bool col[9][9] = {false};
        vector<int> blank;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char v = board[i][j];
                if (v == '.') {
                    blank.push_back(i * 9 + j);
                } else {
                    row[i][v - '1'] = true;
                    col[j][v - '1'] = true;
                    grid[i / 3 * 3 + j / 3][v - '1'] = true;
                }
            }
        }
        process(board, grid, row, col, blank, 0);
    }

    bool process(vector<vector<char>>& board, bool grid[9][9], bool row[9][9], bool col[9][9], vector<int>& blank, int index) {
        if (index == blank.size()) {
            return true;
        }

        int ix = blank[index];
        int r = ix / 9;
        int c = ix % 9;

        for (int i = 0; i < 9; i++) {
            if (!row[r][i] && !col[c][i] && !grid[r / 3 * 3 + c / 3][i]) {
                row[r][i] = col[c][i] = grid[r / 3 * 3 + c / 3][i] = true;
                board[r][c] = '1' + i;
                if (process(board, grid, row, col, blank, index + 1)) {
                    return true;
                }
                row[r][i] = col[c][i] = grid[r / 3 * 3 + c / 3][i] = false;
            }
        }

        return false;
    }
};
class Solution {
public:
    bool can(vector<vector<char>>& g, int i, int j, int val) {
        for (int k = 0; k < 9; ++k) {
            if (g[i][k] != '.' && g[i][k] - '0' == val)
                return false;
            if (g[k][j] != '.' && g[k][j] - '0' == val)
                return false;
        }
        int r = i / 3, c = j / 3;
        for (int x = 3 * r; x < 3 * r + 3; ++x)
            for (int y = 3 * c; y < 3 * c + 3; ++y) {
                if (g[x][y] != '.' && g[x][y] - '0' == val)
                    return false;
            }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        bool m = false;
        dfs(board, 0, 0, m);
    }
    void dfs(vector<vector<char>>& g, int i, int j, bool& m) {
        if (i > 8 && j > 8) {
            m = true;
            return;
        }
        if (i > 8 || j > 8)
            return;
        if (g[i][j] != '.') {
            if (j < 8) {
                dfs(g, i, j + 1, m);
                if (m)
                    return;
            } else if (i < 8) {
                dfs(g, i + 1, 0, m);
                if (m)
                    return;
            }
            if (i >= 8 && j >= 8) {
                m = true;
                return;
            }
        } else {
            for (int v = 1; v <= 9; ++v) {
                if (can(g, i, j, v)) {
                    g[i][j] = '0' + v;
                    if (i >= 8 && j >= 8) {
                        m = true;
                        return;
                    }
                    if (j < 8) {
                        dfs(g, i, j + 1, m);
                        if (m)
                            return;
                        g[i][j] = '.';

                    } else if (i < 8) {
                        dfs(g, i + 1, 0, m);
                        if (m)
                            return;
                        g[i][j] = '.';
                    }
                }
            }
        }
    }
};