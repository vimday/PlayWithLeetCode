/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0921_convert-bst-to-greater-tree.cpp
 * @Created Time:2020-09-21 15:03:12
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
    TreeNode* convertBST(TreeNode* root) {
        int t = 0;
        dfs(t, root);
        return root;
    }
    void dfs(int& t, TreeNode* root) {
        if (!root)
            return;
        dfs(t, root->right);
        int tmp = root->val;
        root->val += t;
        t += tmp;
        dfs(t, root->left);
    }
};
class Solution {
public:
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        if (!root)
            return NULL;
        else {
            convertBST(root->right);
            sum += root->val;
            root->val = sum;
            convertBST(root->left);
            return root;
        }
    }
};