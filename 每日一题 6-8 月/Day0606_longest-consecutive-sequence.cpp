/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0606_longest-consecutive-sequence.cpp
 * @Created Time:2020-06-06 00:47:12
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
    int longestConsecutive(vector<int>& nums) {
        //hiahia  刚开始是会员题  lc 太良心了！
        //这个就遍历用 map 记录 m[i]表示 i 所在的序列中的最长连续长度
        int res = 0;
        unordered_map<int, int> m;
        for (int& i : nums) {
            if (m.count(i) == 0) {
                int l = m.count(i - 1) ? m[i - 1] : 0;  //i没有出现过 则 i-1 肯定为右端点
                int r = m.count(i + 1) ? m[i + 1] : 0;  //同理
                int t = l + r + 1;
                if (t > res)
                    res = t;
                m[i] = t;
                m[i - l] = t;
                m[i + r] = t;
            }
        }
        return res;
    }
};