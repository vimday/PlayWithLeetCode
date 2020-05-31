/*
 * @Author      :vimday
 * @Desc        :编辑距离动态规划
 * @Url         :https://leetcode-cn.com/problems/edit-distance/
 * @File Name   :Day37edit-distance.cpp
 * @Created Time:2020-04-06 00:05:17
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
    int minDistance(string word1, string word2) {
        if (word1 == word2) return 0;
        int m = word1.size(), n = word2.size();
        if (m == 0 || n == 0) return m + n;
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= m; ++i) dp[i][0] = i;
        for (int i = 1; i <= n; ++i) dp[0][i] = i;
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
        return dp[m][n];
    }
};

class Solution {
public:
    int min1(int a, int b, int c) {
        int temp = a < b ? a : b;
        return temp < c ? temp : c;
    }
    int minDistance(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();
        int dis[size1 + 1][size2 + 1];
        for (int i = 0; i <= size1; i++) {
            for (int j = 0; j <= size2; j++) {
                if (i == 0)
                    dis[i][j] = j;
                else if (j == 0)
                    dis[i][j] = i;
                else {
                    if (word1[i - 1] == word2[j - 1]) {
                        dis[i][j] = 1 + min1(dis[i - 1][j], dis[i][j - 1], dis[i - 1][j - 1] - 1);
                    } else
                        dis[i][j] = 1 + min1(dis[i - 1][j], dis[i][j - 1], dis[i - 1][j - 1]);
                }
            }
        }
        return dis[size1][size2];
    }
};