/*
 * @Author      :vimday
 * @Desc        :lc day59
 * @Url         :https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/submissions/
 * @File Name   :Day59shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof.cpp
 * @Created Time:2020-04-28 00:09:36
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
    vector<int> singleNumbers(vector<int> &nums) {
        vector<int> res(2, 0);
        int t = 0;
        for (int &i : nums)
            t ^= i;
        t &= (-t);
        for (int &i : nums)
            if (i & t)
                res[0] ^= i;
            else
                res[1] ^= i;
        return res;
    }
};