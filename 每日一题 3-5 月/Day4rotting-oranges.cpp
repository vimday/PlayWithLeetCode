#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int d[5]={-1,0,1,0,-1};
    int orangesRotting(vector<vector<int>>& g) {
        int m=g.size(),n=g[0].size(),cnt=0;
        queue<int> q;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(g[i][j]==1)
                    cnt++;
                else if(g[i][j]==2)
                    q.push(i*n+j);
        int res=0;
        while(!q.empty()){
            if(cnt==0)
                return res;
            int sz=q.size();
            res++;
            while(sz--){
                int t=q.front();q.pop();
                int i=t/n,j=t%n;
                for(int k=0;k<4;k++){
                    int r=i+d[k],c=j+d[k+1];
                    if(r>=0&&r<m&&c>=0&&c<n&&g[r][c]==1){
                        g[r][c]=2;
                        cnt--;
                        q.push(r*n+c);
                    }
                }
            }
        }
        return cnt==0?0:-1;
    }
};