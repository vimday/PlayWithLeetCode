/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1108_best-time-stock-ii.cpp
 * @Created Time:2020-11-08 14:31:02
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
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int tmp = prices[0], sum = 0;
        for (auto& i : prices) {
            if (i > tmp) {
                sum += (i - tmp);
                tmp = i;
            } else
                tmp = i;
        }
        return sum;
    }
};