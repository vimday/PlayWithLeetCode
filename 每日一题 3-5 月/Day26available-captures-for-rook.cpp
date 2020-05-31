/*
 * @Author      :vimday
 * @Desc        :lc day 26
 * @Url         :https://leetcode-cn.com/problems/available-captures-for-rook/
 * @File Name   :Day26available-captures-for-rook.cpp
 * @Created Time:2020-03-26 00:08:54
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
    int numRookCaptures(vector<vector<char>>& bd) {
        int m = bd.size(), n = bd[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (bd[i][j] == 'R') {
                    int res = 0;
                    int x = i - 1;
                    while (x >= 0 && bd[x][j] == '.') x--;
                    if (x >= 0 && bd[x][j] == 'p')
                        res++;
                    x = i + 1;
                    while (x < n && bd[x][j] == '.') x++;
                    if (x < n && bd[x][j] == 'p')
                        res++;
                    x = j + 1;
                    while (x < m && bd[i][x] == '.') x++;
                    if (x < m && bd[i][x] == 'p')
                        res++;
                    x = j - 1;
                    while (x >= 0 && bd[i][x] == '.') x--;
                    if (x >= 0 && bd[i][x] == 'p')
                        res++;
                    return res;
                }
            }
        return 0;
    }
};