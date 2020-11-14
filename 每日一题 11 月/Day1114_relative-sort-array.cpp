/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1114_relative-sort-array.cpp
 * @Created Time:2020-11-14 14:08:13
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
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res(1001);
        for (int i = 0; i < arr1.size(); i++) {
            res[arr1[i]]++;
        }
        int k = 0;
        for (int i = 0; i < arr2.size(); i++) {
            while (res[arr2[i]] > 0) {
                arr1[k] = arr2[i];
                k++;
                res[arr2[i]]--;
            }
        }
        for (int i = 0; i < res.size(); i++) {
            while (res[i] > 0) {
                arr1[k] = i;
                k++;
                res[i]--;
            }
        }
        return arr1;
    }
};
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int m[1001];
        memset(m, 0, 1001 << 2);
        for (int& i : arr1)
            ++m[i];
        int idx = 0;
        for (int& i : arr2) {
            while (m[i] > 0) {
                arr1[idx++] = i;
                --m[i];
            }
        }
        for (int i = 0; i < 1001; ++i)
            while (m[i] > 0) {
                arr1[idx++] = i;
                --m[i];
            }
        return arr1;
    }
};