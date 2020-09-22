/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0922_TODO_HARD_binary-tree-cameras.cpp
 * @Created Time:2020-09-22 17:09:00
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
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int res = 0;
    int minCameraCover(TreeNode* root) {
        res += dfs(root) == 0;
        return res;
    }
    int dfs(TreeNode* root) {
        if (!root)
            return 1;
        int l = dfs(root->left), r = dfs(root->right);
        if (l == 0 || r == 0) {
            ++res;
            return 2;
        }
        if (l == 2 || r == 2) {
            return 1;
        }
        return 0;
    }
};

class Solution {
public:
    int ans = 0;
    stack<TreeNode*> s1, s2;
    int minCameraCover(TreeNode* root) {
        if (!root) return 0;
        dfs(root);
        if (root->val == 0) ++ans;
        return ans;
    }
    //单栈双指针版
    void dfs(TreeNode* root) {
        TreeNode* last = root;
        s1.push(root);
        while (!s1.empty()) {
            TreeNode* t = s1.top();
            if ((!t->left && !t->right) || (!t->right && t->left == last) || (t->right == last)) {
                if ((t->left && t->left->val == 0) || (t->right && t->right->val == 0)) {
                    ++ans;
                    t->val = 2;
                } else if ((t->left && t->left->val == 2) || (t->right && t->right->val == 2)) {
                    t->val = 1;
                }
                last = t;
                s1.pop();
            } else {
                if (t->right)
                    s1.push(t->right);
                if (t->left)
                    s1.push(t->left);
            }
        }
    }
    // 双栈版后序dfs
    //     void dfs(TreeNode * root){
    //
    //         s1.push(root);
    //         while(!s1.empty()){
    //             TreeNode* t=s1.top();s1.pop();s2.push(t);
    //             if(t->left) s1.push(t->left);
    //             if(t->right) s1.push(t->right);
    //         }
    //         while(!s2.empty()){
    //             TreeNode* t=s2.top();s2.pop();
    //             //if(!t->left&&!t->right) t->val=1;
    //             if((t->left&&t->left->val==0)||(t->right&&t->right->val==0))
    //                 {t->val=2;++ans;}
    //             else if((t->left&&t->left->val==2)||(t->right&&t->right->val==2))
    //                 t->val=1;

    //         }

    //     }
};

//树形DP

class Solution {
public:
    unordered_map<TreeNode*, int> hash1, hash2, hash3;  //自己、父节点、子节点

    int minCameraCover(TreeNode* root) {
        if (!root) return 0;
        dfs(root, root);
        return min(hash1[root], hash3[root]);
    }

    void dfs(TreeNode* u, TreeNode* root) {
        if (!u) return;
        hash1[u] = 1;
        dfs(u->left, root);
        dfs(u->right, root);

        if (u == root)
            hash2[u] = 0x3f3f3f3f;
        else {
            if (u->left) hash2[u] += min(hash1[u->left], hash3[u->left]);
            if (u->right) hash2[u] += min(hash1[u->right], hash3[u->right]);
        }

        if (u->left) hash1[u] += min(hash1[u->left], min(hash2[u->left], hash3[u->left]));
        if (u->right) hash1[u] += min(hash1[u->right], min(hash2[u->right], hash3[u->right]));

        int cnt = 0x3f3f3f3f;
        if (!u->left && u->right) cnt = min(cnt, hash1[u->right]);
        if (!u->right && u->left) cnt = min(cnt, hash1[u->left]);
        if (!u->left && !u->right) hash3[u] = cnt;
        if (u->left && u->right) cnt = min(cnt, min(hash1[u->left] + hash1[u->right], min(hash1[u->left] + hash3[u->right], hash3[u->left] + hash1[u->right])));
        hash3[u] = cnt;
    }
};