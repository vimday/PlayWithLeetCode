/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :AAA.cpp
 * @Created Time:2020-09-05 22:30:40
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
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += mat[i][i];
            mat[i][i] = 0;
        }
        for (int i = 0; i < n; i++) {
            res += mat[i][n - i - 1];
        }
        return res;
    }
};