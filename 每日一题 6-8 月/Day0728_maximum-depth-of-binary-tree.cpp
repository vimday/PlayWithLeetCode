/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0728_maximum-depth-of-binary-tree.cpp
 * @Created Time:2020-07-28 12:43:54
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
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        int ans = 0;
        if (root == NULL) return 0;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                TreeNode* tmp = q.front();
                q.pop();
                if (tmp->left != NULL)
                    q.push(tmp->left);
                if (tmp->right != NULL)
                    q.push(tmp->right);
            }
            ++ans;
        }
        return ans;
    }
};