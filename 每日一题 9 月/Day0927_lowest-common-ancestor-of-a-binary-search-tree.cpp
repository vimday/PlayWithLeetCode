/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0927_lowest-common-ancestor-of-a-binary-search-tree.cpp
 * @Created Time:2020-09-27 12:34:34
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
    TreeNode* res;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lca(root, p, q);
        return res;
    }
    void lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if ((root->val - p->val) * (root->val - q->val) <= 0)
            res = root;
        else if ((root->val - p->val) > 0)
            lca(root->left, p, q);
        else
            lca(root->right, p, q);
    }
};