/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1202_TODO_HARD_create-maximum-number.cpp
 * @Created Time:2020-12-02 10:15:50
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
    int ans[1005] = {0};
    int A[1005], lenA;
    int B[1005], lenB;
    int C[1005], lenC;

public:
    void fun(int v[], vector<int>& nums, int k) {
        int i, lenv = 0, pop_rest = nums.size() - k;
        for (i = 0; i < nums.size() && pop_rest; i++) {
            while (lenv && v[lenv - 1] < nums[i] && pop_rest-- > 0) lenv--;
            if (lenv < k)
                v[lenv++] = nums[i];
            else
                pop_rest--;
        }
        while (i < nums.size()) v[lenv++] = nums[i++];
        if (lenv > k) lenv = k;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int K) {
        int i, j, k, l;
        for (i = 0; i <= K; i++) {
            lenA = i;
            lenB = K - i;
            if (lenB > nums2.size()) continue;
            if (lenA > nums1.size()) break;
            fun(A, nums1, lenA);
            fun(B, nums2, lenB);
            for (j = k = lenC = 0; j < lenA || k < lenB;) {
                if (j == lenA) {
                    while (k < lenB) {
                        C[lenC++] = B[k++];
                    }
                } else if (k == lenB) {
                    while (j < lenA) {
                        C[lenC++] = A[j++];
                    }
                } else {
                    for (l = 0; j + l < lenA && k + l < lenB && A[j + l] == B[k + l]; l++)
                        ;
                    if (j + l == lenA || (k + l < lenB && A[j + l] < B[k + l])) {
                        C[lenC++] = B[k++];
                    } else {
                        C[lenC++] = A[j++];
                    }
                }
            }
            for (l = 0; l < lenC && ans[l] == C[l]; l++)
                ;
            if (l < lenC && ans[l] < C[l]) memcpy(ans, C, lenC * sizeof(int));
        }
        vector<int> v(ans, ans + K);
        return v;
    }
};

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<int> maxSubsequence(k, 0);
        int start = max(0, k - n), end = min(k, m);
        for (int i = start; i <= end; i++) {
            vector<int> subsequence1(MaxSubsequence(nums1, i));
            vector<int> subsequence2(MaxSubsequence(nums2, k - i));
            vector<int> curMaxSubsequence(merge(subsequence1, subsequence2));
            if (compare(curMaxSubsequence, 0, maxSubsequence, 0) > 0) {
                maxSubsequence.swap(curMaxSubsequence);
            }
        }
        return maxSubsequence;
    }

    vector<int> MaxSubsequence(vector<int>& nums, int k) {
        int length = nums.size();
        vector<int> stack(k, 0);
        int top = -1;
        int remain = length - k;
        for (int i = 0; i < length; i++) {
            int num = nums[i];
            while (top >= 0 && stack[top] < num && remain > 0) {
                top--;
                remain--;
            }
            if (top < k - 1) {
                stack[++top] = num;
            } else {
                remain--;
            }
        }
        return stack;
    }

    vector<int> merge(vector<int>& subsequence1, vector<int>& subsequence2) {
        int x = subsequence1.size(), y = subsequence2.size();
        if (x == 0) {
            return subsequence2;
        }
        if (y == 0) {
            return subsequence1;
        }
        int mergeLength = x + y;
        vector<int> merged(mergeLength);
        int index1 = 0, index2 = 0;
        for (int i = 0; i < mergeLength; i++) {
            if (compare(subsequence1, index1, subsequence2, index2) > 0) {
                merged[i] = subsequence1[index1++];
            } else {
                merged[i] = subsequence2[index2++];
            }
        }
        return merged;
    }

    int compare(vector<int>& subsequence1, int index1, vector<int>& subsequence2, int index2) {
        int x = subsequence1.size(), y = subsequence2.size();
        while (index1 < x && index2 < y) {
            int difference = subsequence1[index1] - subsequence2[index2];
            if (difference != 0) {
                return difference;
            }
            index1++;
            index2++;
        }
        return (x - index1) - (y - index2);
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/create-maximum-number/solution/pin-jie-zui-da-shu-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
// /*
// 假设数组一为[3,4,6,5]、数组二为[9,1,2,5,8,3]、k = 5;
// 组合情况有0 + 5、1 + 4、2 + 3、3 + 2、4 + 1五种情况,就是从此五种情况取出组合最大的一种;
// Math.max(0, k - n)表示若数组二的元素个数 >= k,则数组一的元素个数可以从0开始取,否则在数组二的大小基础上补.
// */
// public int[] maxNumber(int[] nums1, int[] nums2, int k) {
//     int m = nums1.length, n = nums2.length;
//     int[] res = new int[k];
//     for (int i = Math.max(0, k - n); i <= k && i <= m; i++) {
//         int[] arr = merge(maxArr(nums1, i), maxArr(nums2, k - i), k);
//         if (gt(arr, 0, res, 0)) res = arr;
//     }
//     return res;
// }

// /*
// 假设选择了2 + 3的情况,分别从两个数组取出相应元素个数的最大组合，对数组一来说就是[6,5],对数组二来说是[9,8,3];
// n - i : 当前数组中,当前下标到结尾还有多少个元素;
// j : 当前数组中i之前有多少个数加入到最大组合中;
// n - i + j > k <=> n - i - 1 + j >= k : 当前下标的元素大于最大组合的末尾元素，就需要弹出,弹出后的元素减少,故j--,
// n - i(数组剩余元素) - 1(去掉最大组合末尾元素) + j(最大组合中剩余元素)时刻保持 >= k;
// if j < k : 先将最大组合填满再进行比较替换操作
//  */
// private int[] maxArr(int[] nums, int k) {
//     int n = nums.length;
//     int[] res = new int[k];
//     for (int i = 0, j = 0; i < n; i++) {
//         while (n - i + j > k && j > 0 && nums[i] > res[j-1]) j--;
//         if (j < k) res[j++] = nums[i];
//     }
//     return res;
// }

// /*
// 假设数组一最大组合为[6,5],数组二最大组合为[9,8,3],进行双指针排序,排序后为[9,8,6,5,3]
//  */
// private int[] merge(int[] nums1, int[] nums2, int k) {
//     int[] res = new int[k];
//     for (int i = 0, j = 0, r = 0; r < k; r++)
//         res[r] = gt(nums1, i, nums2, j) ? nums1[i++] : nums2[j++];
//     return res;
// }

// /*
// 比较两数组相应位置大小,相等就一直跳过,直到不相等就比较.
//  */
// private boolean gt(int[] nums1, int i, int[] nums2, int j) {
//     while (i < nums1.length && j < nums2.length && nums1[i] == nums2[j]) {
//         i++;
//         j++;
//     }
//     return j == nums2.length || (i < nums1.length && nums1[i] > nums2[j]);
// }