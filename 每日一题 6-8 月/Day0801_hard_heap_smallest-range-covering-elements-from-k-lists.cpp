/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0801_hard_heap_smallest-range-covering-elements-from-k-lists.cpp
 * @Created Time:2020-08-01 15:05:35
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
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
        int mx = INT_MIN, n = nums.size();
        for (int i = 0; i < n; i++) {
            pq.push({nums[i][0], i, 0});
            mx = max(mx, nums[i][0]);
        }
        vector<int> res{pq.top()[0], mx};
        while (1) {
            auto t = pq.top();
            pq.pop();
            if (++t[2] >= nums[t[1]].size()) break;
            pq.push({nums[t[1]][t[2]], t[1], t[2]});
            mx = max(mx, nums[t[1]][t[2]]);
            int d = mx - pq.top()[0];
            if (d < res[1] - res[0]) {
                res[0] = pq.top()[0];
                res[1] = mx;
            }
        }
        return res;
    }
};