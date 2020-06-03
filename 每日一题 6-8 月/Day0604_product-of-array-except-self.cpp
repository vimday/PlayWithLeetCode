/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0604_product-of-array-except-self.cpp
 * @Created Time:2020-06-04 00:12:56
 * @E-mail      :lwftx@outlook.com
 * @GitHub      :https://github.com/vimday
 */
#include<bits/stdc++.h>
using namespace std;
void debug(){
    #ifdef LOCAL
         freopen("E:\\Cpp\\in.txt", "r", stdin);
         freopen("E:\\Cpp\\out.txt", "w", stdout);
    #endif
}
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,1);
        int l=1;
        for(int i=1;i<n;++i){
            l*=nums[i-1];
            res[i]=l;
        }
        int r=1;
        for(int i=n-2;i>=0;i--){
            r*=nums[i+1];
            res[i]*=r;
        }
        return res;
    }
};