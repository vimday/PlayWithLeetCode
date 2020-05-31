/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0601_easy-kids-with-the-greatest-number-of-candies.cpp
 * @Created Time:2020-06-01 00:08:26
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
    vector<bool> kidsWithCandies(vector<int>& cs, int eds) {
        int n = cs.size();
        vector<bool> res(n);
        int mx = 0;
        for (int& i : cs) mx = max(i, mx);
        for (int i = 0; i < n; i++)
            if (cs[i] + eds >= mx)
                res[i] = true;
        return res;
    }
};