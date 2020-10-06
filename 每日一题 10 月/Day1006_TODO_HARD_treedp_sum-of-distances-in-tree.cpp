/*
 * @Author      :vimday
 * @Desc        :树形DP
 * @Url         :https://leetcode-cn.com/problems/sum-of-distances-in-tree/solution/shu-zhong-ju-chi-zhi-he-by-leetcode-solution/
 * @File Name   :Day1006_TODO_HARD_treedp_sum-of-distances-in-tree.cpp
 * @Created Time:2020-10-06 12:59:55
 * @E-mail      :lwftx@outlook.com
 * @GitHub      :https://github.com/vimday
 */
#include <bits/stdc++.h>
using namespace std;
void debug() {
#ifdef LOCAL
    freopen("E:\\Cpp\\in.txt", "r", stdin);
    freopen("E:\\Cpp\\out.txt", "w", stdout);
#endif
}
class Solution {
private:
    int n;
    vector<int> g[10001];
    bool visited[10001];
    int children[10001];
    int sum[10001];

public:
    int dfsgetchildren(int v) {
        visited[v] = true;
        for (int i = 0; i < g[v].size(); i++) {
            if (!visited[g[v][i]])
                children[v] += dfsgetchildren(g[v][i]);
        }
        children[v]++;
        return children[v];
    }
    void dfsgetd(int v, int d) {
        visited[v] = true;
        d++;
        for (int i = 0; i < g[v].size(); i++) {
            if (!visited[g[v][i]])
                dfsgetd(g[v][i], d);
        }
        sum[0] += d;
    }
    void dfs(int v, int prev) {
        visited[v] = true;
        if (v) {
            sum[v] = sum[prev] - children[v] + (n - children[v]);
        }
        for (int i = 0; i < g[v].size(); i++) {
            if (!visited[g[v][i]])
                dfs(g[v][i], v);
        }
    }
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        n = N;
        for (vector<int>& v : edges) {
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }
        memset(visited, 0, sizeof visited);
        memset(children, 0, sizeof children);
        memset(sum, 0, sizeof sum);
        dfsgetchildren(0);
        memset(visited, 0, sizeof visited);
        dfsgetd(0, -1);
        memset(visited, 0, sizeof visited);
        dfs(0, -1);
        vector<int> res(n);
        for (int i = 0; i < n; i++)
            res[i] = sum[i];
        return res;
    }
};

class Solution {
public:
    vector<int> ans, sz, dp;
    vector<vector<int>> graph;

    void dfs(int u, int f) {
        sz[u] = 1;
        dp[u] = 0;
        for (auto& v : graph[u]) {
            if (v == f) {
                continue;
            }
            dfs(v, u);
            dp[u] += dp[v] + sz[v];
            sz[u] += sz[v];
        }
    }

    void dfs2(int u, int f) {
        ans[u] = dp[u];
        for (auto& v : graph[u]) {
            if (v == f) {
                continue;
            }
            int pu = dp[u], pv = dp[v];
            int su = sz[u], sv = sz[v];

            dp[u] -= dp[v] + sz[v];
            sz[u] -= sz[v];
            dp[v] += dp[u] + sz[u];
            sz[v] += sz[u];

            dfs2(v, u);

            dp[u] = pu, dp[v] = pv;
            sz[u] = su, sz[v] = sv;
        }
    }

    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        ans.resize(N, 0);
        sz.resize(N, 0);
        dp.resize(N, 0);
        graph.resize(N, {});
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }
        dfs(0, -1);
        dfs2(0, -1);
        return ans;
    }
};

//链接：https://leetcode-cn.com/problems/sum-of-distances-in-tree/solution/shu-zhong-ju-chi-zhi-he-by-leetcode-solution/
