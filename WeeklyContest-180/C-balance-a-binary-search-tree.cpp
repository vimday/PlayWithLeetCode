/*
 * @Author      :vimday
 * @Desc        :lc 周赛5179 C
 * @Url         :https://leetcode-cn.com/problems/balance-a-binary-search-tree/
 * @File Name   :C-balance-a-binary-search-tree.cpp
 * @Created Time:2020-03-15 13:06:07
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
    vector<int> data;
    void build(TreeNode* root, vector<int>& v) {
        if (!root) return;
        if (root->left)
            build(root->left, data);
        data.push_back(root->val);
        if (root->right)
            build(root->right, data);
    }
    TreeNode* help(vector<int>& v, int l, int h) {
        if (l >= h)
            return nullptr;
        int mi = l + (h - l >> 1);
        TreeNode* root = new TreeNode(v[mi]);

        root->left = help(v, l, mi);
        root->right = help(v, mi + 1, h);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        build(root, data);
        return help(data, 0, data.size());
    }
};