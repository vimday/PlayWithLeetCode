/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0610_palindrom-num.cpp
 * @Created Time:2020-06-10 00:15:07
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
    bool isPalindrome(int x) {
        if (x == 0) return true;
        if (x < 0 || x % 10 == 0) return false;
        int remain = 0;
        while (x > remain) {
            remain = 10 * remain + x % 10;
            x /= 10;
        }
        //1221      //121
        return x == remain || x == remain / 10;
    }
};