/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0707_dfsbfs_path-sum.cpp
 * @Created Time:2020-07-07 00:05:26
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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        sum -= root->val;
        if (root->left == NULL && root->right == NULL)
            return sum == 0;

        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        stack<TreeNode*> s;
        stack<int> ts;
        s.push(root);
        ts.push(sum - root->val);
        while (!s.empty()) {
            TreeNode* tmp = s.top();
            s.pop();
            int i = ts.top();
            ts.pop();
            if (tmp->left == nullptr && tmp->right == nullptr && i == 0)
                return true;
            if (tmp->left != nullptr) {
                s.push(tmp->left);
                ts.push(i - tmp->left->val);
            }
            if (tmp->right != nullptr) {
                s.push(tmp->right);
                ts.push(i - tmp->right->val);
            }
        }
        return false;
    }
};