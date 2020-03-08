#include<bits/stdc++.h>
using namespace std;

//wlp
class Solution {
    string ans;
public:
    string generateTheString(int n) {
        int i;
        ans="";
        for(i=1;i<n;i++)ans+='a';
        if(n&1)ans+='a';
        else ans+='b';
        return ans;
    }
};

//lj code by me
class Solution {
public:
    string generateTheString(int n) {
        string res;
        if(n==1)
            return "n";
        if(n%2==0&&(n/2)%2==0){
            int t=(n/2);
            for(int i=0;i<t-1;i++)
                res+="a";
            for(int i=0;i<t+1;i++)
                res+="b";
            return res;
        }
        if(n%2==0&&(n/2)%2==1){
            int t=n/2;
            for(int i=0;i<t;i++)
                res+="a";
            for(int i=0;i<t;i++)
                res+="b";
            return res;
        }
        if(n%2==1){
            int t=(n+1)/2;
            //t-1 t
            if((t-1)%2){
                for(int i=0;i<t-1;i++)
                    res+="a";
                if((t/2)%2==0){
                    int tt=(t/2);
                for(int i=0;i<tt-1;i++)
                    res+="b";
                for(int i=0;i<tt+1;i++)
                    res+="c";
                return res;
                }
            if((t/2)%2==1){
                int tt=t/2;
                for(int i=0;i<tt;i++)
                    res+="b";
                for(int i=0;i<tt;i++)
                    res+="c";
                return res;
            }
        }else{
                for(int i=0;i<t;i++)
                    res+="a";
                if(((t-1)/2)%2==0){
                    int tt=((t-1)/2);
                for(int i=0;i<tt-1;i++)
                    res+="b";
                for(int i=0;i<tt+1;i++)
                    res+="c";
                return res;
                }
            if(((t-1)/2)%2==1){
                int tt=(t-1)/2;
                for(int i=0;i<tt;i++)
                    res+="b";
                for(int i=0;i<tt;i++)
                    res+="c";
                return res;
            }
            }
        }
        return res;
    }
};