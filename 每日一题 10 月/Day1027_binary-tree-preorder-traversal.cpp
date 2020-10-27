/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1027_binary-tree-preorder-traversal.cpp
 * @Created Time:2020-10-27 10:29:58
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
    vector<int> res;
    void pre(TreeNode* root) {
        if (!root) return;
        res.push_back(root->val);
        pre(root->left);
        pre(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        // pre(root);
        // return res;
        if (!root) return res;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* t = s.top();
            s.pop();
            res.push_back(t->val);
            if (t->right)
                s.push(t->right);
            if (t->left)
                s.push(t->left);
        }
        return res;
        //o(1)space
        //         vector<int> res;
        //         TreeNode * cur=root,*pre=nullptr;
        //         while(cur){
        //             if(!cur->left){
        //                 res.emplace_back(cur->val);
        //                 cur=cur->right;
        //             }
        //             else{
        //                 pre=cur->left;
        //                 while(pre->right&&pre->right!=cur)
        //                     pre=pre->right;
        //                 if(!pre->right){
        //                     res.emplace_back(cur->val);
        //                     pre->right=cur;
        //                     cur=cur->left;
        //                 }
        //                 else{
        //                     pre->right=nullptr;
        //                     cur=cur->right;
        //                 }

        //             }
        //         }
        //         return res;
    }
};