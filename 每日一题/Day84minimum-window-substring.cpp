/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day84minimum-window-substring.cpp
 * @Created Time:2020-05-23 01:02:32
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
    string minWindow(string s, string t) {
        int m[128];
        memset(m, 0, sizeof m);
        for (char& c : t)
            m[c]++;  //先记录 t 中的字符 map
        int n = s.size(), l = 0, r = 0, cnt = t.size(), start = -1, cm = INT_MAX;
        //bf n^2 双指针 n
        while (r < n) {
            if (--m[s[r++]] >= 0)
                --cnt;
            if (cnt == 0) {
                //此时 [l,r) 肯定满足要求并且 r 为右端点（不包含）
                //但 l 还有可能右移
                while (++m[s[l++]] <= 0)
                    ;
                //此时 m[s[l-1]]==1 ++前定为左端点
                if (r - l + 1 < cm) {
                    cm = r - l + 1;
                    start = l - 1;
                }
                cnt++;
            }
        }
        return start == -1 ? "" : s.substr(start, cm);
    }
};