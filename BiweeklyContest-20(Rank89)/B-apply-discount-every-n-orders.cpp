#include<bits/stdc++.h>
using namespace std;
class Cashier {
public:
    int n,dt,cnt;
    int m[205]={};
    Cashier(int n, int dt, vector<int>& pts, vector<int>& pcs) {
        cnt=1;
        this->n=n;this->dt=dt;
        int sz=pts.size();
        for(int i=0;i<sz;i++)
            m[pts[i]]=pcs[i];
    }
    
    double getBill(vector<int> pt, vector<int> at) {
        double res=0;int sz=pt.size();
        for(int i=0;i<sz;i++)
            res+=m[pt[i]]*at[i];
        if(cnt++%n==0)
            return res-(dt*res)/100;
        return res;
        

    }
};