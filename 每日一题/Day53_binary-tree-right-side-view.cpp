/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day53_binary-tree-right-side-view.cpp
 * @Created Time:2020-04-22 00:14:30
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        int v;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                TreeNode* t = q.front();
                q.pop();
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
                v = t->val;
            }
            res.push_back(v);
        }
        return res;
    }
};