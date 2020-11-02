/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1102_intersection-of-two-arrays.cpp
 * @Created Time:2020-11-02 14:53:08
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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m, res;
        for (int& i : nums1)
            m.insert(i);
        for (int& i : nums2)
            if (m.count(i))
                res.insert(i);
        return vector<int>(res.begin(), res.end());
    }
};