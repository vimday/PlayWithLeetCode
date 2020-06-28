/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0629_kth-largest-element-in-an-array.cpp
 * @Created Time:2020-06-29 00:11:43
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
    int findKthLargest(vector<int>& nums, int k) {
        int idx = helper(nums, 0, nums.size() - 1, k);
        return nums[idx];
    }

    int helper(vector<int>& nums, int low, int high, int& k) {
        if (low >= high) return low;
        int mid = partition(nums, low, high);
        if (mid < nums.size() - k)
            return helper(nums, mid + 1, high, k);
        else if (mid > nums.size() - k)
            return helper(nums, low, mid - 1, k);
        else
            return mid;
    }

    int partition(vector<int>& nums, int low, int high) {
        int r = rand() % (high - low + 1) + low;
        swap(nums[r], nums[low]);

        int tmp = nums[low];
        while (low < high) {
            while (low < high && nums[high] >= tmp) --high;
            if (low < high) {
                nums[low] = nums[high];
                ++low;
            }
            while (low < high && nums[low] <= tmp) ++low;
            if (low < high) {
                nums[high] = nums[low];
                --high;
            }
        }
        nums[low] = tmp;  // low==high
        return low;
    }
};