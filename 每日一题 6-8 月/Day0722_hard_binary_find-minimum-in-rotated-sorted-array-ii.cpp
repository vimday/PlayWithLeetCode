/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0722_hard_binary_find-minimum-in-rotated-sorted-array-ii.cpp
 * @Created Time:2020-07-22 00:36:21
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
    int minArray(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mi = l + (r - l >> 1);
            //中间的大于右侧的，最小值肯定出在右侧
            if (nums[mi] > nums[r])
                l = mi + 1;
            else if (nums[mi] < nums[r])
                r = mi;
            else
                r--;
        }
        return nums[l];
    }
};
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int res;
        if (nums.size() == 1) {
            return nums[0];
        }
        while (left <= right) {
            while (left < right && nums[left] == nums[left + 1]) left++;
            while (left < right && nums[right] == nums[right - 1]) right--;
            int mid = (left + right) / 2;
            if (nums[left] <= nums[mid] && nums[right] >= nums[mid]) {
                res = nums[left];
                break;
            }
            if (nums[left] < nums[mid]) {
                left = mid + 1;
            } else if (nums[right] > nums[mid]) {
                right = mid;
            } else {
                // 要么左边与mid相等，要么右边与mid相等
                if (nums[left] == nums[mid])
                    left++;
                else
                    right--;
            }
        }
        return res;
    }
};
