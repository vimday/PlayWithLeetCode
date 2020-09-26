/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0926_path-sum-ii.cpp
 * @Created Time:2020-09-26 13:05:26
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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root) return res;
        vector<int> t;
        dfs(root, t, sum);
        return res;
    }
    void dfs(TreeNode* root, vector<int>& t, int s) {
        t.push_back(root->val);
        if (root->val == s && !root->left && !root->right) {
            res.push_back(t);
            t.pop_back();
            return;
        }
        if (root->left)
            dfs(root->left, t, s - root->val);
        if (root->right)
            dfs(root->right, t, s - root->val);
        t.pop_back();
    }
};