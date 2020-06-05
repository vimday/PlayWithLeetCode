/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0605_shunshizhendayinjuzhen.cpp
 * @Created Time:2020-06-05 11:57:11
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
    vector<int> spiralOrder(vector<vector<int>>& ma) {
        //模拟
        if (ma.empty()) return {};
        int li = 0, ri = ma[0].size() - 1, ui = 0, di = ma.size() - 1;
        //为什么取左闭右闭的区间呢 因为不只有上到下 左到右的遍历，还有相反的遍历
        //这样写出来的代码有对称美
        int cur = 0, idx = 0;
        vector<int> res((ri + 1) * (di + 1));
        while (true) {
            idx = li;
            while (idx <= ri) res[cur++] = ma[ui][idx++];
            if (++ui > di) break;

            idx = ui;
            while (idx <= di) res[cur++] = ma[idx++][ri];
            if (--ri < li) break;

            idx = ri;
            while (idx >= li) res[cur++] = ma[di][idx--];
            if (--di < ui) break;

            idx = di;
            while (idx >= ui) res[cur++] = ma[idx--][li];
            if (++li > ri) break;
        }
        return res;
    }
};