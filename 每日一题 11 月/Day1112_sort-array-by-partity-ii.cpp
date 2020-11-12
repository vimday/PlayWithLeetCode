/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1112_sort-array-by-partity-ii.cpp
 * @Created Time:2020-11-12 16:16:03
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
    vector<int> sortArrayByParityII(vector<int>& A) {
        int ne = 0, no = 1, idx = 0, n = A.size();
        while (idx < n) {
            while (idx < n && ((idx & 1) == (A[idx] & 1)))
                ++idx;
            int nx = max(idx + 1, (idx & 1) ? ne : no);
            if (nx >= n)
                break;

            while ((idx & 1) != (A[nx] & 1))
                nx += 2;
            swap(A[idx], A[nx]);
            idx += 2;
            if (nx & 1) {
                no = nx;
                ne = max(ne, idx);
            } else {
                ne = nx;
                no = max(no, idx);
            }
        }
        return A;
    }
};
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int j = 1, n = A.size();
        for (int i = 0; i < n - 1; i = i + 2) {
            if ((A[i] & 1) != 0) {
                while ((A[j] & 1) != 0) {
                    j = j + 2;
                }
                int tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
        }
        return A;
    }
};
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        for (int i = 1, j = 0, n = A.size(), a1; i < n;) {
            if (A[i] & 1) {
                i += 2;
                continue;
            }
            a1 = A[i];
            A[i] = A[j];
            A[j] = a1;
            j += 2;
        }
        return A;
    }
};