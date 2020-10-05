/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1005_binary_xiaozhangdeshuatijihua.cpp
 * @Created Time:2020-10-05 13:43:55
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
    bool can(vector<int> &v, int m, int t) {
        int ps = 0, mx = 0;
        for (int &i : v) {
            mx = max(i, mx);
            ps += i;
            if (ps - mx > t) {
                if (--m < 0)
                    return false;
                ps = i;
                mx = i;
            }
        }
        if (ps && --m < 0)
            return false;
        return true;
    }
    int minTime(vector<int> &time, int m) {
        int n = time.size();
        if (m >= n)
            return 0;
        int h = 0, l = 0;
        for (int &i : time)
            h += i;
        while (l < h) {
            int mi = l + (h - l >> 1);
            can(time, m, mi) ? h = mi : l = mi + 1;
        }
        return l;
    }
};