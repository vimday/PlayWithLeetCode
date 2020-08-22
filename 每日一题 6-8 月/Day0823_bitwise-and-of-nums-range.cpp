/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0823_bitwise-and-of-nums-range.cpp
 * @Created Time:2020-08-23 01:09:58
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
    int rangeBitwiseAnd(int m, int n) {
        while (n > m)
            n &= (n - 1);
        return n;
        // int i=0;
        // while(m!=n){
        //     m>>=1;
        //     n>>=1;
        //     i++;
        // }
        // return n<<i;
    }
};