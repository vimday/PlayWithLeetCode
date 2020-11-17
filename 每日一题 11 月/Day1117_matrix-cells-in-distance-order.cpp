/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1117_matrix-cells-in-distance-order.cpp
 * @Created Time:2020-11-17 15:11:47
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
//或者 bfs
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> vvi;
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j) {
                vvi.push_back({i, j});
            }
        sort(vvi.begin(), vvi.end(), [&](vector<int>& a, vector<int>& b) { return abs(a[0] - r0) + abs(a[1] - c0) < abs(b[0] - r0) + abs(b[1] - c0); });
        return vvi;
    }
};