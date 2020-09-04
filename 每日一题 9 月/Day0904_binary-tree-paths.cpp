/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0904_binary-tree-paths.cpp
 * @Created Time:2020-09-04 16:00:00
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
    vector<string> res;
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        string s = "";
        dfs(s, root);
        return res;
    }
    void dfs(string s, TreeNode* root) {
        if (s.size() == 0)
            s += to_string(root->val);
        else
            s += "->" + to_string(root->val);
        if (!root->left && !root->right) {
            res.emplace_back(s);
            return;
        }
        if (root->left) dfs(s, root->left);
        if (root->right) dfs(s, root->right);
    }
};