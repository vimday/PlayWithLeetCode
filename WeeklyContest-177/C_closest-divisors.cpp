#include<bits/stdc++.h>
using namespace std;

//简单贪心即可

class Solution {
public:
    vector<int> closestDivisors(int num) {
        int num1 = num + 1;
        int num2 = num + 2;
        long long v = sqrt(num2);
        
        for(int i = v; i > 0; i--)
        {
            if(num1 % i == 0)   return {i, num1/i};
            if(num2 % i == 0)   return {i, num2/i};
        }
        return {0, 0};
    }
};
//tcl  迟到就没想太多了  想复杂了
class Solution {
public:
    vector<int> closestDivisors(int num) {
        int cc=sqrt(num)+1;
        if(cc*cc==num+1||cc*cc==num+2) return {cc,cc};
        int cm=INT_MAX,l=0,r=0,j=0;
        bool f=true;
        for(int i=cc;i>0&&f&&abs(i-j)<cm;--i)
            for(j=(num+1)/i;j<=num+1&&abs(i-j)<cm;j++){
                if(i*j>num+2){
                    // if(i<cc-50000)
                    // f=false;
                    break;
                }
                if(i*j==num+1||i*j==num+2){
                    f=false;
                    //cout<<i<<" "<<j<<endl;
                    int ccm=abs(i-j);
                    if(ccm<cm){
                        cm=ccm;
                        l=i;r=j;
                    }
                    break;
                }
            }
        f=true;
        for(int i=cc;i<=num+1&&f&&abs(i-j)<cm;++i)
            for(j=(num+2)/i+1;j>0&&abs(i-j)<cm;j--){
                if(i*j<num+1){
                    // if(i>cc+50000)
                    // f=false;
                    break;
                }
                if(i*j==num+1||i*j==num+2){
                    f=false;
                    //cout<<i<<" "<<j<<endl;
                    int ccm=abs(i-j);
                    if(ccm<cm){
                        cm=ccm;
                        l=i;r=j;
                    }
                    break;
                }
            }
        return {l,r};
                
    }
};