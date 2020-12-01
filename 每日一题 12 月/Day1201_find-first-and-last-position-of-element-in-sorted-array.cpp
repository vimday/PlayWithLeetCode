/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1201_find-first-and-last-position-of-element-in-sorted-array.cpp
 * @Created Time:2020-12-01 12:24:57
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
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res;

        int min = -1, max = -1, mid;
        int i = 0, j = n - 1;
        while (i <= j) {
            mid = (i + j) / 2;
            if (nums[mid] < target) {
                i = mid + 1;
            } else if (nums[mid] > target) {
                j = mid - 1;
            } else {
                int k = 1;
                min = max = mid;
                while (mid - k >= i && nums[mid - k] == target) {
                    min = mid - k;
                    ++k;
                }
                k = 1;
                while (mid + k <= j && nums[mid + k] == target) {
                    max = mid + k;
                    ++k;
                }
                break;
            }
        }
        res.push_back(min);
        res.push_back(max);
        return res;
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if (nums.empty()) return res;
        int n = nums.size(), l = 0, r = n - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] >= target)
                r = m;
            else
                l = m + 1;
        }
        if (nums[l] != target) return res;
        res[0] = l;
        r = n;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] <= target)
                l = m + 1;
            else
                r = m;
        }
        res[1] = l - 1;
        return res;
    }
};