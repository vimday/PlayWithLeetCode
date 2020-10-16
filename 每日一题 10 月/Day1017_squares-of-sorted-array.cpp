/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1017_squares-of-sorted-array.cpp
 * @Created Time:2020-10-16 09:59:25
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
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        vector<int> res(n);
        int idx = 0;
        for (int i = 0; i < n; i++)
            if (A[i] >= 0) {
                idx = i;
                break;
            }
        int l = idx - 1, r = idx;
        idx = 0;
        while (l >= 0 && r < n) {
            if (abs(A[l]) < abs(A[r]))
                res[idx++] = A[l] * A[l], --l;
            else
                res[idx++] = A[r] * A[r], ++r;
        }
        while (l >= 0)
            res[idx++] = A[l] * A[l], --l;
        while (r < n)
            res[idx++] = A[r] * A[r], ++r;
        return res;
    }
};