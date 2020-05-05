/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day67.cpp
 * @Created Time:2020-05-06 00:32:49
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
    int mincostTickets(vector<int>& ds, vector<int>& cs) {
        int n = ds.size();
        if (n == 0) return 0;
        int mn = min(cs[0], min(cs[1], cs[2]));
        int dp[n];
        memset(dp, 0, sizeof dp);
        dp[0] = mn;
        for (int i = 1; i < n; i++) {
            //case 1 单独买1天的
            int c1 = dp[i - 1] + mn, c2 = INT_MAX, c3 = INT_MAX, td = ds[i];
            //case 2 上一次（第days[j] 天）买了7天 且能延续到今天
            for (int j = i - 1; j >= 0 && ds[j] + 7 > td; j--)
                c2 = min(c2, cs[1] + (j > 0 ? dp[j - 1] : 0));
            //case 3 上一次（第days[j] 天）买了30天 且能延续到今天
            for (int j = i - 1; j >= 0 && ds[j] + 30 > td; j--)
                c3 = min(c2, cs[2] + (j > 0 ? dp[j - 1] : 0));
            dp[i] = min(c1, min(c2, c3));
        }
        return dp[n - 1];
    }
};