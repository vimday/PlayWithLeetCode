/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1129_largest-perimeter-triangle.cpp
 * @Created Time:2020-11-29 19:33:29
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
    int largestPerimeter(vector<int>& A) {
        sort(begin(A), end(A));
        for (auto i = A.size() - 1; i >= 2; i--) {
            if (A[i] < A[i - 1] + A[i - 2]) return A[i] + A[i - 1] + A[i - 2];
        }
        return 0;
    }
};