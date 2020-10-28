/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1028_unique-number-of-occurrences.cpp
 * @Created Time:2020-10-28 10:46:17
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
    bool uniqueOccurrences(vector<int> &arr) {
        int m[2007], cnt[1001];
        memset(m, 0, sizeof m);
        memset(cnt, 0, sizeof cnt);
        for (int &i : arr)
            m[i + 1000]++;
        for (int &i : m)
            if (i > 0)
                ++cnt[i];
        for (int &i : cnt)
            if (i > 1)
                return false;
        return true;
    }
};