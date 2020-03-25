/*
 * @Author      :vimday
 * @Desc        :检查网格中是否存在有效路径
 * @Url         :https://leetcode-cn.com/problems/check-if-there-is-a-valid-path-in-a-grid/
 * @File Name   :C-check-if-there-is-a-valid-path-in-a-grid.cpp
 * @Created Time:2020-03-25 16:44:57
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
    bool hasValidPath(vector<vector<int>> &g) {
        int m = g.size(), n = g[0].size();
        queue<array<int, 4>> q;
        q.push({-1, -1, 0, 0});
        bool me[m][n];
        memset(me, 0, sizeof me);
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            int pi = t[0], pj = t[1], i = t[2], j = t[3];
            if (me[i][j])
                continue;
            me[i][j] = true;
            if (i == m - 1 && j == n - 1) return true;
            int nn = g[i][j];
            if (nn == 1) {
                if (j - 1 >= 0 && pj != j - 1) {
                    int ij = g[i][j - 1];
                    if (ij == 1 || ij == 4 || ij == 6) {
                        q.push({i, j, i, j - 1});
                    }
                }
                if (j + 1 < n && pj != j + 1) {
                    int ij = g[i][j + 1];
                    if (ij == 1 || ij == 3 || ij == 5) {
                        q.push({i, j, i, j + 1});
                    }
                }
            } else if (nn == 2) {
                if (i - 1 >= 0 && pi != i - 1) {
                    int ij = g[i - 1][j];
                    if (ij == 2 || ij == 3 || ij == 4) {
                        q.push({i, j, i - 1, j});
                    }
                }
                if (i + 1 < m && pi != i + 1) {
                    int ij = g[i + 1][j];
                    if (ij == 2 || ij == 5 || ij == 6) {
                        q.push({i, j, i + 1, j});
                    }
                }
            } else if (nn == 3) {
                if (j - 1 >= 0 && pj != j - 1) {
                    int ij = g[i][j - 1];
                    if (ij == 1 || ij == 4 || ij == 6) {
                        q.push({i, j, i, j - 1});
                    }
                }
                if (i + 1 < m && pi != i + 1) {
                    int ij = g[i + 1][j];
                    if (ij == 2 || ij == 5 || ij == 6) {
                        q.push({i, j, i + 1, j});
                    }
                }
            } else if (nn == 4) {
                if (j + 1 < n && pj != j + 1) {
                    int ij = g[i][j + 1];
                    if (ij == 1 || ij == 3 || ij == 5) {
                        q.push({i, j, i, j + 1});
                    }
                }
                if (i + 1 < m && pi != i + 1) {
                    int ij = g[i + 1][j];
                    if (ij == 2 || ij == 5 || ij == 6) {
                        q.push({i, j, i + 1, j});
                    }
                }
            } else if (nn == 5) {
                if (j - 1 >= 0 && pj != j - 1) {
                    int ij = g[i][j - 1];
                    if (ij == 1 || ij == 4 || ij == 6) {
                        q.push({i, j, i, j - 1});
                    }
                }
                if (i - 1 >= 0 && pi != i - 1) {
                    int ij = g[i - 1][j];
                    if (ij == 2 || ij == 3 || ij == 4) {
                        q.push({i, j, i - 1, j});
                    }
                }
            } else if (nn == 6) {
                if (i - 1 >= 0 && pi != i - 1) {
                    int ij = g[i - 1][j];
                    if (ij == 2 || ij == 3 || ij == 4) {
                        q.push({i, j, i - 1, j});
                    }
                }
                if (j + 1 < n && pj != j + 1) {
                    int ij = g[i][j + 1];
                    if (ij == 1 || ij == 3 || ij == 5) {
                        q.push({i, j, i, j + 1});
                    }
                }
            }
        }
        return false;
    }
};

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize(3)
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target("sse3", "sse2", "sse")
#pragma GCC target("avx", "sse4", "sse4.1", "sse4.2", "ssse3")
#pragma GCC target("f16c")
#pragma GCC optimize("inline", "fast-math", "unroll-loops", "no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#pragma GCC diagnostic error "-std=c++14"
#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"

#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fr(x) freopen(x, "r", stdin)
#define fw(x) freopen(x, "w", stdout)
#define iout(x) printf("%d\n", x)
#define lout(x) printf("%lld\n", x)
#define REP(x, l, u) for (ll x = l; x < u; x++)
#define RREP(x, l, u) for (ll x = l; x >= u; x--)
#define complete_unique(a) a.erase(unique(a.begin(), a.end()), a.end())
#define mst(x, a) memset(x, a, sizeof(x))
#define all(a) begin(a), end(a)
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define MP make_pair
#define lowbit(x) ((x) & (-(x)))
#define lson (ind << 1)
#define rson (ind << 1 | 1)
#define se second
#define fi first
#define sz(x) ((int)x.size())
#define EX0 exit(0);

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
using namespace __gnu_pbds;  //required
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef vector<ll> VLL;
typedef vector<int> VI;
const int block_size = 320;
typedef complex<ll> point;
const ll mod = 1e9 + 7;
const ll inf = 1e9 + 7;
const ld eps = 1e-9;
const db PI = atan(1) * 4;

template <typename T>
inline int sign(const T &a) {
    if (a < 0) return -1;
    if (a > 0) return 1;
    return 0;
}

string to_string(string s) { return '"' + s + '"'; }

string to_string(const char *s) { return to_string((string)s); }

string to_string(bool b) { return (b ? "true" : "false"); }

template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define dbg(...) \
    {}
#endif

template <typename T, typename S>
inline bool upmin(T &a, const S &b) { return a > b ? a = b, 1 : 0; }

template <typename T, typename S>
inline bool upmax(T &a, const S &b) { return a < b ? a = b, 1 : 0; }

template <typename T>
inline void in(T &x) {
    x = 0;
    T f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    x *= f;
}

ull twop(ll x) { return 1ULL << x; }

ll MOD(ll a, ll m) {
    a %= m;
    if (a < 0) a += m;
    return a;
}

ll inverse(ll a, ll m) {
    a = MOD(a, m);
    if (a <= 1) return a;
    return MOD((1 - inverse(m, a) * m) / a, m);
}

template <typename A, typename B>
inline void in(A &x, B &y) {
    in(x);
    in(y);
}

template <typename A, typename B, typename C>
inline void in(A &x, B &y, C &z) {
    in(x);
    in(y);
    in(z);
}

template <typename A, typename B, typename C, typename D>
inline void in(A &x, B &y, C &z, D &d) {
    in(x);
    in(y);
    in(z);
    in(d);
}

template <typename T>
T sqr(T x) { return x * x; }

ll gcd(ll a, ll b) {
    while (b != 0) {
        a %= b;
        swap(a, b);
    }
    return abs(a);
}

ll fast(ll a, ll b, ll mod) {
    if (b < 0) a = inverse(a, mod), b = -b;
    ll ans = 1;
    while (b) {
        if (b & 1) {
            b--;
            ans = ans * a % mod;
        } else {
            a = a * a % mod;
            b /= 2;
        }
    }
    return ans % mod;
}

void calcNext(const string &s, int nxt[]) {
    int p = nxt[0] = -1;
    REP(i, 1, sz(s)) {
        while (p != -1 && s[p + 1] != s[i]) p = nxt[p];
        p += s[p + 1] == s[i];
        nxt[i] = p;
    }
}

struct DSU {
    std::vector<int> data;

    void init(int n) { data.assign(n, -1); }

    bool unionSet(int y, int x) {
        x = root(x);
        y = root(y);
        if (x != y) {
            if (data[y] < data[x]) std::swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }

    bool same(int x, int y) { return root(x) == root(y); }

    int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }

    int size(int x) { return -data[root(x)]; }
};

class Solution {
public:
    vector<vector<vector<PII>>> ed;
    //0,1,2,3
    int n, m;

    bool getok(vector<vector<int>> &gr, int x, int y, int dir) {
        if (x < 0 or y < 0 or x >= n or y >= m) return false;
        int v = gr[x][y];
        if (dir == 0) {
            return v == 2 or v == 5 or v == 6;
        }
        if (dir == 1) {
            return v == 2 or v == 3 or v == 4;
        }
        if (dir == 2) {
            return v == 1 or v == 3 or v == 5;
        }
        if (dir == 3) {
            return v == 1 or v == 4 or v == 6;
        }
        return false;
    }
    vector<VI> id;
    DSU bcj;

    int getid(int i, int j) {
        return id[i][j];
    }

    bool hasValidPath(vector<vector<int>> &gr) {
        n = sz(gr), m = sz(gr[0]);
        bcj.init(n * m);
        int cnt = 0;
        id.assign(n, VI(m));
        REP(i, 0, n) {
            REP(j, 0, m) {
                id[i][j] = cnt++;
            }
        }
        REP(i, 0, n) {
            REP(j, 0, m) {
                if (getok(gr, i, j, 1) and getok(gr, i + 1, j, 0)) {
                    bcj.unionSet(getid(i, j), getid(i + 1, j));
                }
                if (getok(gr, i, j, 3) and getok(gr, i, j + 1, 2)) {
                    bcj.unionSet(getid(i, j), getid(i, j + 1));
                }
            }
        }

        return bcj.same(getid(0, 0), getid(n - 1, m - 1));
    }
};

class Solution {
    int h[400005], ne[4000005], p[4000005], m, q[400005], he, ta;
    bool b[400005];
    void add(int x, int y) {
        p[++m] = y;
        ne[m] = h[x];
        h[x] = m;
        p[++m] = x;
        ne[m] = h[y];
        h[y] = m;
    }

public:
    bool hasValidPath(vector<vector<int>> &grid) {
        m = 0;
        memset(h, 0, sizeof(h));
        memset(b, 0, sizeof(b));
        int n = grid.size(), m = grid[0].size(), i, j, s = 1 * (m * 2 + 1) + 1, t = (n * 2 - 1) * (m * 2 + 1) + m * 2 - 1;
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++) {
                if (grid[i][j] == 2 || grid[i][j] == 5 || grid[i][j] == 6) add((i * 2) * (m * 2 + 1) + j * 2 + 1, (i * 2 + 1) * (m * 2 + 1) + j * 2 + 1);
                if (grid[i][j] == 1 || grid[i][j] == 4 || grid[i][j] == 6) add((i * 2 + 1) * (m * 2 + 1) + j * 2 + 1, (i * 2 + 1) * (m * 2 + 1) + j * 2 + 2);
                if (grid[i][j] == 2 || grid[i][j] == 3 || grid[i][j] == 4) add((i * 2 + 1) * (m * 2 + 1) + j * 2 + 1, (i * 2 + 2) * (m * 2 + 1) + j * 2 + 1);
                if (grid[i][j] == 1 || grid[i][j] == 3 || grid[i][j] == 5) add((i * 2 + 1) * (m * 2 + 1) + j * 2 + 1, (i * 2 + 1) * (m * 2 + 1) + j * 2);
            }
        he = ta = 0;
        b[q[ta++] = s] = 1;
        while (he != ta)
            for (j = h[i = q[he++]]; j; j = ne[j])
                if (!b[p[j]]) b[q[ta++] = p[j]] = 1;
        return b[t];
    }
};