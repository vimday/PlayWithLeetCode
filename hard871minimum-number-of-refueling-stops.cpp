#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minRefuelStops(int tt, int sf, vector<vector<int>>& ss) {
        priority_queue<int> pq;int cs=sf,res=0,idx=0,n=ss.size();
        while(cs<tt){
            while(idx<n&&ss[idx][0]<=cs){
                pq.push(ss[idx++][1]);
            }
            if(pq.size()){
            cs+=pq.top();pq.pop();
            res++;}else return -1;
        }
        return res;
    }
};
//这题题目只需要想象为把油带在车上，然后往前走，
//当走到自己的油耗光时再从带上的油里找最大的那一桶油。这时的加油就相当于当时停下来加油