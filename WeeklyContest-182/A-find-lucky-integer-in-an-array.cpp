/*
 * @Author      :vimday
 * @Desc        :wc 182 a
 * @Url         :https://leetcode-cn.com/problems/find-lucky-integer-in-an-array/comments/
 * @File Name   :A.cpp
 * @Created Time:2020-03-29 15:37:09
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
    int findLucky(vector<int>& arr) {
        int m[505];
        memset(m, 0, sizeof m);
        for (int& i : arr)
            m[i]++;
        for (int i = 500; i > 0; i--)
            if (m[i] == i)
                return i;
        return -1;
    }
};