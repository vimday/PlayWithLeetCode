/*
 * @Author      :vimday
 * @Desc        :lc 每日一题 5.17 拓扑排序
 * @Url         :https://leetcode-cn.com/problems/course-schedule-ii/submissions/
 * @File Name   :Day78course-schedule-ii.cpp
 * @Created Time:2020-05-17 16:34:54
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
    vector<int> findOrder(int n, vector<vector<int>> &p) {
        vector<int> res;
        int ind[n];
        memset(ind, 0, sizeof ind);
        vector<vector<int>> g(n, vector<int>());
        for (vector<int> &v : p) {
            g[v[1]].emplace_back(v[0]);
            ind[v[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (ind[i] == 0)
                q.push(i);
        //bfs
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            res.push_back(t);
            for (int nb : g[t])
                if (--ind[nb] == 0)
                    q.push(nb);
        }
        if (res.size() != n) return {};
        // stack<int> s;
        // int me[n]={};
        // vector<vector<int>> g(n,vector<int>());
        // for(vector<int> &v:p){
        //     g[v[1]].emplace_back(v[0]);
        // }
        // for(int i=0;i<n;++i){
        //     if(me[i]==0&&!dfs(i,s,me,g))
        //         return res;
        // }
        // while(!s.empty()){
        //     res.emplace_back(s.top());
        //     s.pop();
        // }
        return res;
    }
    //这道做过了,换种 bfs 写一遍
    bool dfs(int i, stack<int> &s, int *me, vector<vector<int>> &g) {
        if (me[i] == 2) return true;  //2代表已完成 1 代表遍历中
        me[i] = 1;
        for (int t : g[i]) {
            if (me[t] == 1 || !dfs(t, s, me, g))
                return false;
        }
        me[i] = 2;
        s.push(i);
        return true;
    }
};
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int> indegree(numCourses, 0);

        for (auto &p : prerequisites) {
            graph[p[0]].push_back(p[1]);
            indegree[p[1]]++;
        }

        stack<int> stk;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) stk.push(i);
        }

        stack<int> order;
        while (!stk.empty()) {
            int c = stk.top();
            stk.pop();
            order.push(c);
            for (auto &pre : graph[c]) {
                indegree[pre]--;
                if (indegree[pre] == 0) {
                    stk.push(pre);
                }
            }
        }

        vector<int> res;
        if (order.size() < numCourses) return res;
        while (!order.empty()) {
            res.push_back(order.top());
            order.pop();
        }
        return res;
    }
};