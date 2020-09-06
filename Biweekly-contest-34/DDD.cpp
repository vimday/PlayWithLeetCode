/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :DDD.cpp
 * @Created Time:2020-09-05 23:15:49
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
typedef long long ll;
const ll mod = 1e9 + 7;

class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<int> lidx = locations;
        unordered_map<int, int> midx;
        for (int i = 0; i < n; i++)
            midx[locations[i]] = i;
        sort(locations.begin(), locations.end());
    }
};