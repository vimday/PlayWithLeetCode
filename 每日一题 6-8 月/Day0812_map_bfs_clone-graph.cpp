/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0812_map_bfs_clone-graph.cpp
 * @Created Time:2020-08-12 00:19:23
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
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> m;

        queue<Node*> q;
        q.push(node);
        Node* res = new Node(node->val, vector<Node*>());
        m[node] = res;
        while (!q.empty()) {
            int sz = q.size();
            Node* t = q.front();
            q.pop();
            //cout<<t->val;
            for (Node* nd : t->neighbors) {
                if (!m.count(nd)) {
                    Node* cp = new Node(nd->val, vector<Node*>());
                    m[nd] = cp;
                    q.push(nd);
                }
                m[t]->neighbors.emplace_back(m[nd]);
            }
        }
        return res;
        //         q.push(node);
        //         unordered_set<Node*> memo;
        //         memo.insert(node);
        //         while(!q.empty()){
        //             int sz=q.size();
        //             while(sz--){

        //                 Node *t=q.front();q.pop();
        //                 for(Node* nd:t->neighbors){
        //                     m[t]->neighbors.emplace_back(m[nd]);
        //                     if(!memo.count(nd))
        //                         {memo.insert(nd);
        //                         q.push(nd);}

        //                 }
        //             }
        //         }
        //         return m[node];
    }
};