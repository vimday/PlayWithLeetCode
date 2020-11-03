/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1103_valid-mountain-array.cpp
 * @Created Time:2020-11-03 14:51:33
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
    bool validMountainArray(vector<int>& A) {
        int n = A.size();
        if (n < 3) return false;
        if (A[1] <= A[0])
            return false;
        bool f = false;
        for (int i = 2; i < n; ++i) {
            if (A[i] == A[i - 1])
                return false;
            if (A[i] > A[i - 1] && f)
                return false;
            if (A[i] < A[i - 1])
                f = true;
        }
        return f;
    }
};