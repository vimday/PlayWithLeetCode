/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1104_insert-interval.cpp
 * @Created Time:2020-11-04 10:47:08
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
    static bool comp(const vector<int> &a, const vector<int> &b) {
        return a[1] < b[0];
    }

public:
    vector<vector<int>> insert(vector<vector<int>> &A, vector<int> &a) {
        int i = lower_bound(A.begin(), A.end(), a, comp) - A.begin(), j = 0;
        for (j = i; j < A.size() && a[1] >= A[j][0]; ++j)
            a = {min(a[0], A[j][0]), max(a[1], A[j][1])};
        A.insert(A.begin() + j, a);
        A.erase(A.begin() + i, A.begin() + j);
        return A;
    }
};
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        int n = intervals.size();
        int l = newInterval[0], r = newInterval[1], idx = 0;
        if (n == 0) return {{l, r}};
        bool f = false, m[n] = {};
        if (intervals[0][0] > r) {
            intervals.insert(intervals.begin(), {l, r});
            return intervals;
        }
        if (intervals[0][0] <= r && intervals[0][1] >= l) {
            intervals[0][0] = min(intervals[0][0], l);
            r = intervals[0][1] = max(intervals[0][1], r);
            f = true;
        }
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] <= r && intervals[i][1] >= l) {
                if (f) {
                    m[i] = true;
                    r = intervals[idx][1] = max(r, intervals[i][1]);
                } else {
                    idx = i;
                    f = true;
                    intervals[i][0] = min(intervals[i][0], l);
                    r = intervals[i][1] = max(intervals[i][1], r);
                }
            } else if (intervals[i][0] > r) {
                if (!f) {
                    intervals.insert(intervals.begin() + i, newInterval);
                    return intervals;
                }
                break;
            }
        }

        if (!f) {
            intervals.emplace_back(newInterval);
            return intervals;
        }
        vector<vector<int>> res;
        for (int i = 0; i < n; ++i) {
            if (!m[i])
                res.emplace_back(intervals[i]);
        }

        return res;
    }
};