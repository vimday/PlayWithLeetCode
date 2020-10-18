/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :CCC.cpp
 * @Created Time:2020-10-18 10:42:41
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
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>> vp;
        vp.push_back(make_pair(-1, 0));
        for (int i = 0; i < n; ++i)
            vp.push_back(make_pair(ages[i], scores[i]));
        sort(vp.begin(), vp.end());
        int dp[n + 1][2];
        memset(dp, 0, sizeof dp);
        //dp[0][1] = vp[0].second;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int ag = vp[i].first, ss = vp[i].second;
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            for (int j = i - 1; j >= 0; j--)
                if (vp[j].second <= ss || (vp[j].first == ag)) {
                    dp[i][1] = max(dp[j][1] + ss, dp[i][1]);
                    //break;
                }
            res = max(res, max(dp[i][0], dp[i][1]));
        }
        return res;
    }
};
typedef long long LL;
typedef double D;
#define all(v) (v).begin(), (v).end()
inline LL fastpo(LL x, LL n, LL mod) {
    LL res(1);
    while (n) {
        if (n & 1) {
            res = res * (LL)x % mod;
        }
        x = x * (LL)x % mod;
        n /= 2;
    }
    return res;
}
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
inline string itoa(int x, int width = 0) {
    string res;
    if (x == 0) res.push_back('0');
    while (x) {
        res.push_back('0' + x % 10);
        x /= 10;
    }
    while ((int)res.size() < width) res.push_back('0');
    reverse(res.begin(), res.end());
    return res;
}
struct P {
    D x, y;
};
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
#define fi first
#define se second
#define ins insert
#define pb push_back

class Solution {
public:
    int bestTeamScore(vector<int>& s, vector<int>& a) {
        int n = s.size();
        vector<int> o(n);
        for (int i = 0; i < n; i++) o[i] = i;
        sort(o.begin(), o.end(), [&](int x, int y) { return a[x] < a[y] || a[x] == a[y] && s[x] < s[y]; });
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = s[o[i]];
            for (int j = 0; j < i; j++) {
                if (s[o[j]] <= s[o[i]]) {
                    dp[i] = max(dp[i], dp[j] + s[o[i]]);
                }
            }
        }
        return *max_element(all(dp));
    }
};