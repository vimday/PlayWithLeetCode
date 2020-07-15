/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0716_dfs_bfs_is-graph-bipartite.cpp
 * @Created Time:2020-07-16 00:31:39
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
public:
    queue<int> q;
    stack<int> s;
    vector<int> co;
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        co = vector<int>(n, 0);
        for (int i = 0; i < n; ++i) {
            if (co[i] == 0 && !isB(i, graph))  //递归版为（i，1，graph）
                return false;
        }
        return true;
    }
    //栈dfs
    bool isB(int t, vector<vector<int>>& g) {
        co[t] = 1;
        s.push(t);
        while (!s.empty()) {
            int from = s.top();
            s.pop();
            int cc = co[from];
            for (int i : g[from]) {
                if (co[i] == 0) {
                    co[i] = -cc;
                    s.push(i);
                } else if (co[i] == cc)
                    return false;
            }
        }
        return true;
    }
    //栈递归
    // bool isB(int s,int cc,vector<vector<int>>& g){
    //     if(co[s]!=0)
    //         return co[s]==cc;
    //     co[s]=cc;
    //     for(int i:g[s]){
    //         if(!isB(i,-cc,g))
    //             return false;
    //     }
    //     return true;
    // }
    //BFS版
    // bool isB(int s,vector<vector<int>>& g){
    //     co[s]=1;
    //     q.push(s);
    //     while(!q.empty()){
    //         int from=q.front();q.pop();
    //         for(int x:g[from]){
    //             if(co[x]==0){
    //                 q.push(x);
    //                 co[x]=-co[from];
    //             }
    //             if(co[x]==co[from])
    //                 return false;
    //         }
    //     }
    //     return true;
    // }
};