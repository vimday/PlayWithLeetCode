/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :C_sort-integers-by-the-power-value.cpp
 * @Created Time:2020-03-21 23:20:25
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
    int me[1005];
    void help(int i) {
        long t = i, cnt = 0;
        while (t != 1) {
            if (t & 1)
                t = 3 * t + 1;
            else
                t >>= 1;
            cnt++;
        }
        me[i] = cnt;
    }
    int getKth(int lo, int hi, int k) {
        memset(me, 0, sizeof me);
        vector<int> v;
        for (int i = lo; i <= hi; i++) {
            v.push_back(i);
            help(i);
        }
        sort(v.begin(), v.end(), [&](int a, int b) { return me[a] == me[b] ? a < b : me[a] < me[b]; });
        return v[k - 1];
    }
};