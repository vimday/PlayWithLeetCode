/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0921_minimum-depth-of-binary-tree.cpp
 * @Created Time:2020-08-21 00:19:34
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
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == nullptr) return 0;
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        if (l == 0 || r == 0) return l + r + 1;
        return min(l, r) + 1;
    }
};