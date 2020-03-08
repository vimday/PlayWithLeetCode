#include<bits/stdc++.h>
using namespace std;
//BFS 292ms
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& mr, vector<int>& ie) {
        vector<vector<int>> g(n);int s=-1;
        for(int i=0;i<n;i++){
            if(mr[i]!=-1)
                g[mr[i]].push_back(i);
            else
                s=i;
        }
        queue<pair<int,int>> q;q.push({s,0});
        int res=0,cnt=0;
        while(!q.empty()){
            int sz=q.size();
            cnt+=sz;if(cnt==n) return res;
            while(sz--){
                auto t=q.front();q.pop();
                int ci=t.first,cc=t.second;
                for(int &nb:g[ci]){
                    q.push({nb,cc+ie[ci]});
                    res=max(res,cc+ie[ci]);
                }
                    
            }
            
        }
        return res;
    }
};

//dfs 456ms
void dfs(vector<vector<int>>& mana, vector<int>& informTime, int id, int time, int& ans)
{
    time += informTime[id];
    if (mana[id].empty())
    {
        ans = max(ans, time);
        return;
    }
    for (auto& next : mana[id])
    {
        dfs(mana, informTime, next, time, ans);
    }
}

int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
{
    vector<vector<int>> mana(manager.size(), vector<int>());
    for (int i = 0; i < manager.size(); i++)
    {
        if (manager[i] == -1) continue;
        mana[manager[i]].push_back(i);
    }

    int ans = 0;
    dfs(mana, informTime, headID, 0, ans);
    return ans;
}

//wlp dfs 272ms

class Solution {
    int ans,h[100005],ne[100005],a[100005],d[100005];
    void dfs(int x)
    {
        ans=max(ans,d[x]);
        for(int i=h[x];~i;i=ne[i])
        {
            d[i]=d[x]+a[x];
            dfs(i);
        }
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        memset(h,-1,sizeof(h));
        int i;
        for(i=0;i<n;i++)if(i!=headID)
        {
            ne[i]=h[manager[i]];
            h[manager[i]]=i;
        }
        for(i=0;i<n;i++)a[i]=informTime[i];
        d[headID]=ans=0;
        dfs(headID);
        return ans;
    }
};

//zqy 320ms
class Solution {
    vector<int> G[100005];
    int ans = 0;
    void dfs(int cur, int acc, vector<int>& informTime){
        if (G[cur].empty()) ans = max(ans, acc);
        for (int x: G[cur])
            dfs(x, acc + informTime[cur], informTime);
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for (int i = 0; i < n; ++i)
            if (i != headID)
                G[manager[i]].push_back(i);
        dfs(headID, 0, informTime);
        return ans;
    }
};


//liouzhou  956ms

const int INF = 1000000000;

template<class weight_type>
struct weighted_directed_graph
{
	int n;
	vector<vector<pair<int, weight_type>>> v;
	
	weighted_directed_graph (int n = 0)
	{
		init(n);
	}
	void init(int n)
	{
		assert(n >= 0);
		this->n = n;
		v = vector<vector<pair<int, weight_type>>>(n+1);
	}
	void addedge(int x, int y, weight_type z)
	{
		assert(1 <= x && x <= n);
		assert(1 <= y && y <= n);
		v[x].push_back({y, z});
	}
	
	vector<weight_type> dis;
	weight_type shortest_path(int s, int t)
	{
		dis = vector<weight_type>(n+1, INF);
		dis[s] = 0;
		priority_queue<pair<weight_type, int>, vector<pair<weight_type, int>>, greater<pair<weight_type, int>>> Q;
		Q.push({0, s});
		while (!Q.empty())
		{
			weight_type d;
			int x;
			tie(d, x) = Q.top();
			Q.pop();
			if (dis[x] != d) continue;
			for (auto e : v[x])
			{
				int y, z;
				tie(y, z) = e;
				if (dis[y] > d+z) Q.push({dis[y] = d+z, y});
			}
		}
		return dis[t];
	}
};


class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        weighted_directed_graph<int> G(n);
        for (int i = 0; i < n; ++ i)
        {
            if (manager[i] == -1) continue;
            G.addedge(i+1, manager[i]+1, informTime[manager[i]]);
            G.addedge(manager[i]+1, i+1, informTime[manager[i]]);
        }
        G.shortest_path(headID+1, headID+1);
        int ret = 0;
        for (int i = 1; i <= n; ++ i) ret = max(ret, G.dis[i]);
        return ret;
    }
};