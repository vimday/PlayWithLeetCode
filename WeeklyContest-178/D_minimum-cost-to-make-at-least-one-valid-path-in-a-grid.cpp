#include<bits/stdc++.h>
using namespace std;

const int dx[5] = {0, 1, -1, 0, 0};
const int dy[5] = {0, 0, 0, 1, -1};
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;
//124ms
//在优先队列实现中，并不需要显式地进行decrease_key操作，
//因为我们只要将更新后的权值加入优先队列中，它就会排到原先较大的权值前面，从而变相实现了权值的减小。
//而由于我们使用了标记数组vis来记录每一个节点是否已经拓展过，原来较大的权值在出队时就会被跳过。
//dij
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INF));
        dist[0][0] = 0;
        priority_queue<pii, vector<pii>, greater<>> pq;
        pq.push(make_pair(0, 0));
        vector<bool> vis(n * m);
        while (!pq.empty()) {
            pii f = pq.top();
            pq.pop();
            if (vis[f.second]) continue;
            vis[f.second] = true;
            int y = f.second / m, x = f.second % m;
            for (int k = 1; k <= 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;
                int nd = f.first + (grid[y][x] == k ? 0 : 1);
                if (nd < dist[ny][nx]) {
                    dist[ny][nx] = nd;
                    pq.push(make_pair(dist[ny][nx], ny * m + nx));
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};
//大佬们 tql
//作者：lucifer1004
//链接：https://leetcode-cn.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/solution/zui-duan-lu-jing-suan-fa-bfs0-1bfsdijkstra-by-luci/
//96ms
class Solution {
public:
    int d[5][2]={{0,0},{0,1},{0,-1},{1,0},{-1,0}};
    int minCost(vector<vector<int>>& g) {
        int m=g.size(),n=g[0].size();
        int me[m*n];
        memset(me,0x3f,sizeof me);
        function<bool(int,int)> cmp=[&me](int a,int b){return me[a]>me[b];};
        priority_queue<int,vector<int>,decltype(cmp)> pq(cmp);
        me[0]=0;
        pq.push(0);
        while(!pq.empty()){
            int t=pq.top();pq.pop();
            //if(t==m*n-1) return me[m*n-1]; *************！！！！！不能提前退出
            int i=t/n,j=t%n;
            for(int k=1;k<5;k++){
                int r=i+d[k][0],c=j+d[k][1];
                if(r<0||c<0||r>=m||c>=n)
                    continue;
                int nt=r*n+c,nd=g[i][j]==k?0:1;
                if(me[nt]>me[t]+nd){
                    me[nt]=me[t]+nd;
                    pq.push(nt);//！！！！！！！！！！ 此时修改me，并不会更新更新 整个堆，使用变化的数组做比较操作 的弊端显而易见，若nt已在堆中，此时push 有可能并不把nt提前
                                //！！！！！！！！！！！push_heap的实现是自低向上更新，早终止
                }
                
            }
        }
        return me[m*n-1];
    }
};
//bfs
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pii> pq;
        pq.push(make_pair(0, 0));
        vector<vector<int>> dist(n, vector<int>(m, INF));
        dist[0][0] = 0;
        while (!pq.empty()) {
            pii f = pq.front();
            pq.pop();
            int y = f.first, x = f.second;
            for (int k = 1; k <= 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;
                int nd = dist[y][x] + (grid[y][x] == k ? 0 : 1);
                if (nd < dist[ny][nx]) {
                    dist[ny][nx] = nd;
                    pq.push(make_pair(ny, nx));
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};
//spfa
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pii> pq;
        pq.push(make_pair(0, 0));
        vector<vector<bool>> in(n, vector<bool>(m));
        vector<vector<int>> dist(n, vector<int>(m, INF));
        dist[0][0] = 0;
        in[0][0] = true;
        while (!pq.empty()) {
            pii f = pq.front();
            pq.pop();
            int y = f.first, x = f.second;
            in[y][x] = false;
            for (int k = 1; k <= 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;
                int nd = dist[y][x] + (grid[y][x] == k ? 0 : 1);
                if (nd < dist[ny][nx]) {
                    dist[ny][nx] = nd;
                    if (!in[ny][nx]) {
                        pq.push(make_pair(ny, nx));
                        in[ny][nx] = true;                                          
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};
//最快的0-1bfs
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        deque<pii> pq;
        pq.push_back(make_pair(0, 0));
        vector<vector<bool>> vis(n, vector<bool>(m));
        while (!pq.empty()) {
            pii f = pq.front();
            pq.pop_front();
            int y = f.second / m, x = f.second % m;
            if (vis[y][x]) continue;
            vis[y][x] = true;
            if (y == n - 1 && x == m - 1)
                return f.first;
            for (int k = 1; k <= 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;
                if (grid[y][x] == k) 
                    pq.push_front(make_pair(f.first, ny * m + nx));
                else
                    pq.push_back(make_pair(f.first + 1, ny * m + nx));
            }
        }
        return 0;
    }
};

//my deque
class Solution {
public:
    const int dx[5]={0,0,0,1,-1},dy[5]={0,1,-1,0,0};
    int minCost(vector<vector<int>>& g) {
        int m=g.size(),n=g[0].size();
        deque<int> dq;
        int me[m*n];memset(me,0x3f,sizeof me);
        bool vis[m*n]={};
        
        me[0]=0;dq.push_back(0);
        while(!dq.empty()){
            int t=dq.front();dq.pop_front();
            if(t==m*n-1) return me[t];
            if(vis[t]) continue;
            vis[t]=true;
            int i=t/n,j=t%n;
            for(int k=1;k<5;k++){
                int r=i+dx[k],c=j+dy[k];
                if(r>=0&&r<m&&c>=0&&c<n){
                    int nx=r*n+c;
                    if(k==g[i][j]){
                        if(me[t]<me[nx]){
                            me[nx]=me[t];
                            dq.push_front(nx);
                        }
                    }else if(me[t]+1<me[nx]){
                        me[nx]=me[t]+1;
                        dq.push_back(nx);
                    }
                        
                }
            }
        }
        return 0;
    }
};
//68ms
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>visited(n, vector<int>(m,10000));//表示到达某个点最少需要修改多少次
        struct node { int x, y, c; };//queue+vector很慢
        auto cmp = [](node& a, node& b) {return a.c > b.c; };
        priority_queue<node,vector<node>,decltype(cmp)>que(cmp);
        que.push({ 0,0,0 });
        vector<vector<int>>dir = { {0,1},{0,-1},{1,0},{-1,0} };
        for(;que.size();que.pop())
        {
            auto top = que.top();
            if (top.x == n - 1 && top.y == m - 1) return top.c;
            for (int i = 0; i < 4; i++)
            {
                int nx = top.x + dir[i][0],ny = top.y + dir[i][1];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m)
                    if(top.c + (grid[top.x][top.y] != i + 1)<visited[nx][ny])
                    {//如果可以经过较小的修改次数到该点，就更新该点，其实就是dijkstra算法
                        visited[nx][ny]=top.c + (grid[top.x][top.y] != i + 1);
                        que.push({ nx,ny,top.c + (grid[top.x][top.y] != i + 1) });
                    }
            }
        }
        return 0;
    }
};

//liuzhou大佬的模板
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

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

class Solution {
public:
    int minCost(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        int N = n*m;
        
        auto place = [&](int x, int y)
        {
            return x*m+y+1;
        };
        
        weighted_directed_graph<int> G(N);
        for (int i = 0; i < n; ++ i)
            for (int j = 0; j < m; ++ j)
            {
                for (int k = 0; k < 4; ++ k)
                {
                    int x = i+dx[k], y = j+dy[k];
                    if (0 <= x && x < n && 0 <= y && y < m)
                    {
                        G.addedge(place(i, j), place(x, y), k+1 != a[i][j]);
                    }
                }
            }
        auto ret = G.shortest_path(place(0, 0), place(n-1, m-1));
        return ret;
    }
};

//wlp比赛时就想到了
class Solution {
    const int dx[5]={0,0,0,1,-1},dy[5]={0,1,-1,0,0};
    int d[105][105];
    deque<pair<int,int>> q;
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),i,j,k;
        memset(d,127,sizeof(d));
        d[0][0]=0;
        q.clear();
        q.push_back(make_pair(0,0));
        while(!q.empty())
        {
            i=q.front().first;
            j=q.front().second;
            q.pop_front();
            for(k=1;k<5;k++)if(i+dx[k]>=0&&i+dx[k]<n&&j+dy[k]>=0&&j+dy[k]<m)if(k==grid[i][j]&&d[i+dx[k]][j+dy[k]]>d[i][j])
            {
                d[i+dx[k]][j+dy[k]]=d[i][j];
                q.push_front(make_pair(i+dx[k],j+dy[k]));
            }
            else if(k!=grid[i][j]&&d[i+dx[k]][j+dy[k]]>d[i][j]+1)
            {
                d[i+dx[k]][j+dy[k]]=d[i][j]+1;
                q.push_back(make_pair(i+dx[k],j+dy[k]));
            }
        }
        return d[n-1][m-1];
    }
};