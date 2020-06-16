/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0617_best-sightseeing-pair.cpp
 * @Created Time:2020-06-17 00:15:13
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
    int maxScoreSightseeingPair(vector<int>& A) {
        if (A.empty()) return 0;
        int res = INT_MIN, ai = A[0], i = 0, n = A.size();
        for (int j = 1; j < n; j++) {
            res = max(res, ai + A[j] + i - j);
            if (A[j] + j > ai + i) {
                ai = A[j];
                i = j;
            }
        }
        return res;
    }
};