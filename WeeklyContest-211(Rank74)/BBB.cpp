/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :BBB.cpp
 * @Created Time:2020-10-18 10:34:48
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
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        set<string> ss;
        ss.insert(s);
        queue<string> q;
        q.push(s);
        while (!q.empty()) {
            string s = q.front();
            q.pop();
            string as = s;
            for (int i = 1; i < n; i += 2) {
                char na = (s[i] - '0' + a) % 10 + '0';
                as[i] = na;
            }
            if (ss.count(as) == 0) {
                ss.insert(as);
                q.push(as);
            }

            s = s.substr(n - b, b) + s.substr(n - b);
            if (ss.count(s) == 0) {
                ss.insert(s);
                q.push(s);
            }
        }
        return *ss.begin();
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
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        string ans = s;
        vector<string> q;
        q.pb(s);
        set<string> st;
        st.insert(s);
        for (int op = 0; op < (int)q.size(); op++) {
            string s = q[op];
            for (int i = 1; i < n; i += 2) {
                s[i] = (s[i] - '0' + a) % 10 + '0';
            }
            if (st.count(s) == 0) {
                q.pb(s);
                st.insert(s);
            }
            s = q[op];
            string t(s);
            for (int i = 0; i < n; i++) {
                t[i] = s[(i - b + n) % n];
            }
            if (st.count(t) == 0) {
                q.pb(t);
                st.insert(t);
            }
        }
        return *st.begin();
        /*or(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                for(int k = 0; k < n; k++) {
                    string t;
                    for(int l = 0; l < n; l++) {
                        int pos = (k + l) % n;
                        char c = s[pos];
                        if(pos % 2 == 1) c = (c - '0' + i * a) % 10 + '0';
                        else c = (c - '0' + j * a) % 10 + '0';
                        t.pb(c);
                    }
                    cout << t << endl;
                    ans = min(ans, t);
                }
            }
        }*/
        return ans;
    }
};