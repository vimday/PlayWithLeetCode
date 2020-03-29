/*
 * @Author      :vimday
 * @Desc        :find-all-good-strings
 * @Url         :https://leetcode-cn.com/problems/find-all-good-strings/
 * @File Name   :D-find-all-good-strings.cpp
 * @Created Time:2020-03-29 15:53:57
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
    static const long long mod = 1e9 + 7;
    static const int MAX_K = 51;
    static const int MAX_N = 501;

    int N, K;
    string S1, S2, ES;
    int next[MAX_K][26];
    long long dp1[MAX_N][MAX_K][2], dp2[MAX_N][MAX_K][2];

    void getnext() {
        for (int i = 0; i < K; ++i) {
            for (int j = 0; j < 26; ++j) {
                string s = ES.substr(0, i) + char(j + 'a');
                while (ES.substr(0, s.length()) != s) {
                    s = s.substr(1);
                }
                next[i][j] = s.length();
            }
        }
    }

    void solve1(string &s) {
        dp1[0][0][1] = 1;
        dp1[0][0][0] = 0;
        for (int i = 1; i < K; ++i) dp1[0][i][0] = dp1[0][i][1] = 0;
        for (int t = 0; t < N; ++t) {
            for (int i = 0; i < K; ++i) dp1[t + 1][i][0] = dp1[t + 1][i][1] = 0;

            for (int i = 0; i < K; ++i) {
                for (int j = 0; j < 26; ++j) {
                    int ti = next[i][j];
                    if (ti == K) continue;
                    if (j == s[t] - 'a')
                        dp1[t + 1][ti][1] = (dp1[t + 1][ti][1] + dp1[t][i][1]) % mod;
                    else if (j < s[t] - 'a')
                        dp1[t + 1][ti][0] = (dp1[t + 1][ti][0] + dp1[t][i][1]) % mod;
                    dp1[t + 1][ti][0] = (dp1[t + 1][ti][0] + dp1[t][i][0]) % mod;
                }
            }
        }
    }
    void solve2(string &s) {
        dp2[0][0][1] = 1;
        dp2[0][0][0] = 0;
        for (int i = 1; i < K; ++i) dp2[0][i][0] = dp2[0][i][1] = 0;
        for (int t = 0; t < N; ++t) {
            for (int i = 0; i < K; ++i) dp2[t + 1][i][0] = dp2[t + 1][i][1] = 0;

            for (int i = 0; i < K; ++i) {
                for (int j = 0; j < 26; ++j) {
                    int ti = next[i][j];
                    if (ti == K) continue;
                    if (j == s[t] - 'a')
                        dp2[t + 1][ti][1] = (dp2[t + 1][ti][1] + dp2[t][i][1]) % mod;
                    else if (j < s[t] - 'a')
                        dp2[t + 1][ti][0] = (dp2[t + 1][ti][0] + dp2[t][i][1]) % mod;
                    dp2[t + 1][ti][0] = (dp2[t + 1][ti][0] + dp2[t][i][0]) % mod;
                }
            }
        }
    }

    int findGoodStrings(int n, string s1, string s2, string evil) {
        S1 = s1, S2 = s2, ES = evil;
        N = n;
        K = evil.size();
        getnext();
        solve1(s1);
        solve2(s2);
        long long ans = 0;
        for (int i = 0; i < K; ++i) {
            ans = (ans + dp2[N][i][0]) % mod;
            ans = (ans + dp2[N][i][1]) % mod;
        }
        for (int i = 0; i < K; ++i) {
            ans = (ans + mod - dp1[N][i][0]) % mod;
        }
        return ans;
    }
};

// // time complxity O(n * m * m * 26)
// class Solution {

//   public int findGoodStrings(int n, String s1, String s2, String evil) {
//     int mod = (int) 1e9 + 7;
//     int m = evil.length();
//     long[][][] dp = new long[n + 1][4][m + 1]; // 第二维度中， 0表示s1和s2都有限制，1表s1有限制， 2表示s2有限制， 3表示s1和s2无限制； 第三维度表示前面已经匹配的evil的长度
//     // 初始化
//     for (int i = 0; i < m; i++) {
//       dp[n][0][i] = 1;
//       dp[n][1][i] = 1;
//       dp[n][2][i] = 1;
//       dp[n][3][i] = 1;
//     }
//     char[] p = evil.toCharArray();
//     int[] prefix = calcuPrefixFunction(p); // O(n)，计算前缀数组
//     for (int i = n - 1; i >= 0; i--) {
//       for (int j = 0; j < m; j++) {
//         // handle 0
//         for (char k = s1.charAt(i); k <= s2.charAt(i); k++) {
//           int state = 0;
//           if (k == s1.charAt(i) && k == s2.charAt(i)) {
//             state = 0;
//           } else if (k == s1.charAt(i)) {
//             state = 1;
//           } else if (k == s2.charAt(i)) {
//             state = 2;
//           } else {
//             state = 3;
//           }
//           dp[i][0][j] += dp[i + 1][state][getNext(prefix, p, k, j)];
//           dp[i][0][j] %= mod;
//         }
//         // handle 1
//         for (char k = s1.charAt(i); k <= 'z'; k++) {
//           int state = k == s1.charAt(i) ? 1 : 3;
//           dp[i][1][j] += dp[i + 1][state][getNext(prefix, p, k, j)];
//           dp[i][1][j] %= mod;
//         }
//         //handle 2
//         for (char k = 'a'; k <= s2.charAt(i); k++) {
//           int state = k == s2.charAt(i) ? 2 : 3;
//           dp[i][2][j] += dp[i + 1][state][getNext(prefix, p, k, j)];
//           dp[i][2][j] %= mod;
//         }
//         // handle 3
//         for (char k = 'a'; k <= 'z'; k++) {
//           int state = 3;
//           dp[i][3][j] += dp[i + 1][state][getNext(prefix, p, k, j)];
//           dp[i][3][j] %= mod;
//         }
//       }
//     }
//     return (int) dp[0][0][0];
//   }

//   private int[] calcuPrefixFunction(char[] p) { // 考虑边界情况， 即p的长度为0
//     int n = p.length;
//     int[] prefixArray = new int[n];  // 表示匹配的长度结果
//     prefixArray[0] = 0;
//     int j = 0;  // len of match string 表示匹配的长度
//     for (int i = 1; i < n; i++) {
//       while (j > 0 && p[i] != p[j]) {
//         j = prefixArray[j - 1];
//       }
//       if (p[i] == p[j]) {
//         j++;
//       }
//       prefixArray[i] = j;
//     }
//     return prefixArray;
//   }

//   private int getNext(int[] prefix, char[] p, char c, int j) {
//     while (j > 0 && c != p[j]) {
//       j = prefix[j - 1];
//     }
//     if (c == p[j]) {
//       j++;
//     }
//     return j;
//   }
// }

// 作者：HenryLee4
// 链接：https://leetcode-cn.com/problems/find-all-good-strings/solution/shu-wei-dp-kmpqian-zhui-shu-zu-java-by-henrylee4/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

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

int tr[60][26];
int fail[60];
int n;

void calcNext(string s) {
    n = sz(s);
    s = " " + s;
    fail[0] = 0;
    REP(i, 0, 26) {
        if (s[1] == i) {
            tr[0][i] = 1;
        } else {
            tr[0][i] = 0;
        }
    }
    fail[1] = 0;
    REP(i, 1, n) {
        REP(j, 0, 26) {
            if (s[i + 1] == j) {
                tr[i][j] = i + 1;
                fail[i + 1] = tr[fail[i]][j];
            } else {
                tr[i][j] = tr[fail[i]][j];
            }
        }
    }
}

class Solution {
public:
    int dp[501][2][2][51];
    string str[2];

    int dfs(int len, int l, int s, int mat) {
        if (len == sz(str[0])) return 1;
        if (dp[len][l][s][mat] != -1) return dp[len][l][s][mat];
        ll ans = 0;
        // cout<<n<<endl;
        for (int i = 0; i < 26; i++) {
            if (i < str[0][len] and !l) continue;
            if (i > str[1][len] and !s) continue;
            int nxt = tr[mat][i];
            // cout<<i<<" "<<nxt<<endl;
            if (nxt == n) continue;
            ans += dfs(len + 1, l or i > str[0][len], s or i < str[1][len], nxt);
        }
        ans %= mod;
        return dp[len][l][s][mat] = ans;
    }

    int findGoodStrings(int n, string s1, string s2, string evil) {
        mst(dp, -1);
        for (auto &i : s1) i -= 'a';
        for (auto &i : s2) i -= 'a';
        for (auto &i : evil) i -= 'a';
        str[0] = s1;
        str[1] = s2;

        calcNext(evil);
        return dfs(0, 0, 0, 0);
    }
};

//
//namespace SOLVE {
//    void main() {
//
//    }
//}
//
//
//signed main() {
//#ifndef ONLINE_JUDGE
//    fr("/Users/zhangqingchuan/Desktop/cp/cp/input.txt");
//    fw("/Users/zhangqingchuan/Desktop/cp/cp/output.txt");
//#endif
//
//
//    int t = 1;
////    in(t);
//    for(int i = 1; i <= t; i++) {
////        cout<<"Case #"<<i<<":";
//        SOLVE::main();
//
//    }
//
//
//
//
//
//
//
//
////    clock_t st = clock();
////    while(clock() - st < 3.0 * CLOCKS_PER_SEC){
////
////    }
//
//
//
//
//
//
//    return 0;
//}