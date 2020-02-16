#include<bits/stdc++.h>
using namespace std;
long long solve(long long n,long long g,long long b){
    long long lm=(n-1)/2+1;
    int cnt=lm/g;
    long long res=cnt*(g+b);
    if(lm%g)
        res+=lm%g;
    else
    {
        res-=b;
    }
    //cout<<"+++++++++"<<endl;
    return max(res,n);
}
int main(int argc, char const *argv[])
{
    /* code */
    int T;
    cin>>T;
    while(T--){
        long long n,g,b;
        cin>>n>>g>>b;
        cout<<solve(n,g,b)<<endl;
    }
    return 0;
}
