/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :AAA.cpp
 * @Created Time:2020-09-19 22:30:02
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
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int res = 0;
        for (int k = 1; k <= n; k += 2) {
            for (int i = 0; i < n - k + 1; i++)
                for (int j = i; j < i + k; j++)
                    res += arr[j];
        }
        return res;
    }
};
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        vector<int> pre(arr.size() + 1);
        for (int i = 1; i <= arr.size(); ++i) pre[i] = pre[i - 1] + arr[i - 1];
        int ans = 0;
        for (int len = 1; len <= arr.size(); len += 2)
            for (int i = 0; i + len < pre.size(); ++i)
                ans += pre[i + len] - pre[i];
        return ans;
    }
};
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int res = 0;
        for (int i = 0; i < arr.size(); i++) {
            int left = i + 1, right = arr.size() - i,
                left_even = (left + 1) / 2, right_even = (right + 1) / 2,
                left_odd = left / 2, right_odd = right / 2;
            res += (left_even * right_even + left_odd * right_odd) * arr[i];
        }
        return res;
    }
};

//https://leetcode-cn.com/problems/sum-of-all-odd-length-subarrays/solution/cong-on3-dao-on-de-jie-fa-by-liuyubobobo/