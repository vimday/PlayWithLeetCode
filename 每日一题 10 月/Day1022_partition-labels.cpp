/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1022_partition-labels.cpp
 * @Created Time:2020-10-22 11:50:22
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
    vector<int> partitionLabels(string S) {
        int charidx[26]{0};
        vector<int> res;
        int n = S.size();
        for (int i = 0; i < n; ++i)
            charidx[S[i] - 'a'] = i;
        int left = 0, init = 0, right = 0;
        while (left < n) {
            init = left;
            right = charidx[S[left] - 'a'];
            while (left < right) {
                ++left;
                if (charidx[S[left] - 'a'] > right)
                    right = charidx[S[left] - 'a'];
            }
            res.emplace_back(++left - init);
        }
        return res;
    }
};
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size(), cur = 0, r = 0, l = 0;
        int m[26]{0};
        for (int i = 0; i < n; ++i)
            m[s[i] - 'a'] = i;
        vector<int> res;
        while (cur < n) {
            l = cur;
            r = m[s[cur] - 'a'];
            while (++cur <= r)
                r = max(r, m[s[cur] - 'a']);
            res.push_back(cur - l);
        }
        return res;
    }
};