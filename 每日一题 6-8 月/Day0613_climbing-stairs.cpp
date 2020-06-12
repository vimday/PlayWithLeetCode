/*
 * @Author      :vimday
 * @Desc        :LeetCode 每日一题 爬楼梯 
 * @Url         :
 * @File Name   :Day0613_climbing-stairs.cpp
 * @Created Time:2020-06-13 00:11:27
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
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        n -= 2;
        int pre = 1, cur = 2, res = 2;
        while (n--) {
            res = pre + cur;
            pre = cur;
            cur = res;
        }
        return res;
    }
};