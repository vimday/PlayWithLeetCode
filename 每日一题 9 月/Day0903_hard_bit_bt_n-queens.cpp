/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0903_hard_bit_bt_n-queens.cpp
 * @Created Time:2020-09-03 21:18:21
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
    vector<vector<string>> solveNQueens(int n) {
        auto solutions = vector<vector<string>>();
        auto queens = vector<int>(n, -1);
        solve(solutions, queens, n, 0, 0, 0, 0);
        return solutions;
    }

    void solve(vector<vector<string>> &solutions, vector<int> &queens, int n, int row, int columns, int diagonals1, int diagonals2) {
        if (row == n) {
            auto board = generateBoard(queens, n);
            solutions.push_back(board);
        } else {
            int availablePositions = ((1 << n) - 1) & (~(columns | diagonals1 | diagonals2));
            while (availablePositions != 0) {
                int position = availablePositions & (-availablePositions);
                availablePositions = availablePositions & (availablePositions - 1);
                int column = __builtin_ctz(position);
                queens[row] = column;
                solve(solutions, queens, n, row + 1, columns | position, (diagonals1 | position) >> 1, (diagonals2 | position) << 1);
                queens[row] = -1;
            }
        }
    }

    vector<string> generateBoard(vector<int> &queens, int n) {
        auto board = vector<string>();
        for (int i = 0; i < n; i++) {
            string row = string(n, '.');
            row[queens[i]] = 'Q';
            board.push_back(row);
        }
        return board;
    }
};
class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        if (n == 2 || n == 3 || n == 0) return res;
        vector<string> t(n, string(n, '.'));
        dfs(t, 0, 0);
        return res;
    }
    void dfs(vector<string> &t, int i, int j) {
        int n = t.size();
        if (i >= n && j >= n) {
            res.emplace_back(t);
            return;
        }
        for (int l = 0; l < n; ++l) {
            if (can(t, i, l)) {
                t[i][l] = 'Q';
                dfs(t, i + 1, j + 1);
                t[i][l] = '.';
            }
        }
    }

    bool can(vector<string> &t, int i, int j) {
        int n = t.size();
        for (int x = 0; x < n; ++x) {
            // if(t[i][x]=='Q')
            //     return false;
            if (t[x][j] == 'Q')
                return false;
            if (i + x < n && j + x < n && t[i + x][j + x] == 'Q')
                return false;
            if (i - x >= 0 && j - x >= 0 && t[i - x][j - x] == 'Q')
                return false;
            if (i + x < n && j - x >= 0 && t[i + x][j - x] == 'Q')
                return false;
            if (i - x >= 0 && j + x < n && t[i - x][j + x] == 'Q')
                return false;
        }
        return true;
    }
};