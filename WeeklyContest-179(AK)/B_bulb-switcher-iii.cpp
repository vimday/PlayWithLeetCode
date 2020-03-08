#include<bits/stdc++.h>
using namespace std;
//刚开始想复杂了 以为要用到线段树或者树状数组来更新
class Solution {
public:
    int numTimesAllBlue(vector<int>& lt) {
        int n=lt.size(),res=0;
        int ch=-1;
        for(int i=0;i<n;i++){
            int t=lt[i];
            ch=max(t,ch);
            if(ch==i+1)
                res++;
        }
        return res;
    }
};


//wlp大佬的树状数组

class Solution {
    int t[50005];
public:
    int numTimesAllBlue(vector<int>& light) {
        int n=light.size(),i,j,k,ans=0;
        for(i=1;i<=n;i++)
        {
            for(j=light[i-1];j<=n;j+=j&-j)t[j]++;
            for(j=i,k=0;j;j^=j&-j)k+=t[j];//异或也可以换成减
            if(k==i)ans++;
        }
        return ans;
    }
};

//zqy
class Solution {
    bool vis[50005];
public:
    int numTimesAllBlue(vector<int>& light) {
        int cur = 0, ans = 0, maxi = 0;
        for (int x: light){
            vis[x] = true;
            maxi = max(maxi, x);
            while (vis[cur + 1])
                ++cur;
            if (cur == maxi) ++ans;
        }
        return ans;
    }
};

