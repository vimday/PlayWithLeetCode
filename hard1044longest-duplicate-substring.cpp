#include<bits/stdc++.h>
using namespace std;

//超内存
class Solution {
public:
    string longestDupSubstring(string ss) {
        int n=ss.size();string res;
        vector<string> sa(n);
        for(int i=0;i<n;i++)
            sa[i]=ss.substr(i);
        sort(sa.begin(),sa.end());
        for(int i=1;i<n;i++){
            int sz=min(sa[i].size(),sa[i-1].size()),j=0;
            while(j<sz&&sa[i-1][j]==sa[i][j]) j++;
            if(j>res.size())
                    res=sa[i].substr(0,j);
        }
        return res;

    }
};