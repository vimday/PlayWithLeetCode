//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize(3)
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC target("sse3","sse2","sse")
//#pragma GCC target("avx","sse4","sse4.1","sse4.2","ssse3")
//#pragma GCC target("f16c")
//#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
//#pragma GCC diagnostic error "-fwhole-program"
//#pragma GCC diagnostic error "-fcse-skip-blocks"
//#pragma GCC diagnostic error "-funsafe-loop-optimizations"
//#pragma GCC diagnostic error "-std=c++14"
#include "bits/stdc++.h"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/pb_ds/assoc_container.hpp"

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
using namespace __gnu_pbds; //required
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
inline int sign(const T &a)
{
    if (a < 0)
        return -1;
    if (a > 0)
        return 1;
    return 0;
}

string to_string(string s) { return '"' + s + '"'; }

string to_string(const char *s) { return to_string((string)s); }

string to_string(bool b) { return (b ? "true" : "false"); }

template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }

template <typename A>
string to_string(A v)
{
    bool first = true;
    string res = "{";
    for (const auto &x : v)
    {
        if (!first)
        {
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
void debug_out(Head H, Tail... T)
{
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define dbg(...) \
    {            \
    }
#endif

template <typename T, typename S>
inline bool upmin(T &a, const S &b)
{
    return a > b ? a = b, 1 : 0;
}

template <typename T, typename S>
inline bool upmax(T &a, const S &b) { return a < b ? a = b, 1 : 0; }

template <typename T>
inline void in(T &x)
{
    x = 0;
    T f = 1;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    x *= f;
}

ull twop(ll x) { return 1ULL << x; }

ll MOD(ll a, ll m)
{
    a %= m;
    if (a < 0)
        a += m;
    return a;
}

ll inverse(ll a, ll m)
{
    a = MOD(a, m);
    if (a <= 1)
        return a;
    return MOD((1 - inverse(m, a) * m) / a, m);
}

template <typename A, typename B>
inline void in(A &x, B &y)
{
    in(x);
    in(y);
}

template <typename A, typename B, typename C>
inline void in(A &x, B &y, C &z)
{
    in(x);
    in(y);
    in(z);
}

template <typename A, typename B, typename C, typename D>
inline void in(A &x, B &y, C &z, D &d)
{
    in(x);
    in(y);
    in(z);
    in(d);
}

template <typename T>
T sqr(T x) { return x * x; }

ll gcd(ll a, ll b)
{
    while (b != 0)
    {
        a %= b;
        swap(a, b);
    }
    return abs(a);
}

ll fast(ll a, ll b, ll mod)
{
    if (b < 0)
        a = inverse(a, mod), b = -b;
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            b--;
            ans = ans * a % mod;
        }
        else
        {
            a = a * a % mod;
            b /= 2;
        }
    }
    return ans % mod;
}
class Solution
{
public:
    int maxStudents(vector<vector<char>> &seats)
    {
        int m = sz(seats[0]);
        VI dp(twop(m), 0);
        for (auto row : seats)
        {
            VI tmp(twop(m), 0);
            REP(from, 0, twop(m))
            {
                REP(state, 0, twop(m))
                {
                    bool ok = 1;
                    REP(j, 0, m)
                    {
                        if ((state & twop(j)) and row[j] == '#')
                            ok = 0;
                    }
                    REP(j, 1, m)
                    {
                        if ((state & twop(j)) and (state & twop(j - 1)))
                            ok = 0;
                        if ((state & twop(j)) and (from & twop(j - 1)))
                            ok = 0;
                    }
                    REP(j, 0, m - 1)
                    {
                        if ((state & twop(j)) and (from & twop(j + 1)))
                            ok = 0;
                    }
                    if (ok)
                    {
                        upmax(tmp[state], dp[from] + __builtin_popcountll(state));
                    }
                }
            }
            swap(tmp, dp);
        }
        return *max_element(all(dp));
    }
};
class Solution
{
    int o[256], f[9][256], a[9];

public:
    int maxStudents(vector<vector<char>> &seats)
    {
        int n = seats.size(), m = seats[0].size(), i, j, k, ans = 0;
        for (i = 1; i < 256; i++)
            o[i] = o[i >> 1] + (i & 1);
        memset(f, 128, sizeof(f));
        memset(a, 0, sizeof(a));
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                if (seats[i][j] == '#')
                    a[i] |= 1 << j;
        for (i = f[0][0] = 0; i < n; i++)
            for (j = 0; j < 1 << m; j++)
                if (!(j & a[i]) && !(j & j >> 1) && !(j & j << 1))
                    for (k = 0; k < 1 << m; k++)
                        if (!(j & k >> 1) && !(j & k << 1))
                            f[i + 1][j] = max(f[i + 1][j], f[i][k] + o[j]);
        for (i = 0; i < 1 << m; i++)
            ans = max(ans, f[n][i]);
        return ans;
    }
};