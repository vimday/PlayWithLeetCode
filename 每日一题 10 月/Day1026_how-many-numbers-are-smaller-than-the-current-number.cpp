/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1026_how-many-numbers-are-smaller-than-the-current-number.cpp
 * @Created Time:2020-10-26 10:38:41
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
    vector<int> smallerNumbersThanCurrent(vector<int>& a) {
        int m[101];
        memset(m, 0, sizeof m);
        for (const int& i : a)
            ++m[i];
        int pre = 0;
        for (int i = 0; i < 101; ++i) {
            int t = m[i];
            m[i] = pre;
            pre += t;
        }
        vector<int> res;
        for (const int& i : a)
            res.push_back(m[i]);
        return res;
    }
};