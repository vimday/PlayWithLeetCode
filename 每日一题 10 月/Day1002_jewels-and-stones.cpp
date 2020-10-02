/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1002_jewels-and-stones.cpp
 * @Created Time:2020-10-02 19:32:25
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
    int numJewelsInStones(string J, string S) {
        bool m[128];
        memset(m, 0, sizeof m);
        for (char &c : J)
            m[c] = true;
        int res = 0;
        for (char &c : S)
            if (m[c])
                res++;
        return res;
    }
};