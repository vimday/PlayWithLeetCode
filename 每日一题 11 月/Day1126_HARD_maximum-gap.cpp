/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1126_HARD_maximum-gap.cpp
 * @Created Time:2020-11-26 15:10:34
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
    int maximumGap(vector<int> &nums) {
        int n = nums.size();
        if (n < 2) return 0;
        int mx = nums[0], mn = nums[0];
        for (int &i : nums) {
            if (i > mx)
                mx = i;
            else if (i < mn)
                mn = i;
        }
        int d = (mx - mn) / n < 1 ? 1 : (mx - mn) / n;
        int sz = (mx - mn) / d + 1;
        int mxv[sz], mnv[sz], b = sz;
        bool m[sz];
        memset(mxv, 0, sizeof mxv);
        memset(m, 0, sizeof m);
        memset(mnv, 0xff, sizeof mnv);
        for (int &i : nums) {
            int p = (i - mn) / d;
            m[p] = true;
            if (p < b) b = p;
            if (i > mxv[p]) mxv[p] = i;
            if (i < mnv[p] || mnv[p] == -1) mnv[p] = i;
        }
        int last = b, res = 0;
        for (int i = b + 1; i < sz; ++i) {
            if (m[i]) {
                if (mnv[i] - mxv[last] > res)
                    res = mnv[i] - mxv[last];
                last = i;
            }
        }
        return res;
    }
};