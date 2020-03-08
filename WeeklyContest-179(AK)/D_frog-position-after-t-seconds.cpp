#include<bits/stdc++.h>
using namespace std;

//bfs 28ms
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& es, int t, int tt) {
        vector<vector<int>> g(n+1);
        for(vector<int>&v:es){
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }
        vector<int> m(n+1);
        double cc=1.0;
        queue<pair<int,double>> q;
        q.push({1,1.0});m[1]=1;int cur=0;
        while(!q.empty()&&cur<=t){
            int sz=q.size();
            while(sz--){
                auto pp=q.front();q.pop();
                int ci=pp.first;double pi=pp.second;
                if(ci==tt){
                    int ct=0;
                    for(int &nb:g[ci])
                        if(m[nb]==0)
                            ct++;
                    if(ct>0)
                        return cur==t?pi:0;
                    return pi;
                }
                int ct=0;
                    for(int &nb:g[ci])
                        if(m[nb]==0)
                            ct++;
                for(int &nb:g[ci]){
                    if(m[nb]==0){
                        m[nb]=1;
                        q.push({nb,pi/ct});
                    }
                }
            }
            cur++;
        }
        return 0;
    }
};

//dfs 20ms wlp
class Solution {
    double a[105];
    int m,d[105],c[105],h[105],ne[205],p[205],f[105];
    void dfs(int x)
    {
        int i;
        for(i=h[x],c[x]=0;i;i=ne[i])if(p[i]!=f[x])c[x]++;
        for(i=h[x];i;i=ne[i])if(p[i]!=f[x])
        {
            f[p[i]]=x;
            d[p[i]]=d[x]+1;
            a[p[i]]=a[x]/c[x];
            dfs(p[i]);
        }
    }
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        m=0;
        for(auto e:edges)
        {
            p[++m]=e[1];
            ne[m]=h[e[0]];
            h[e[0]]=m;
            p[++m]=e[0];
            ne[m]=h[e[1]];
            h[e[1]]=m;
        }
        a[1]=1;
        d[1]=f[1]=0;
        dfs(1);
        if(d[target]==t||d[target]<t&&!c[target])return a[target];
        return 0;
    }
};

//zqy 28ms
class Solution {
    double f[105][55];
    vector<int> G[105];
    void dfs(int cur, int fa, int curt){
        int sz = G[cur].size();
        if (fa != 0) --sz; 
        if (sz == 0){
            f[cur][curt] += f[cur][curt - 1];
            return ;
        }
        for (int x: G[cur]){
            if (x == fa) continue;
            f[x][curt] = 1.0 * f[cur][curt - 1] * (1.0 / sz);
            dfs(x, cur, curt);
        }
    }
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        for (auto& v: edges)
            G[v[0]].push_back(v[1]), G[v[1]].push_back(v[0]);
        f[1][0] = 1;
        for (int i = 1; i <= t; ++i)
            dfs(1, 0, i);
        return f[target][t];
    }
};

//liouzhou 52ms
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> v(n+1);
        for (auto e : edges)
        {
            int x = e[0], y = e[1];
            v[x].push_back(y);
            v[y].push_back(x);
        }
        
        vector<vector<double>> f(111, vector<double>(n+1));
        
        function<void(int, int, int)> dfs = [&](int x, int d, int p)
        {
            int sons = 0;
            for (auto y : v[x])
            {
                if (y == p) continue;
                sons ++;
            }
            for (auto y : v[x])
            {
                if (y == p) continue;
                f[d+1][y] = f[d][x]/sons;
                dfs(y, d+1, x);
            }
            if (sons == 0)
            {
                for (int i = d+1; i <= t; ++ i)
                    f[i][x] = f[d][x];
            }
        };
        
        f[0][1] = 1;
        dfs(1, 0, 0);
        
        return f[t][target];
    }
};