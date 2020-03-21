/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :B_cinema-seat-allocation.cpp
 * @Created Time:2020-03-21 23:19:32
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
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {
        int res = 2 * n;
        unordered_map<int, array<bool, 11>> me;
        for (vector<int>& v : rs)
            me[v[0]][v[1]] = true;
        for (auto& p : me) {
            auto& v = p.second;
            bool l = false, r = false, ml = false, mr = false;
            if (v[2] || v[3])
                l = true;
            if (v[8] || v[9])
                r = true;
            if (v[4] || v[5])
                ml = true;
            if (v[6] || v[7])
                mr = true;
            if ((l && r && (ml || mr)) || (ml && mr) || (l && mr) || (r && ml)) {
                res -= 2;
                continue;
            }
            if (!l && !r && !ml && !mr)
                continue;
            res--;
        }
        return res;
    }
};