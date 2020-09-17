/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0917_TODO_HARD_redundant-connection-ii.cpp
 * @Created Time:2020-09-17 11:06:53
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
struct UnionFind {
public:
    vector<int> sz, parent;
    UnionFind(const int n) {
        sz.reserve(n);
        sz.assign(n, 1);
        parent.reserve(n);
        for (int i = 0; i < n; ++i)
            parent.push_back(i);
    }

    int findParent(int x) {
        while (x != parent[x]) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    bool merge(int x, int y) {
        int p = findParent(x);
        int q = findParent(y);
        if (p == q)
            return false;
        else if (sz[p] >= sz[q]) {
            sz[p] += sz[q];
            parent[q] = p;
        } else {
            sz[q] += sz[p];
            parent[p] = q;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> indegree;  // 记录每个节点的入度
        indegree.reserve(edges.size() + 1);
        indegree.assign(edges.size() + 1, 0);
        int abnormalNode = -1;          // 记录入度为 2 的节点
        vector<int> preNodeVec(2, -1);  // 记录入度为 2 的节点的两个父节点
        vector<int> preNodeMap;         // 记录每个节点的父节点
        preNodeMap.reserve(edges.size() + 1);
        preNodeMap.assign(edges.size() + 1, -1);

        // 统计每个节点的入度，寻找是否存在入度为2的节点
        for (auto& e : edges) {
            // 如果发现某个节点入度为 2，保存这个节点，同时保存这个节点的两个父节点
            if (++indegree[e[1]] > 1) {
                abnormalNode = e[1];
                preNodeVec[0] = preNodeMap[e[1]];
                preNodeVec[1] = e[0];
                break;
            }
            preNodeMap[e[1]] = e[0];
        }

        vector<int> ans;
        ans.reserve(2);
        ans.assign(2, abnormalNode);

        UnionFind uf(edges.size() + 1);
        // 如果存在入度为 2 的节点，删除靠后的那条边，测试是否有环
        // 如果有环，说明返回边是前一条边，如果无环，说明返回边应该是靠后的那条边
        if (abnormalNode != -1) {
            ans[0] = preNodeVec[1];
            bool find = true;
            for (auto& e : edges) {
                if (e[0] == ans[0] && e[1] == abnormalNode)
                    continue;
                else {
                    if (!uf.merge(e[0], e[1])) {
                        ans[0] = preNodeVec[0];
                        break;
                    }
                }
            }
        }
        // 如果没有入度为 2 的边，直接遍历 edges 中所有的边
        // 如果这条边合并了 2 个早已属于同一个集合的顶点，则返回这条边
        else {
            for (auto& e : edges)
                if (!uf.merge(e[0], e[1])) {
                    ans[0] = e[0];
                    ans[1] = e[1];
                    break;
                }
        }
        return ans;
    }
};

// 写在最前面，觉得思路很乱的时候拿起纸笔走一走样例，模拟模拟流程，会清晰许多。 题目说了只需要去除一条边，就能变成一个根树（有向），反过来说一定存在（可以存在很多）某个根树加了一条边变成了现在的图。 这条多余的边，会分为以下情况：

// 这条边从任意一个节点出发，指向树根。

// !image 这种情况下，树不合法的原因是，树没了根，因为所有点的入度都为1。显而易见的是在环上的任意一条边都可以删除，删除之后就可以得到一个合法的根树。 **即这条橙色的多余的边，只是我们上面提到的存在的可能性的某一种，如你所见，其实环上的每一条边都可以是“多余边”，请理解这句话**，既然每一条都可以删除，那按照题目要求删掉环中最后出现的那条边就好。

// 这条边从任意节点出发，指向祖先链上任意一个非根节点。领扣 !image 这种情况下，树不合法的原因是出现了一个有两个入度的节点，**并且其中一个入度来自环中的一条边**。可以观察到，这两个入度里，只能删除来自环里的那条边。

// 这条边从任意节点出发，指向非祖先链上任意一个节点。

// !image

// 这种情况下，树不合法的原因也是出现了一个有两个入度的节点，**但两个入度都在环上**。可以观察到，这两个入度都能删掉，所以按照题目要求删掉排序在后面的那条。

// **以上提到的环，都是指无向环，即假装这个图是个无向图的环**

// 情况分析清楚了，怎么做呢。我们可以从前到后，并查集合并每一条边，对于情况2、3，我们会在这个过程中碰到一条边导致某个点的入度从1变为2，也就是那个有两个入度的点的排在后面的那个入度。我们先把这两条边edge1，edge2记下来，**如果我们跳过并查集合并edge2**，那么对于情况2、3会出现不同的结果。

// 情况3会发现合并到最后一路畅通，什么事情都不会发生，**因此跳过这条edge2就是答案**。
// 情况2中，**如果跳过的这条edge2是在环里的那条边，则也会一路畅通，那答案就是 edge2**, 如果跳过的这条edge2是不在环里的那条边，**那么接下来并查集合并的时候一定会碰到环！那么答案就是 edge1。
// **如果合并的过程中压根没碰到过一条边会导致双入度点，那么就是情况1，这种情况下，**合并过程中会碰到一条边导致环的出现，（一个环，在最后一条边出现之前都不是个环）因此的这条边就是情况1的答案。**
// 这里是我的答案，并查集路径压缩了，不过没有按秩合并，时间是100%。

// class Solution {
//     int[] anc;//并查集
//     int[] parent;// record the father of every node to find the one with 2 fathers,记录每个点的父亲，为了找到双入度点
//     public int[] findRedundantDirectedConnection(int[][] edges) {
//         anc=new int[edges.length+1];
//         parent=new int[edges.length+1];
//         int[] edge1=null;
//         int[] edge2=null;
//         int[] lastEdgeCauseCircle=null;
//         for (int[] pair:edges){
//             int u=pair[0];
//             int v=pair[1];

//             if(anc[u]==0) anc[u]=u;
//             if(anc[v]==0) anc[v]=v;//init the union-find set  初始化并查集

//             if (parent[v]!=0){// node v already has a father, so we just skip the union of this edge and check if there will be a circle ，跳过 edge2,并记下 edge1,edge2
//                 edge1=new int[]{parent[v],v};
//                 edge2=pair;
//             } else {
//                 parent[v]=u;
//                 int ancU=find(u);
//                 int ancV=find(v);
//                 if(ancU!=ancV){
//                     anc[ancV]=ancU;
//                 } else { //meet a circle , 碰到了环
//                     lastEdgeCauseCircle=pair;
//                 }
//             }
//         }
//         if (edge1!=null&&edge2!=null) return lastEdgeCauseCircle==null?edge2:edge1; //如果是情况2、3，则根据有没有碰到环返回 edge1 或 edge2
//         else return lastEdgeCauseCircle; //否则就是情况1，返回那个导致环的最后出现的边。
//     }

//     private int find(int node){
//         if (anc[node]==node) return node;
//         anc[node]=find(anc[node]);
//         return anc[node];
//     }
// }