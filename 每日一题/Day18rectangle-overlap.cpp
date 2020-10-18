/*
 * @Author      :vimday
 * @Desc        :lc day day up
 * @Url         :
 * @File Name   :Day18rectangle-overlap.cpp
 * @Created Time:2020-03-18 00:13:53
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
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return help(rec1, rec2) || help(rec2, rec1);
    }
    bool help(vector<int>& a, vector<int>& b) {
        return a[2] > b[0] && a[3] > b[1] && a[0] < b[2] && a[1] < b[3];
    }
};