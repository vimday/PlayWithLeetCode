/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0906_binary-tree-level-order-traversal-ii.cpp
 * @Created Time:2020-09-06 00:17:57
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            int nums = q.size();
            ans.push_back(vector<int>());

            for (int i = 0; i < nums; i++) {
                auto node = q.front();
                q.pop();
                ans.back().push_back(node->val);

                if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};