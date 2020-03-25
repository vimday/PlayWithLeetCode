/*
 * @Author      :vimday
 * @Desc        :kmp应用
 * @Url         :https://leetcode-cn.com/problems/longest-happy-prefix/
 * @File Name   :D-longest-happy-prefix.cpp
 * @Created Time:2020-03-25 16:50:25
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
//prefix_func
class Solution {
    int ne[100005];
    string ans;

public:
    string longestPrefix(string s) {
        int n = s.size(), i, j;
        for (ne[1] = j = 0, i = 2; i <= n; i++) {
            while (j && s[j] != s[i - 1]) j = ne[j];
            if (s[j] == s[i - 1]) j++;
            ne[i] = j;
        }
        ans.clear();
        for (i = 0; i < ne[n]; i++) ans += s[i];
        return ans;
    }
};
class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        int dp[n];
        memset(dp, 0, sizeof dp);
        for (int i = 1; i < n; i++) {
            int j = dp[i - 1];
            while (j > 0 && s[j] != s[i]) j = dp[j - 1];
            if (s[i] == s[j]) j++;
            dp[i] = j;
        }
        return s.substr(0, dp[n - 1]);
    }
};

//应用 kmp
class Solution {
public:
    int strStr(string t, string s) {
        int n = s.size();
        if (n == 0) return 0;
        int dp[n + 1];
        memset(dp, 0, sizeof dp);
        dp[0] = -1;
        dp[1] = 0;
        for (int i = 1; i < n; i++) {
            int j = dp[i];
            while (j > 0 && s[j] != s[i]) j = dp[j];
            if (s[i] == s[j])
                j++;
            dp[i + 1] = j;
        }
        int i = 0, j = 0, m = t.size();
        while (i < m && j < n) {
            if (j == -1 || t[i] == s[j]) {
                i++;
                j++;
            } else
                j = dp[j];
        }
        if (j == n)
            return i - j;
        return -1;
    }
};
//字符串hash
class Solution {
public:
    typedef unsigned long long ull;
    const ull mod = 29;
    int n;
    int help(string &a, string &b) {
        int res = 0;
        ull ah = 0, bh = 0, t = 1;
        for (int i = 0; i < n; i++) {
            ah = ah * mod + a[i] - 'a';
            bh = bh + (b[n - i - 1] - 'a') * t;
            if (ah == bh)
                res = i + 1;
            t *= mod;
        }
        return res;
    }
    string longestPrefix(string s) {
        n = s.size() - 1;
        string a = s.substr(0, n), b = s.substr(1);
        return s.substr(0, help(a, b));
    }
};

typedef unsigned long long ULL;
class Solution {
public:
    string longestPrefix(string s) {
        int base = 131;
        ULL p[100002];
        p[0] = 1;
        ULL hash[100002];
        hash[0] = 0;
        for (int i = 1; i <= s.size(); i++) {
            hash[i] = hash[i - 1] * base + s[i - 1] - 'a' + 1;
            p[i] = p[i - 1] * base;
        }
        for (int i = s.size() - 1; i >= 1; i--) {
            ULL pre = hash[i];
            ULL suf = hash[s.size()] - hash[s.size() - i] * p[i];
            if (pre == suf) {
                return s.substr(0, i);
            }
        }
        return "";
    }
};

//c++17
class Solution {
public:
    string longestPrefix(string s) {
        string_view prefix = s;
        string_view suffix = s;
        for (int i = s.size() - 1; i > 0; --i) {
            suffix.remove_prefix(1);
            prefix.remove_suffix(1);
            if (prefix == suffix) {
                return string(prefix);
            }
        }

        return string();
    }
};

//c++14
class Solution {
public:
    string longestPrefix(string s) {
        auto prefixEnd = s.end();
        auto suffixBegin = s.begin();
        for (int i = s.size() - 1; i > 0; --i) {
            --prefixEnd;
            ++suffixBegin;
            if (equal(s.begin(), prefixEnd, suffixBegin, s.end())) {
                return string(s.begin(), prefixEnd);
            }
        }

        return string();
    }
};

//py暴力能过
// class Solution:
//     def longestPrefix(self, s: str) -> str:
//         n = len(s)
//         for i in range(n - 1, 0, -1):
//             if s.endswith(s[:i]):
//                 return s[-i:]
//         return ""

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

class Solution {
public:
    int nxt[100010];

    string longestPrefix(string s) {
        calcNext(s, nxt);
        int len = nxt[sz(s) - 1];
        s = s.substr(0, len + 1);
        return s;
    }
};