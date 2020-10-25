/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1025_longest-mountain-in-array.cpp
 * @Created Time:2020-10-25 12:06:21
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
    int longestMountain(vector<int>& A) {
        int l = 1, r = 0, res = 0, n = A.size();
        for (int i = 1; i < n;) {
            while (i < n && A[i] > A[i - 1]) {
                l++;
                r = 0;
                i++;
            }

            while (i < n && A[i] < A[i - 1]) {
                r++;
                i++;
            }
            if (l > 1 && r && res < l + r)
                res = l + r;
            l = 1;
            r = 0;
            if (i < n && A[i] == A[i - 1])
                i++;
        }
        return res;
    }
};