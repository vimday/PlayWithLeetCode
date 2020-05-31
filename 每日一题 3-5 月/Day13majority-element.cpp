#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res=0,cnt=0;
        for(int&i:nums){
            if(cnt==0){
                res=i;
                cnt=1;
            }else if(i==res)
                cnt++;
            else
                cnt--;
        }
        return res;
    }
};