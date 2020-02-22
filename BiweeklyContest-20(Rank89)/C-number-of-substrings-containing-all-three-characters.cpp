#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nxa[50005],nxb[50005],nxc[50005];

    int numberOfSubstrings(string s) {
        int n=s.size();
        nxa[n]=-1;nxb[n]=-1;nxc[n]=-1;
        for(int i=n-1;i>=0;--i){
            nxa[i]=nxa[i+1];
            nxb[i]=nxb[i+1];
            nxc[i]=nxc[i+1];
            if(s[i]=='a')
                nxa[i]=i;
            else if(s[i]=='b')
                nxb[i]=i;
            else nxc[i]=i;
        }
        int res=0;
        for(int i=0;i<n-2;i++){
            char c=s[i];
            if(c=='a'){
                int r1=nxb[i];
                int r2=nxc[i];
                if(r1==-1||r2==-1)
                    return res;
                int r=max(r1,r2);
                res+=n-r;
            }
            if(c=='b'){
                int r1=nxa[i];
                int r2=nxc[i];
                if(r1==-1||r2==-1)
                    return res;
                int r=max(r1,r2);
                res+=n-r;
            }
            if(c=='c'){
                int r1=nxb[i];
                int r2=nxa[i];
                if(r1==-1||r2==-1)
                    return res;
                int r=max(r1,r2);
                res+=n-r;
            }
        }
        return res;

    }
};