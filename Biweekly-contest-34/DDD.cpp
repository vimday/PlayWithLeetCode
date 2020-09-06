/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :DDD.cpp
 * @Created Time:2020-09-05 23:15:49
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
typedef long long ll;
const ll mod = 1e9 + 7;

// 这题感觉是比较经典的背包了

// f[i][j]代表消耗i点代价，移动到j点的方案数，转移就是枚举下一个要移动到的点k，然后

// f[i + abs(position[j] - position[k])][k] += f[i][j]
class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        // vector<int> lidx = locations;
        // unordered_map<int, int> midx;
        // for (int i = 0; i < n; i++)
        //     midx[locations[i]] = i;
        // sort(locations.begin(), locations.end());
        ll dp[fuel + 1][n];
        memset(dp, 0, sizeof dp);
        dp[0][start] = 1;
        for (int i = 1; i <= fuel; i++) {
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++) {
                    if (k == j)
                        continue;
                    int cost = abs(locations[j] - locations[k]);
                    if (i >= cost) {
                        dp[i][j] += dp[i - cost][k];
                        if (dp[i][j] >= mod)
                            dp[i][j] -= mod;
                    }
                }
        }
        ll res = 0;
        for (int i = 0; i <= fuel; i++) {
            res += dp[i][finish];
        }
        return res % mod;
    }
};

// dp，dp[i][j] 表示在第i个城市剩余j的汽油的方案数，比赛时搞错了枚举顺序, 赛后才发现QAQ，太菜了。

// #define ll long long
const int maxn = 210;
const ll mod = 1e9 + 7;
ll dp[maxn][maxn];
class Solution {
public:
    int countRoutes(vector<int>& a, int start, int finish, int fuel) {
        int n = a.size();
        memset(dp, 0, sizeof(dp));
        dp[start][fuel] = 1;
        for (int k = fuel; k >= 0; k--) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j) continue;
                    int d = abs(a[i] - a[j]);
                    if (k - d >= 0) dp[j][k - d] = (dp[j][k - d] + dp[i][k]) % mod;
                }
            }
        }
        ll ans = 0;
        for (int i = 0; i <= fuel; i++) {
            ans = (ans + dp[finish][i]) % mod;
        }
        return (int)ans;
    }
};

class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        start = locations[start];
        finish = locations[finish];
        sort(locations.begin(), locations.end());
        start = lower_bound(locations.begin(), locations.end(), start) - locations.begin();
        finish = lower_bound(locations.begin(), locations.end(), finish) - locations.begin();
        vector<vector<int>> dp(201, vector<int>(locations.size(), 0));
        int N = locations.size();
        int deno = pow(10, 9) + 7;
        //dp：dp[i][j]油量为I时,从位置J出发可以到达finish的种类数
        for (int i = 0; i <= fuel; i++) {
            for (int j = 0; j < N; j++) {
                if (j == finish) {
                    dp[i][j] = 1;
                }
                for (int k = 0; k < N; k++) {
                    if (j == k)
                        continue;
                    int dis = abs(locations[j] - locations[k]);

                    if (dis > i)
                        continue;
                    dp[i][j] += dp[i - dis][k];
                    dp[i][j] %= deno;
                }
            }
        }
        return dp[fuel][start];
    }
};

typedef long long ll;
int dp[105][205];
const int MOD = 1e9 + 7;
class Solution {
public:
    int dfs(vector<int>& locations, int start, int finish, int fuel) {
        if (dp[start][fuel] != -1) return dp[start][fuel];
        ll ans = 0;
        int len = locations.size();
        if (start == finish) ans++;
        for (int i = 0; i < len; i++) {
            int diff = abs(locations[i] - locations[start]);
            if (start == i) continue;
            if (fuel - diff >= 0) {
                ans = (ans + dfs(locations, i, finish, fuel - diff)) % MOD;
            }
        }
        dp[start][fuel] = (ans % MOD);
        return dp[start][fuel];
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(dp, -1, sizeof(dp));
        return dfs(locations, start, finish, fuel);
    }
};

// 作者：j_strawhat-2
// 链接：https://leetcode-cn.com/problems/count-all-possible-routes/solution/c-ji-yi-hua-sou-suo-by-j_strawhat-2/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。