/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0730_dp_integer-break.cpp
 * @Created Time:2020-07-30 00:07:28
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
    int integerBreak(int n) {
        vector<int> dp(n + 1, -1);
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {  //分割成j和（i-j）
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }
        return dp[n];
    }
};
class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        vector<int> dp(n + 1, 0);
        dp[2] = 1;
        dp[3] = 2;
        for (int i = 4; i <= n; i++) {
            for (int j = 1; j < 4; j++) {
                dp[i] = max(dp[i], max(j * dp[i - j], (i - j) * j));
            }
        }
        return dp[n];
    }
};
//数学方法，求函数y=(n/x)^x(x>0)的最大值，可得x=e时y最大，但只能分解成整数，故x取2或3，由于6=2+2+2=3+3，显然2^3=8<9=3^2,故应分解为多个3
int integerBreak(int n) {
    if (n == 2)
        return 1;
    if (n == 3)
        return 2;
    int a = 1;
    while (n > 4) {
        n = n - 3;
        a = a * 3;
    }
    return a * n;
}