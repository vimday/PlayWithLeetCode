#include<bits/stdc++.h>
using namespace std;
//wlp巨佬的手速太快了 tql dfs
class Solution {
    int lc[10005],rc[10005],in[10005];
    bool b[10005];
    bool dfs(int x)
    {
        if(!~x)return 1;
        if(b[x])return 0;
        b[x]=1;
        return dfs(lc[x])&&dfs(rc[x]);
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int i,j;
        memset(in,0,sizeof(in));
        memset(b,0,sizeof(b));
        for(i=0;i<n;i++)
        {
            lc[i]=leftChild[i];
            rc[i]=rightChild[i];
            if(~lc[i])in[lc[i]]++;
            if(~rc[i])in[rc[i]]++;
        }
        for(i=0,j=-1;i<n;i++)if(!in[i])if(~j)return 0;
        else j=i;
        if(!~j)return 0;
        return dfs(j);
    }
};
//并查集解法
// (并查集) O(n)

// （1）初始化n个连通集，让每个结点的祖宗结点是它本身
// （2）设要加的边是a->b，我们判断下，如果 aa 和 bb 的祖宗相等，说明你加上这条边会形成环，返回false，如果不相等，继续往下判断
// （3）因为这里是单向边，如果像示例2的结点3一样有两个结点指向它，也是不成立的，所以我们在（2）的基础上还有判断箭头指向的结点bb原来是否有其他结点指向它，如果有则返回false，否则将bb加到aa所在的连通集中，即p[pb] = pa;
// （4）最后判断连通块的个数是否为11即可
// 时间复杂度是O(n)：并查集的查找和合并操作的复杂度是近乎O(1)的，空间复杂度是O(n)O(n)

class Solution {
public:
    static const int N = 1e4 + 7;
    int p[N];
    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        for (int i = 0; i < n; i ++) p[i] = i;
        
        for (int i = 0; i < n; i ++) {
            // i->leftChild[i]
            int Left = leftChild[i];
            if (Left != -1) {
                int pa = find(i), pb = find(Left);
                if (pa == pb) return false; // 两个结点祖先相同
                else {
                    if (pb == Left) 
                        p[pb] = pa;
                    else // 箭头指向的结点已经有别的结点指向了，如示例2：结点3
                        return false;
                }
            }

            int Right = rightChild[i];
            if (Right != -1) {
                int pa = find(i), pb = find(Right);
                if (pa == pb) return false;
                else {
                    if (pb == Right) 
                        p[pb] = pa;
                    else
                        return false;
                }
            }
        }
        
        // 统计连通块个数
        int ans = 0;
        for (int i = 0; i < n; i ++) {
            if (p[i] == i) ans ++;
        }

        return ans == 1;
    }
};
//bfs
// //思路：
// 满足无环连通图，即为树。
// 若要满足无环图，遍历过程中不能出现重复结点。
// 若要满足连通图，遍历完成后经过的顶点数需为n个
// 至于为什么是二叉树不是三叉树四叉树，因为两个子节点数组可以看作一个邻接表，
// 每个结点的邻居数可能为2、1、0，所以，如果它是树，一定是二叉树。
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        queue<int> q;
        set<int> visd;
        int cnt=0,t;
        q.push(0);
        while(!q.empty()){
            t=q.front();q.pop();
            if(visd.find(t)!=visd.end())
                return false;
            visd.insert(t);
            cnt++;
            if(leftChild[t]!=-1) q.push(leftChild[t]);
            if(rightChild[t]!=-1) q.push(rightChild[t]);
        }
        return cnt==n;
    }
};
//我的lj代码
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& ld, vector<int>& rd) {
        unordered_map<int,int> ml,mr;
        for(int &i:ld)
            if(i!=-1)
                ml[i]++;
        for(int&i:rd)
            if(i!=-1)
                mr[i]++;
        if(ml.size()+mr.size()!=n-1)
            return false;
        int res=0;

        for(auto&p:ml){
            if(p.second>1||mr.count(p.first))
                    return false;
        }
        for(int i=0;i<n;i++)
            if(ml.count(i)==0&&mr.count(i)==0)
                res++;
        return res==1;
    }
};
//qc
class Solution {
public:
    set<int>vis;
    bool ans;
    void dfs(int cur,vector<int>& l, vector<int>& r){
        vis.insert(cur);
        if(l[cur] != -1){
            if(vis.count(l[cur])){
                ans = 0;
            }else{
                dfs(l[cur],l,r);
            }
        }
        if(r[cur] != -1){
            if(vis.count(r[cur])){
                ans = 0;
            }else{
                dfs(r[cur],l,r);
            }
        }
    }
    bool validateBinaryTreeNodes(int n, vector<int>& l, vector<int>& r) {
        vis.clear();
        ans = 1;
        set<int>as;
        for(int i = 0;i<n;i++){
            as.insert(l[i]);
            as.insert(r[i]);
        }
        for(int i = 0;i<n;i++){
            if(as.count(i)==0){
                dfs(i,l,r);
                break;
            }
        }
        if(vis.size() != n)return 0;
        if(!ans)return 0;
        return 1;
    }
};