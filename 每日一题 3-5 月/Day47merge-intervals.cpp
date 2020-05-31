/*
 * @Author      :vimday
 * @Desc        :lc day47
 * @Url         :https://leetcode-cn.com/problems/merge-intervals/submissions/
 * @File Name   :Day47merge-intervals.cpp
 * @Created Time:2020-04-16 20:30:00
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
    static int cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int i = 0, j = 0;
        vector<vector<int>> res;
        while (i < intervals.size()) {
            int s = intervals[i][0];
            int t = intervals[i][1];
            j = i + 1;
            while (j < intervals.size() && intervals[j][0] <= t) {
                t = max(intervals[j][1], t);
                j++;
            }
            res.push_back(vector<int>{s, t});
            i = j;
        }
        return res;
    }
};