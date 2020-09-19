/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0919_sum-of-left-leaves.cpp
 * @Created Time:2020-09-19 13:08:51
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
    int sumOfLeftLeaves(TreeNode *root) {
        if (!root) return 0;
        int res = 0;
        if (root->left && !root->left->left && !root->left->right) res += root->left->val;
        return res + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};