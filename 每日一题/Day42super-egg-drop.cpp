/*
 * @Author      :vimday
 * @Desc        :lc day42 经典dp  扔鸡蛋
 * @Url         :https://leetcode-cn.com/problems/super-egg-drop/submissions/
 * @File Name   :Day42super-egg-drop.cpp
 * @Created Time:2020-04-11 00:34:59
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
// class Solution {
// public:
//     int superEggDrop(int K, int N) {
//         vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
//         int m = 0;
//         while (dp[m][K] < N) {
//             m++;
//             for (int k = 1; k <= K; ++k)
//                 dp[m][k] = dp[m - 1][k - 1] + dp[m - 1][k] + 1;
//         }
//         return m;
//     }
// };

class Solution {
public:
    int superEggDrop(int K, int N) {
        //i个鸡蛋，j次最多能确认多少层
        //dp[i][j]=dp[i-1][j-1]+dp[i][j-1]+1;
        int dp[K + 1][N + 1];
        memset(dp, 0, sizeof dp);
        int j = 0;
        while (dp[K][j] < N) {
            j++;
            for (int i = 1; i <= K; i++)
                dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1] + 1;
            //j++;
        }
        return j;
    }
};