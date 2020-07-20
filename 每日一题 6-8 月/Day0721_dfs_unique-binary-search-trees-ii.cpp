/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0721_dfs_unique-binary-search-trees-ii.cpp
 * @Created Time:2020-07-21 00:29:32
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
    vector<TreeNode*> generateTrees(int n) {
        if (n < 1) return vector<TreeNode*>();
        return gst(1, n);
    }
    vector<TreeNode*> gst(int l, int n) {
        if (l > n) return {nullptr};
        vector<TreeNode*> res;
        for (int i = l; i <= n; ++i) {
            vector<TreeNode*> left = gst(l, i - 1);
            vector<TreeNode*> right = gst(i + 1, n);
            for (TreeNode* l : left)
                for (TreeNode* r : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
        }
        return res;
    }
};