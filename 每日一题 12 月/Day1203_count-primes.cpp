/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1203_count-primes.cpp
 * @Created Time:2020-12-03 12:34:08
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
    int countPrimes(int n) {
        //const int sz=n;
        if (n == 0) return 0;
        bool np[n];
        memset(np, 0, sizeof np);
        int res = 0;
        for (int i = 2; i < n; ++i) {
            if (np[i])
                continue;
            res++;
            for (long j = (long)i * i; j < n; j += i) {
                np[j] = true;
            }
        }
        return res;
    }
};