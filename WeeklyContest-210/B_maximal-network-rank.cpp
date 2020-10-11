/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :BBB.cpp
 * @Created Time:2020-10-11 11:28:40
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
    int g[102][102];
    int cnt[102];
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        memset(g, 0, sizeof g);
        memset(cnt, 0, sizeof cnt);
        for (vector<int>& v : roads) {
            int a = v[0], b = v[1];
            g[a][b] = g[b][a] = 1;
            cnt[a]++;
            cnt[b]++;
        }
        int res = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                res = max(res, cnt[i] + cnt[j] - g[i][j]);
        return res;
    }
};