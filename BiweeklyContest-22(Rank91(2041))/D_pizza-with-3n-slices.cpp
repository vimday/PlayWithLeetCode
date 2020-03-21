/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :D_pizza-with-3n-slices.cpp
 * @Created Time:2020-03-22 00:04:29
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
    int f[500][500][2];

    int maxSizeSlices(vector<int>& slices) {
        memset(f, 0, sizeof(f));
        f[1][1][1] = slices[0];
        for (int i = 2; i <= slices.size(); ++i) {
            for (int j = 1; j <= max(i, (int)slices.size() / 3); ++j) {
                f[i][j][0] = f[i - 1][j][0];
                f[i][j][1] = f[i - 1][j][1];
                f[i][j][0] = max(f[i][j][0], f[i - 2][j - 1][0] + slices[i - 1]);
                f[i][j][1] = max(f[i][j][1], f[i - 2][j - 1][1] + slices[i - 1]);
            }
        }
        return max(f[slices.size()][slices.size() / 3][0], f[slices.size() - 1][slices.size() / 3][1]);
    }
};