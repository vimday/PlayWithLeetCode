#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& ps) {
        int res=0,cm=INT_MAX;
        for(int&i:ps)
            if(i<cm)
                cm=i;
            else if(i-cm>res)
                res=i-cm;
        return res;
        
    }
};