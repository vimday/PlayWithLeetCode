#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    unordered_map<TreeNode*,int> m;
    int res=0;
    bool isb(TreeNode* root){
        if(!root) return true;
        if(root->left&&root->left->val>=root->val) return false;
        if(root->right&&root->right->val<=root->val) return false;
        return isb(root->left)&&isb(root->right);
    }
    int gets(TreeNode* root){
        if(!root)
            return 0;
        int rt=root->val+gets(root->left)+gets(root->right);
        if(rt>res)
            res=rt;
        return rt;
    }
    void dfs(TreeNode* root){
        if(!root) return;
        if(m.count(root)){
            if(m[root]>res)
                res=m[root];
            return;
        }
        if(!isb(root)){
            m[root]=-1;
            dfs(root->left);
            dfs(root->right);
        }else{
            m[root]=gets(root);
        }
    }
    int maxSumBST(TreeNode* root) {
        m[nullptr]=0;
        dfs(root);
        return res;
    }
};