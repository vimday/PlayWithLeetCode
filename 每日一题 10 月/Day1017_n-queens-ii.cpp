/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1018_n-queens-ii.cpp
 * @Created Time:2020-10-17 13:28:20
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
    int totalNQueens(int n) {
        bool mr[n], mc[n], mx[2 * n - 1], my[2 * n];
        memset(mr, 0, sizeof mr);
        memset(mc, 0, sizeof mc);
        memset(mx, 0, sizeof mx);
        memset(my, 0, sizeof my);
        vector<vector<bool>> g(n, vector<bool>(n, false));

        function<void(int, int, int &)> dfs = [&](int i, int j, int &res) {
            if (i == n - 1) {
                res++;
                return;
            }
            mr[i] = true;
            mc[j] = true;
            mx[i + j] = true;
            my[i - j + n] = true;
            for (int d = 0; d < n; d++) {
                if (mr[i + 1] || mc[d] || mx[i + 1 + d] || my[i + 1 - d + n])
                    continue;
                dfs(i + 1, d, res);
            }
            mr[i] = false;
            mc[j] = false;
            mx[i + j] = false;
            my[i - j + n] = false;
        };
        int res = 0;
        for (int i = 0; i < n; ++i)
            dfs(0, i, res);
        return res;
    }
};