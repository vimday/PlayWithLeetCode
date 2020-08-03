/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0804_course-schedule.cpp
 * @Created Time:2020-08-04 00:36:45
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
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int> ind(n, 0);
        vector<vector<int>> g(n, vector<int>());
        for (vector<int>& v : p) {
            g[v[1]].emplace_back(v[0]);
            ind[v[0]]++;
        }
        queue<int> q;
        int sz = 0;
        for (int i = 0; i < n; ++i) {
            if (ind[i] == 0) {
                q.push(i);
                ++sz;
            }
        }
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (int i : g[t]) {
                ind[i]--;
                if (ind[i] == 0) {
                    q.push(i);
                    ++sz;
                }
            }
        }
        return sz == n;
    }
};
class Solution {
public:
    vector<vector<int>> g;
    vector<int> m;
    stack<int> s;
    bool canFinish(int n, vector<vector<int>>& p) {
        g = vector<vector<int>>(n, vector<int>());
        m = vector<int>(n, 0);
        for (vector<int>& v : p)
            g[v[0]].emplace_back(v[1]);
        for (int i = 0; i < n; ++i) {
            if (m[i] == 0 && !dfs(i))
                return false;
        }
        return true;
    }
    // bool dfs(int i){
    //     //if(m[i]==2) return true;
    //     m[i]=1;
    //     s.push(i);
    //     while(!s.empty()){
    //         int t=s.top();s.pop();
    //         if(g[t].empty())
    //         {
    //             m[t]=2;
    //             continue;
    //         }
    //         for(int tt:g[t]){
    //             if(m[tt]==1)
    //                 return false;
    //             if(m[tt]==2)
    //                 continue;
    //             m[tt]=1;
    //             s.push(tt);
    //         }
    //         //m[t]=2;
    //     }
    //     m[i]=2;
    //     //cout<<i;
    //     return true;
    // }
    bool dfs(int i) {
        //if(m[i]==1) return false;
        if (m[i] == 2) return true;
        m[i] = 1;
        for (int t : g[i]) {
            if (m[t] == 1 || !dfs(t))
                return false;
        }
        m[i] = 2;
        return true;
    }
};