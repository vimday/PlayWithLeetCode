/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0912_average-of-levels-in-binary-tree.cpp
 * @Created Time:2020-09-12 22:47:08
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        double sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            int len = q.size();
            sum = 0.0;
            for (int i = 0; i < len; ++i) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
                sum += cur->val;
            }
            ans.push_back(sum /= len);
        }
        return ans;
    }
};