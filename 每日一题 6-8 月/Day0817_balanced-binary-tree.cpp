/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0817_balanced-binary-tree.cpp
 * @Created Time:2020-08-17 00:13:06
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
    int dfs(TreeNode* root) {
        if (!root)
            return 0;
        int l = dfs(root->left), r = dfs(root->right);
        if (abs(l - r) > 1 || l == -1 || r == -1)
            return -1;
        return 1 + max(l, r);
    }
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
};