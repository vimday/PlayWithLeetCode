#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> distributeCandies(int cs, int n) {
        vector<int> res(n);int i=0;
        while(cs>i){
            res[i%n]+=i+1;
            
            cs-=++i;
        }
        res[i%n]+=cs;
        return res;
        
    }
};