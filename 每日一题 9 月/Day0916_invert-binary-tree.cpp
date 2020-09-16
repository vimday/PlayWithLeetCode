/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0916_invert-binary-tree.cpp
 * @Created Time:2020-09-16 10:46:28
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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        TreeNode* t = root->right;
        root->right = invertTree(root->left);
        root->left = invertTree(t);
        return root;
    }
};
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            TreeNode* t = q.front();
            q.pop();
            TreeNode* r = t->right;
            t->right = t->left;
            t->left = r;
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
        }
        return root;
    }
};