/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1106_sortbit.cpp
 * @Created Time:2020-11-06 15:39:05
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
int count_one(int a) {
    int cnt = 0;
    while (a) a = a & (a - 1), cnt++;
    return cnt;
}
bool cmp(int a, int b) {
    int numa = count_one(a), numb = count_one(b);
    return numa != numb ? numa < numb : a < b;
}
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};
class Solution {
public:
    int getn(int i) {
        int res = 0;
        while (i) {
            if (i & 1)
                res++;
            i = i >> 1;
        }
        return res;
    }
    vector<int> sortByBits(vector<int>& arr) {
        unordered_map<int, int> m;
        for (int& i : arr)
            if (m.count(i) == 0)
                m[i] = getn(i);
        sort(arr.begin(), arr.end(), [&](int a, int b) { return m[a] == m[b] ? a < b : m[a] < m[b]; });
        return arr;
    }
};