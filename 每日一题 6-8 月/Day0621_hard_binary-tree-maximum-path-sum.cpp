/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0621_hard_binary-tree-maximum-path-sum.cpp
 * @Created Time:2020-06-21 00:43:30
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
    int res = INT_MIN;
    int maxPathSum(TreeNode* root) {
        maxgain(root);
        return res;
    }
    int maxgain(TreeNode* root) {
        if (!root) return 0;
        int l = max(maxgain(root->left), 0);
        int r = max(maxgain(root->right), 0);
        int newpath = l + r + root->val;
        res = max(res, newpath);
        return root->val + max(l, r);
    }
};