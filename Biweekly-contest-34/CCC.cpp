/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :CCC.cpp
 * @Created Time:2020-09-05 22:56:26
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
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        if (n < 2)
            return 0;
        int ed = -1, st = -1;
        for (int i = n - 1; i > 0; i--) {
            if (arr[i] < arr[i - 1]) {
                ed = i;
                break;
            }
        }
        if (ed == -1)
            return 0;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                st = i;
                break;
            }
        }
        int nst = st, ned = ed;
        for (; nst >= 0; nst--) {
            if (arr[nst] <= arr[ed])
                break;
        }
        if (nst == -1)
            return ed;
        for (; ned < n; ned++)
            if (arr[ned] >= arr[st])
                break;
        if (ned == n)
            return n - st - 1;
        return min(ed - nst - 1, ned - st - 1);
    }
};
