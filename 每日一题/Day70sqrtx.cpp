/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day70sqrtx.cpp
 * @Created Time:2020-05-09 00:14:20
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
    int mySqrt(int x) {
        if (x == 0) return 0;
        if (x < 4) return 1;
        int t = x - 1;  //最大为 x-1,之后不断逼近
        while (t > x / t)
            t = (t + x / t) / 2;
        return t;
    }
};