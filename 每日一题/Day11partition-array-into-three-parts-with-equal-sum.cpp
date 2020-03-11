#include<vector>
using namespace std;


class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int s=0;
        for(int&i:A) s+=i;
        if(s%3) return false;
        s/=3;int cnt=0,cs=0;;
        for(int i=0;i<A.size();i++){
            cs+=A[i];
            if(cs==s){
                cnt++;
                cs=0;
                if(cnt==2&&i!=A.size()-1)
                    return true;
            }
        }
        return false;
        
    }
};