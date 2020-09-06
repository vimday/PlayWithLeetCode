/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :BBB.cpp
 * @Created Time:2020-09-05 22:34:10
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
class Solution {
public:
    int numWays(string s) {
        int cnt = 0, n = s.size();
        for (char& c : s)
            if (c == '1')
                cnt++;
        if (cnt % 3)
            return 0;
        int t = cnt / 3;
        if (cnt == 0) {
            return helpcn2(n - 1) % mod;
        }
        int cn = cnt, idx1 = 0, idx2 = 0, idx3 = 0, idx4 = n;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                --cn;
                if (cn == 2 * t) {
                    idx1 = i;
                } else if (cn == 2 * t - 1) {
                    idx2 = i;
                } else if (cn == t) {
                    idx3 = i;
                } else if (cn == t - 1) {
                    idx4 = i;
                }
            }
        }

        int c1 = idx2 - idx1, c2 = idx4 - idx3;
        return c1 * c2 % mod;
    }
    ll helpcn2(int n) {
        return n * (n - 1) / 2;
    }
};