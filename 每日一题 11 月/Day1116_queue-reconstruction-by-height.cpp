/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1116_queue-reconstruction-by-height.cpp
 * @Created Time:2020-11-16 13:23:22
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
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        vector<vector<int>> res(n);
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) { return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]; });
        for (int i = 0; i < n; i++) {
            vector<int>& v = people[i];
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if ((res[j].size() == 0) && cnt++ == v[1]) {
                    res[j] = v;
                    break;
                }
            }
        }
        return res;
    }
};