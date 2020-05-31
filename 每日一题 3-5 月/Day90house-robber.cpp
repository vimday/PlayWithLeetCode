/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day90house-robber.cpp
 * @Created Time:2020-05-29 21:37:09
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
    int rob(vector<int>& nums) {
        //dp 降维 直接用三个变量记录状态即可
        int ppre = 0, pre = 0, cur = 0;
        for (int& i : nums) {
            cur = max(i + ppre, pre);
            ppre = pre;
            pre = cur;
        }
        return cur;
    }
};