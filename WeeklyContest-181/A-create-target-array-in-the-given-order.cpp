/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :https://leetcode-cn.com/problems/create-target-array-in-the-given-order/submissions/
 * @File Name   :A.cpp
 * @Created Time:2020-03-25 16:29:49
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
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n = nums.size();
        vector<int> res(n);
        int cur = -1;
        for (int i = 0; i < n; i++) {
            int idx = index[i];
            if (idx > cur) {
                res[idx] = nums[i];
                cur = idx;
            } else {
                for (int j = ++cur; j > idx; j--)
                    res[j] = res[j - 1];

                res[idx] = nums[i];
            }
        }
        return res;
    }
};
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> res;
        for (int i = 0; i < index.size(); ++i) {
            res.insert(res.begin() + index[i], nums[i]);
        }
        return res;
    }
};