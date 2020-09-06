/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :CCC.cpp
 * @Created Time:2020-09-05 22:56:26
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
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        if (n < 2)
            return 0;
        int ed = -1, st = -1;
        for (int i = n - 1; i > 0; i--) {
            if (arr[i] < arr[i - 1]) {
                ed = i;
                break;
            }
        }
        if (ed == -1)
            return 0;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                st = i;
                break;
            }
        }
        int nst = st, ned = ed;
        for (; nst >= 0; nst--) {
            if (arr[nst] <= arr[ed])
                break;
        }
        if (nst == -1)
            return ed;
        for (; ned < n; ned++)
            if (arr[ned] >= arr[st])
                break;
        if (ned == n)
            return n - st - 1;
        return min(ed - nst - 1, ned - st - 1);
    }
};

// 双指针
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& v) {
        if (is_sorted(v.begin(), v.end())) {
            return 0;
        }
        v.insert(v.begin(), -1);
        v.push_back(1e9 + 7);
        int N = v.size();
        int R = N;
        for (int i = N - 2; i >= 0; --i) {
            if (v[i] > v[i + 1]) {
                R = i + 1;
                break;
            }
        }
        int L = 0;
        int best = R - L - 1;
        for (int i = R; i < N; ++i) {
            while (L + 1 < i && v[L + 1] <= v[i]) {
                if (v[L + 1] < v[L]) return best;
                L += 1;
                best = min(best, i - L - 1);
            }
        }
        return best;
    }
};

// 二分
const int MAXN = 1e5 + 1;
int dp[MAXN];

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        memset(dp, 0, sizeof(dp));
        int n = arr.size();
        dp[0] = 1;
        for (int i = 1; i < n; ++i) {
            if (arr[i] >= arr[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            } else {
                dp[i] = 1;
            }
        }
        if (dp[n - 1] == n)
            return 0;
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            bool bCan = false;
            for (int i = 0; i + mid <= n; ++i) {
                if (i == 0) {
                    if (dp[n - 1] >= n - mid) {
                        bCan = true;
                        break;
                    }
                } else if (i + mid == n) {
                    if (dp[i - 1] == n - mid) {
                        bCan = true;
                        break;
                    }
                } else {
                    if (dp[i - 1] == i && dp[n - 1] >= n - (i + mid) && arr[i - 1] <= arr[i + mid]) {
                        bCan = true;
                        break;
                    }
                }
            }
            if (bCan) {
                right = mid - 1;
            } else
                left = mid + 1;
        }

        return left;
    }
};

// 延伸1 找最长 上升子序列
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int dp[n] = {}, ml = 0;
        for (int& t : nums) {
            int l = 0, h = ml;
            while (l < h) {
                int mi = l + (h - l >> 1);
                dp[mi] < t ? l = mi + 1 : h = mi;
            }
            if (l == ml)
                dp[ml++] = t;
            else
                dp[l] = t;
        }
        return ml;
    }
};

// 延伸2 删除最短子序列是数组先增后减

#include <cstdio>
#include <iostream>

using namespace std;

const int maxn = 1e3 + 5;

int a[maxn];
int dp1[maxn];
int dp2[maxn];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int ans1 = -1;
    for (int i = 1; i <= n; i++) {
        dp1[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[j] >= a[i]) {
                dp1[i] = max(dp1[j] + 1, dp1[i]);
            }
        }
        ans1 = max(ans1, dp1[i]);
    }
    int ans2 = -1;
    for (int i = n; i >= 1; i--) {
        dp2[i] = 1;
        for (int j = n; j > i; j--) {
            if (a[i] <= a[j]) {
                dp2[i] = max(dp2[j] + 1, dp2[i]);
            }
        }
        ans2 = max(ans2, dp2[i]);
    }
    //    for(int i=1;i<=n;i++){
    //        cout<<dp1[i]<<" ";
    //    }
    //    cout<<endl;
    //    for(int i=1;i<=n;i++){
    //        cout<<dp2[i]<<" ";
    //    }
    //    cout<<endl;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(dp1[i] + dp2[i] - 1, res);
    }
    printf("%d\n", n - res);
    return 0;
}

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int st = -1, ed = -1;
        for (int i = n - 1; i > 0; i--) {
            if (arr[i] < arr[i - 1]) {
                ed = i;
                break;
            }
        }
        if (ed == -1)
            return 0;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                st = i;
                break;
            }
        }
        int nst = st, ned = ed;
        for (; nst >= 0; nst--)
            if (arr[nst] <= arr[ed])
                break;
        for (; ned < n; ned++)
            if (arr[ned] >= arr[st])
                break;
        return min(ned - st - 1, ed - nst - 1);
    }
};