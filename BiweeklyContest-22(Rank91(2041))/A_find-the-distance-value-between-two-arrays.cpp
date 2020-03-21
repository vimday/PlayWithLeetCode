/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :A_find-the-distance-value-between-two-arrays.cpp
 * @Created Time:2020-03-21 23:18:12
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
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int res = 0;
        for (int& i : arr1) {
            bool f = true;
            for (int& j : arr2) {
                if (abs(i - j) <= d) {
                    f = false;
                    break;
                }
            }
            if (f)
                res++;
        }
        return res;
    }
};