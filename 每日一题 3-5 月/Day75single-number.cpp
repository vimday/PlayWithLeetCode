/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day75single-number.cpp
 * @Created Time:2020-05-14 00:08:24
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
    int singleNumber(vector<int>& nums) {
        //异或性质 a^a=0 a^b^a=a^a^b=0^b=b
        int res = 0;
        for (int& i : nums)
            res ^= i;
        return res;
    }
};