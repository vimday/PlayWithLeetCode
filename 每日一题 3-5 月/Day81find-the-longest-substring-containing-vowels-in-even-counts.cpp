/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day81find-the-longest-substring-containing-vowels-in-even-counts.cpp
 * @Created Time:2020-05-20 00:34:31
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
    int findTheLongestSubstring(string s) {
        //状态压缩标记
        int m[1 << 5];
        memset(m, 0xff, sizeof m);
        m[0] = 0;  //表示 a e i o u 均出现偶数次（0）的 idx 为 0
        int res = 0, idx = 0, status = 0;
        for (char &c : s) {
            ++idx;  //idx 从 1 开始
            if (c == 'a')
                status ^= 1;
            else if (c == 'e')
                status ^= 2;
            else if (c == 'i')
                status ^= 4;
            else if (c == 'o')
                status ^= 8;
            else if (c == 'u')
                status ^= 16;
            if (m[status] != -1)
                res = max(res, idx - m[status]);
            else
                m[status] = idx;
        }
        return res;
    }
};