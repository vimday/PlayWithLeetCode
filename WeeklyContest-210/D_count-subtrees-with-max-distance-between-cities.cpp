/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :D_count-subtrees-with-max-distance-between-cities.cpp
 * @Created Time:2020-10-11 17:06:32
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
    int d[16][16];
    bool me[16];
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        memset(d, 0x3f, sizeof d);
        for (int i = 1; i <= n; i++)
            d[i][i] = 0;

        vector<int> res(n - 1);
        for (int bit = 1; bit < (1 << n); bit++) {
            memset(d, 0x3f, sizeof d);
            memset(me, 0, sizeof me);
            int idx = 0, c = bit;
            while (c) {
                ++idx;
                if (c & 1)
                    me[idx] = true;
                c >>= 1;
            }
            int mx = 0;
            for (vector<int>& v : edges) {
                int a = v[0], b = v[1];
                d[a][b] = d[b][a] = 1;
            }
            for (int k = 1; k <= n; k++)
                if (me[k])
                    for (int i = 1; i <= n; i++)
                        if (me[i])
                            for (int j = i + 1; j <= n; j++)
                                if (me[j])
                                    d[i][j] = d[j][i] = min(d[i][j], d[i][k] + d[k][j]);

            for (int i = 1; i <= n; i++)
                for (int j = i + 1; j <= n; j++)
                    if (me[i] && me[j]) {
                        mx = max(mx, d[i][j]);
                    }
            if (mx && mx < n)
                res[mx - 1]++;
        }
        return res;
    }
};

//大佬的模板
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
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& e) {
        vector<vector<int>> d(n, vector<int>(n, inf));
        for (int i = 0; i < n; i++) d[i][i] = 0;
        for (auto& t : e) {
            //cout << t[0] << ' ' << t[1] << endl;
            t[0]--;
            t[1]--;
            d[t[0]][t[1]] = 1;
            d[t[1]][t[0]] = 1;
        }
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    d[i][j] = min(d[k][j] + d[i][k], d[i][j]);
        vector<int> ans(n - 1), vst(n);
        for (int msk = 1; msk < (1 << n); msk++) {
            int mx = 0;
            vector<int> q;
            int v = -1;
            for (int i = 0; i < n; i++) {
                if ((msk >> i) % 2 == 0) continue;
                v = i;
                for (int j = 0; j < n; j++) {
                    if ((msk >> j) % 2 == 0) continue;
                    mx = max(mx, d[i][j]);
                }
            }
            for (int i = 0; i < n; i++) {
                vst[i] = 0;
            }

            q.pb(v);
            vst[v] = 1;
            for (int op = 0; op < (int)q.size(); op++) {
                int v = q[op];
                for (int y = 0; y < n; y++) {
                    if (d[v][y] == 1 && (msk >> y) % 2 == 1 && vst[y] == 0) {
                        vst[y] = 1;
                        q.pb(y);
                    }
                }
            }
            if (q.size() != __builtin_popcount(msk)) continue;
            //cout << mx << endl;
            if (mx <= n && mx > 0) ans[mx - 1]++;
        }
        return ans;
    }
};

class Solution {
public:
    void dfs(const vector<vector<int>>& e, vector<int>& seen, vector<int>& ins, int id, int u) {
        seen[u] = id;
        for (int v : e[u]) {
            if (ins[v] && seen[v] != id) {
                dfs(e, seen, ins, id, v);
            }
        }
    }

    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> e(n);
        vector<vector<int>> g(n, vector<int>(n, 666));
        for (const auto& ee : edges) {
            e[ee[0] - 1].push_back(ee[1] - 1);
            e[ee[1] - 1].push_back(ee[0] - 1);
            g[ee[0] - 1][ee[1] - 1] = g[ee[1] - 1][ee[0] - 1] = 1;
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }

        vector<int> ans(n - 1);
        vector<int> seen(n, -1), ins(n);
        for (int i = 1; i < (1 << n); ++i) {
            // cout << "i = " << i << "\n";
            int b = __builtin_popcount(i);
            if (b < 2) {
                continue;
            }
            int u = -1;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    ins[j] = 1;
                    u = j;
                } else {
                    ins[j] = 0;
                }
            }

            dfs(e, seen, ins, i, u);
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (seen[j] == i) {
                    ++cnt;
                }
            }
            if (cnt == b) {
                // cout << "i = " << i << "\n";
                int dd = 0;
                for (int p = 0; p < n; ++p) {
                    if (ins[p]) {
                        for (int q = p + 1; q < n; ++q) {
                            if (ins[q]) {
                                dd = max(dd, g[p][q]);
                            }
                        }
                    }
                }
                ++ans[dd - 1];
            }
        }
        // cout << "good\n";
        return ans;
    }
};
class Solution {
public:
    void dfs(const vector<vector<int>>& e, vector<int>& seen, vector<int>& ins, int id, int u) {
        seen[u] = id;
        for (int v : e[u]) {
            if (ins[v] && seen[v] != id) {
                dfs(e, seen, ins, id, v);
            }
        }
    }

    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> e(n);
        vector<vector<int>> g(n, vector<int>(n, 666));
        for (const auto& ee : edges) {
            e[ee[0] - 1].push_back(ee[1] - 1);
            e[ee[1] - 1].push_back(ee[0] - 1);
            g[ee[0] - 1][ee[1] - 1] = g[ee[1] - 1][ee[0] - 1] = 1;
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }

        vector<int> ans(n - 1);
        vector<int> seen(n, -1), ins(n);
        for (int i = 1; i < (1 << n); ++i) {
            // cout << "i = " << i << "\n";
            int b = __builtin_popcount(i);
            if (b < 2) {
                continue;
            }
            int u = -1;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    ins[j] = 1;
                    u = j;
                } else {
                    ins[j] = 0;
                }
            }

            dfs(e, seen, ins, i, u);
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (seen[j] == i) {
                    ++cnt;
                }
            }
            if (cnt == b) {
                // cout << "i = " << i << "\n";
                int dd = 0;
                for (int p = 0; p < n; ++p) {
                    if (ins[p]) {
                        for (int q = p + 1; q < n; ++q) {
                            if (ins[q]) {
                                dd = max(dd, g[p][q]);
                            }
                        }
                    }
                }
                ++ans[dd - 1];
            }
        }
        // cout << "good\n";
        return ans;
    }
};