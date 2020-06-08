/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0609mianshiti46.cpp
 * @Created Time:2020-06-09 00:22:32
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
    int translateNum(int num) {
        //dp dp[i]=dp[i-1]+dp[i-2]
        if (num < 10)
            return 1;
        string s = to_string(num);
        int n = s.size();
        int dp[n];
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        if (s[0] == '1' || (s[0] == '2' && s[1] < '6'))
            dp[1] = 2;
        else
            dp[1] = 1;
        for (int i = 2; i < n; i++)
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '6'))
                dp[i] = dp[i - 1] + dp[i - 2];
            else
                dp[i] = dp[i - 1];
        return dp[n - 1];
    }
};