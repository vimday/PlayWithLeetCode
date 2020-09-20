/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :CCC.cpp
 * @Created Time:2020-09-19 22:53:33
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
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int ans = n;
        long long sum = 0;
        unordered_map<int, int> cnt;

        for (int i = 0; i < n; ++i) sum += nums[i];
        int rest = sum % p;
        if (rest == 0) return 0;

        cnt[0] = 0;
        sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += nums[i - 1];
            int x = (sum - rest + p) % p;
            if (cnt.count(x)) {
                ans = min(ans, i - cnt[x]);
            }
            cnt[sum % p] = i;
        }
        if (ans == n) return -1;
        return ans;
    }
};

class Solution {
public:
    int n;
    int minSubarray(vector<int>& nums, int p) {
        n = nums.size();
        vector<ll> ps(n + 1);
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < n; i++) {
            ps[i + 1] = ps[i] + nums[i];
        }

        if (ps[n] % p == 0)
            return 0;
        if (p > ps[n])
            return -1;
        ll tt = ps[n] % p;
        for (int i = 1; i <= n; i++) {
            ps[i] %= p;
            m[ps[i]].push_back(i);
        }
        int res = n;
        for (int i = 0; i <= n; i++) {
            ll cs;
            if (ps[i] >= tt)
                cs = ps[i] - tt;
            else {
                cs = p + ps[i] - tt;
            }
            if (m.count(cs)) {
                vector<int>& v = m[cs];
                for (int j : v) {
                    if (j < i)
                        res = min(res, i - j);
                    else {
                        break;
                    }
                }
                // auto it = lower_bound(v.begin(), v.end(), i);
                // auto idx = it - v.begin();
                // if (idx != 0)
                //     res = min(res, i - v[idx]);
            }
        }
        return res;

        // for (int i = 1; i < n; i++) {
        //     for (int j = i; j <= n; j++) {
        //         if (ps[n] - (ps[j] - ps[j - i]) % p == 0)
        //             return i;
        //     }
        // }
        // return -1;
        // int l = 0, h = n;
        // while (l < h) {
        //     int mi = l + (h - l >> 1);
        //     if (help(ps, p, mi))
        //         h = mi;
        //     else {
        //         l = mi + 1;
        //     }
        // }
    }
};