/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :DDD.cpp
 * @Created Time:2020-10-18 11:06:34
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

struct DSU {
    std::vector<int> data;
    void init(int n) {
        data.assign(n, -1);
    }
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
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
};
class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        int sz = queries.size();
        vector<bool> res(sz, true);
        if (threshold < 1) {
            return res;
        }
        // vector<unordered_set<int>> g;
        // g.resize(n + 1);
        DSU dsu;
        dsu.init(n + 1);
        for (int i = 1; i <= n; i++)
            for (int j = threshold + 1; j <= i; ++j)
                if (i % j == 0) {
                    // g[i].insert(j);
                    // g[j].insert(i);
                    dsu.unionSet(i, j);
                }
        for (int i = 0; i < sz; ++i) {
            int a = queries[i][0], b = queries[i][1];
            if (dsu.root(a) != dsu.root(b))
                res[i] = false;
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

const int N = 100011;
int rela[N];
int getr(int x) {
    int p = x;
    while (rela[p] != p) p = rela[p];
    int p1 = p;
    p = x;
    while (rela[p] != p) {
        int p2 = rela[p];
        rela[p] = p1;
        p = p2;
    }
    return p1;
}
class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& q) {
        for (int i = 1; i <= n; i++) rela[i] = i;
        for (int i = threshold + 1; i <= n; i++) {
            for (int j = i; j + i <= n; j += i) {
                int x = j, y = j + i;
                x = getr(x);
                y = getr(y);
                if (getr(x) != getr(y)) {
                    rela[x] = rela[y];
                }
            }
        }
        vector<bool> res;
        for (auto& t : q) {
            res.pb(getr(t[0]) == getr(t[1]));
        }
        return res;
    }
};