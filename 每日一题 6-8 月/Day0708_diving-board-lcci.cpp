/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0708_diving-board-lcci.cpp
 * @Created Time:2020-07-08 00:42:52
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
    vector<int> divingBoard(int st, int lg, int k) {
        vector<int> res;
        if (k == 0) return res;
        res.push_back(st * k);
        if (st != lg) {
            int ad = lg - st;
            while (k--)
                res.push_back(res.back() + ad);
        }
        return res;
    }
};