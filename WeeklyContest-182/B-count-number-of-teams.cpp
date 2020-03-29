/*
 * @Author      :vimday
 * @Desc        :dp
 * @Url         :https://leetcode-cn.com/problems/count-number-of-teams/comments/
 * @File Name   :B-count-number-of-teams.cpp
 * @Created Time:2020-03-29 15:39:53
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
//dp
class Solution {
public:
    int numTeams(vector<int>& rg) {
        int dp1[205][3] = {0}, dp2[205][3] = {0};
        int res = 0, n = rg.size();
        for (int i = 0; i < n; i++)
            dp1[i][0] = dp2[i][0] = 1;
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++) {
                if (rg[j] > rg[i]) {
                    dp1[j][1] += dp1[i][0];
                    dp1[j][2] += dp1[i][1];
                } else if (rg[j] < rg[i]) {
                    dp2[j][1] += dp2[i][0];
                    dp2[j][2] += dp2[i][1];
                }
            }
        for (int i = 0; i < n; i++)
            res += dp1[i][2] + dp2[i][2];
        return res;
    }
};

//bf
class Solution {
public:
    int numTeams(vector<int>& rg) {
        int res = 0;
        int n = rg.size();
        for (int i = 0; i < n - 2; i++)
            for (int j = i + 1; j < n - 1; j++)
                for (int k = j + 1; k < n; k++)
                    if ((rg[i] < rg[j] && rg[j] < rg[k]) || (rg[i] > rg[j] && rg[j] > rg[k]))
                        res++;
        return res;
    }
};