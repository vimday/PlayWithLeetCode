/*
 * @Author      :vimday
 * @Desc        :lc 周赛180 A
 * @Url         :https://leetcode-cn.com/problems/lucky-numbers-in-a-matrix/
 * @File Name   :A-lucky-numbers-in-a-matrix.cpp
 * @Created Time:2020-03-15 12:25:23
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
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return {};
        int n = matrix[0].size();
        vector<int> res;
        for (int i = 0; i < m; i++) {
            int idx = 0, cur = matrix[i][0];
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] < cur) {
                    cur = matrix[i][j];
                    idx = j;
                }
            }
            bool f = false;
            for (int k = 0; k < m; k++)
                if (matrix[k][idx] > cur) {
                    f = true;
                    break;
                }
            if (!f) res.push_back(cur);
        }
        return res;
    }
};
//by wlp
class Solution {
    int a[55], b[55];
    vector<int> ans;

public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), i, j;
        memset(a, 127, sizeof(a));
        memset(b, 0, sizeof(b));
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++) {
                a[i] = min(a[i], matrix[i][j]);
                b[j] = max(b[j], matrix[i][j]);
            }
        ans.clear();
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                if (a[i] == matrix[i][j] && b[j] == matrix[i][j]) ans.push_back(matrix[i][j]);
        return ans;
    }
};