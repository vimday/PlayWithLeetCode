#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// //java 6ms
// class Solution {
//     int max = 0;
//     public int longestZigZag(TreeNode root) {
//         dfs(root,true);
//         return max;
//     }
//     private int dfs(TreeNode root, boolean isLeft){
//         if(root==null)  return 0;
//         int r =  dfs(root.right,false);
//         int l = dfs(root.left,true);
//         int big = l>r? l:r;
//         if(big>max) max = big;
//         if(isLeft){
//             return r+1;
//         } else {
//             return l+1;
//         }
//     }
// }

//123ms
// class Solution {
    
//     HashMap<TreeNode,Integer> table1 = new HashMap<>();
//     HashMap<TreeNode,Integer> table2 = new HashMap<>();
//     public int longestZigZag(TreeNode root) {
//         if(root==null) return 0;
//         TreeNode left = root.left;
//         TreeNode right = root.right;
//         int cur = Math.max(turnRight(root),turnLeft(root));
//         int son = Math.max(longestZigZag(left),longestZigZag(right));
//         return Math.max(cur,son);
//     }
//     public int turnLeft(TreeNode root){
//         if(root==null) return -1;
//         if(table1.containsKey(root)) return table1.get(root);
//         int res = 1+turnRight(root.left);
//         table1.put(root,res);
//         return res;
//     }
//     public int turnRight(TreeNode root){
//         if(root==null) return -1;
//         if(table2.containsKey(root)) return table2.get(root);
//         int res = 1+turnLeft(root.right);
//         table2.put(root,res);
//         return res;
//     }
// }


//by vimday
class Solution
{
public:
    unordered_map<TreeNode *, pair<int, int>> m;
    int res = -1;
    int dfs(TreeNode *root)
    {
        if (!root)
            return -1;
        if (!root->left && !root->right)
        {
            m[root] = {0, 0};
            return 0;
        }
        if (m.count(root))
        {

            int t = max(m[root].first, m[root].second);
            if (t > res)
                res = t;
            return res;
        }

        if (m.count(root->left))
            m[root].second = m[root->left].first + 1;
        if (m.count(root->right))
            m[root].first = m[root->right].second + 1;
        if (m.count(root))
        {

            int t = max(m[root].first, m[root].second);
            if (t > res)
                res = t;
            return res;
        }
        dfs(root->left);
        dfs(root->right);
        if (m.count(root->left))
            m[root].second = m[root->left].first + 1;
        if (m.count(root->right))
            m[root].first = m[root->right].second + 1;
        if (m.count(root))
        {

            int t = max(m[root].first, m[root].second);
            if (t > res)
                res = t;
            return res;
        }
        return res;
    }
    int longestZigZag(TreeNode *root)
    {
        return dfs(root);
    }
};
//by wlp

class Solution
{
    int n, s[50005][2], ans;
    int work(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int x = ++n;
        ans = max(ans, max(s[x][0] = s[work(root->left)][1] + 1, s[x][1] = s[work(root->right)][0] + 1));
        return x;
    }

public:
    int longestZigZag(TreeNode *root)
    {
        s[0][0] = s[0][1] = -1;
        ans = n = 0;
        work(root);
        return ans;
    }
};
//by liouzhou
class Solution
{
public:
    unordered_map<TreeNode *, int> f, g;
    int ans;

    void dfs(TreeNode *x)
    {
        if (!x)
            return;
        if (x->left)
        {
            dfs(x->left);
            f[x] = g[x->left] + 1;
        }
        else
            f[x] = 0;
        if (x->right)
        {
            dfs(x->right);
            g[x] = f[x->right] + 1;
        }
        else
            g[x] = 0;
        ans = max(ans, max(f[x], g[x]));
    }

    int longestZigZag(TreeNode *root)
    {
        f.clear();
        g.clear();
        ans = 0;
        dfs(root);
        return ans;
    }
};
//pycode
// class Solution:
//     def longestZigZag(self, root: TreeNode) -> int:
//         ans = 0
//         if root == None:
//             return 0

//         def dfs(cur):
//             nonlocal ans
//             cur.lll = 0
//             cur.rrr = 0
//             if cur.left != None:
//                 dfs(cur.left)
//                 cur.lll = max(cur.lll, cur.left.rrr + 1)
//             if cur.right != None:
//                 dfs(cur.right)
//                 cur.rrr = max(cur.rrr, cur.right.lll + 1)
//             ans = max(ans, cur.lll)
//             ans = max(ans, cur.rrr)

//         dfs(root)
//         return ans