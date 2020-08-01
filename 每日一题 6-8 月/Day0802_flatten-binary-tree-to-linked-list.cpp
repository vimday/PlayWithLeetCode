/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0802_flatten-binary-tree-to-linked-list.cpp
 * @Created Time:2020-08-02 00:36:18
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        flatten(root->left);
        TreeNode *t = root->left, *lr = root;
        while (t) {
            lr = t;
            t = t->right;
        }
        flatten(root->right);
        TreeNode* r = root->right;
        root->right = root->left;
        root->left = nullptr;
        lr->right = r;
    }
};
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root)
            return;
        flatten(root->left);
        flatten(root->right);
        TreeNode* t = root->right;
        root->right = root->left;
        root->left = nullptr;
        while (root->right) root = root->right;
        root->right = t;
    }
};