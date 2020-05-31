/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day83construct-binary-tree-from-preorder-and-inorder-traversal.cpp
 * @Created Time:2020-05-22 00:19:38
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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& ind) {
        return help(pre, ind, 0, pre.size(), 0, pre.size());
    }
    TreeNode* help(vector<int>& pre, vector<int>& ind, int pl, int pr, int il, int ir) {
        if (pl >= pr || il >= ir)
            return nullptr;
        int t = pre[pl];
        TreeNode* root = new TreeNode(t);
        int idx = il;
        for (; idx < ir; idx++)
            if (ind[idx] == t)
                break;
        root->left = help(pre, ind, pl + 1, pl + idx - il + 1, il, idx);
        root->right = help(pre, ind, pl + idx - il + 1, pr, idx + 1, ir);
        return root;
    }
};