/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day72pow(x,n).cpp
 * @Created Time:2020-05-11 00:05:37
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
    double myPow(double x, int n) {
        double res = 1.0;
        for (int i = n; i != 0; i /= 2) {
            if (i % 2)
                res *= x;
            x *= x;
        }
        return n < 0 ? 1 / res : res;
    }
};