/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0628_minimum-size-subarray-sum.cpp
 * @Created Time:2020-06-28 00:19:31
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
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int ans = INT_MAX;
        vector<int> sums(n + 1, 0);
        // 为了方便计算，令 size = n + 1
        // sums[0] = 0 意味着前 0 个元素的前缀和为 0
        // sums[1] = A[0] 前 1 个元素的前缀和为 A[0]
        // 以此类推
        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        for (int i = 1; i <= n; i++) {
            int target = s + sums[i - 1];
            auto bound = lower_bound(sums.begin(), sums.end(), target);
            if (bound != sums.end()) {
                ans = min(ans, static_cast<int>((bound - sums.begin()) - (i - 1)));
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        // int n=nums.size(),res=INT_MAX;
        // int pre[n+1];memset(pre,0,sizeof pre);
        // for(int i=0;i<n;i++)
        //     pre[i+1]=pre[i]+nums[i];
        // deque<int>dq;
        // for(int i=0;i<=n;i++){
        //     while(!dq.empty()&&pre[i]-pre[dq.front()]>=s){
        //         if(i-dq.front()<res)
        //             res=i-dq.front();
        //         dq.pop_front();
        //     }
        //     dq.push_back(i);
        // }
        // return res==INT_MAX?0:res;
        int i = 0;
        int sum = 0;
        int len = 0;
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while (sum >= s) {
                len = len == 0 ? j - i + 1 : min(len, j - i + 1);
                sum -= nums[i++];
            }
        }
        return len;
    }
};