#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getn(int i){
        int res=0;
        while(i){
            if(i&1)
                res++;
            i=i>>1;
        }
        return res;
    }
    vector<int> sortByBits(vector<int>& arr) {
        unordered_map<int,int> m;
        for(int&i:arr)
            if(m.count(i)==0)
                m[i]=getn(i);
        auto cmp=[](int i)->int{int res=0;
        while(i){
            if(i&1)
                res++;
            i=i>>1;
        }
        return res;};
        sort(arr.begin(),arr.end(),[&](int a,int b){return cmp(a)==cmp(b)?a<b:cmp(a)<cmp(b);});
        return arr;
    }
};