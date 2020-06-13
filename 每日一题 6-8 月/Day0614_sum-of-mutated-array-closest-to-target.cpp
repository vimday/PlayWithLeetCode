/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0614_sum-of-mutated-array-closest-to-target.cpp
 * @Created Time:2020-06-14 00:12:12
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
    int sumFunc(vector<int>& arr, int threshold) {
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= threshold) {
                sum += arr[i];
            } else {
                sum += threshold;
            }
        }
        return sum;
    }
    int findBestValue(vector<int>& arr, int target) {
        int left = 1;
        int right = *max_element(arr.begin(), arr.end());  // 二分法上下限分别是0和max(arr)
        while (left < right) {
            int mid = left + (right - left) / 2;
            std::cout << "mid = " << mid << std::endl;
            int sum = sumFunc(arr, mid);
            if (sum < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
            std::cout << "left = " << left << std::endl;
            std::cout << "right = " << right << std::endl;
        }
        std::cout << "left = " << left << std::endl;
        int sum1 = sumFunc(arr, left - 1);
        int sum2 = sumFunc(arr, left);
        if (sum2 - target >= target - sum1) {
            return left - 1;
        } else {
            return left;
        }
    }
};
class Solution {
public:
    int findBestValue(vector<int>& arr, int t) {
        sort(arr.begin(), arr.end());
        int n = arr.size(), sum = 0;
        for (int& i : arr)
            sum += i;
        if (sum == t)
            return arr[n - 1];
        if (t / n <= arr[0]) {
            if (t - t / n * n > (t / n + 1) * n - t)
                return t / n + 1;
            return t / n;
        }
        if (t / n > arr[n - 1])
            return arr[n - 1];
        int cm = INT_MAX, res = arr[0], ps = 0, ci = 0;
        for (int i = arr[0]; i <= arr[n - 1]; i++) {
            int idx = lower_bound(arr.begin(), arr.end(), i) - arr.begin();
            for (int j = ci; j < idx; j++)
                ps += arr[j];
            int ccm = abs(ps + (n - idx) * i - t);
            if (ccm < cm) {
                cm = ccm;
                res = i;
            }
            ci = idx;
        }
        return res;
    }
};