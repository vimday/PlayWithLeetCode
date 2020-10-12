/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1012_minimum-absolute-difference-in-bst.cpp
 * @Created Time:2020-10-12 21:06:35
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
    int res = INT_MAX;
    TreeNode* pre = nullptr;
    int getMinimumDifference(TreeNode* root) {
        if (!root)
            return 0;
        getMinimumDifference(root->left);
        if (pre)
            res = min(res, root->val - pre->val);
        pre = root;
        getMinimumDifference(root->right);
        return res;
    }
};
class Solution {
public:
    int res = INT_MAX;
    TreeNode* pre;
    int getMinimumDifference(TreeNode* root) {
        dfs(root);

        return res;
    }
    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        if (pre)
            res = min(res, root->val - pre->val);
        pre = root;
        dfs(root->right);
    }
};