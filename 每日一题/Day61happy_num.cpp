/*
 * @Author      :vimday
 * @Desc        :lc day61 last
 * @Url         :https://leetcode-cn.com/problems/happy-number/comments/
 * @File Name   :Day61happy_num.cpp
 * @Created Time:2020-04-30 00:12:07
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
    int gets(int n) {
        int res = 0;
        while (n) {
            res += (n % 10) * (n % 10);
            n /= 10;
        }
        return res;
    }
    bool isHappy(int n) {
        int f = n, s = n;
        while (f != 1 && s != 1) {
            s = gets(s);
            f = gets(gets(f));
            if (s != 1 && s == f)
                return false;
        }
        return true;
    }
};