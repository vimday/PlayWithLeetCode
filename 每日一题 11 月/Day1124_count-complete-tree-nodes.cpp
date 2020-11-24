/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1124_count-complete-tree-nodes.cpp
 * @Created Time:2020-11-24 15:20:28
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
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int l = getd(root->left);
        int r = getd(root->right);
        if (l == r)
            return (1 << l) + countNodes(root->right);
        else
            return (1 << r) + countNodes(root->left);
    }
    int getd(TreeNode* root) {
        int d = 0;
        while (root) {
            d++;
            root = root->left;
        }
        return d;
    }
};