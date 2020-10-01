/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0930_insert-into-a-binary-search-tree.cpp
 * @Created Time:2020-10-01 22:54:05
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        /*if(root->val>val && !root->left) {
            root->left=new TreeNode(val);
        }
        if(root->val<val && !root->right) {
            root->right=new TreeNode(val);
        }*/
        if (root->val > val) root->left = insertIntoBST(root->left, val);
        if (root->val < val) root->right = insertIntoBST(root->right, val);
        return root;
    }
};