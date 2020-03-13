/*
 * @Author      :vimday
 * @Desc        :leetcode day problem
 * @File Name   :Day14.cpp
 * @Created Time: 2020-03-14 00:08:14
 * @E-mail      :lwftx@outlook.com
 * @Url         :https://github.com/vimday
 */
#include<bits/stdc++.h>
using namespace std;
void debug(){
    #ifdef LOCAL
         freopen("E:\Cpp\in.txt", "r", stdin);
         freopen("E:\Cpp\out.txt", "w", stdout);
    #endif
}
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();if(n==0)return 0;
        int dp[n]={},ml=0;
        for(int &i:nums){
            int l=0,h=ml;
            while(l<h){
                int mi=l+(h-l>>1);
                i>dp[mi]?l=mi+1:h=mi;
            }
            dp[l]=i;
            if(l==ml)
                ml++;
        }
        return ml;
        
        // int dp[n],res=1;
        // for(int i=0;i<n;i++)
        //     dp[i]=1;
        // for(int i=1;i<n;i++)
        //     for(int j=i-1;j>=0;j--)
        //         if(nums[j]<nums[i])
        //         {
        //             dp[i]=max(dp[i],dp[j]+1);
        //             res=max(res,dp[i]);
        //         }
        // return res;
    }
};