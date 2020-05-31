/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day66validate-binary-search-tree.cpp
 * @Created Time:2020-05-05 22:46:11
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
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    long long pre = LONG_MIN;
    bool isValidBST(TreeNode *root) {
        if (!root)
            return true;
        else {
            if (!isValidBST(root->left) || pre >= root->val)
                return false;
            pre = root->val;
            return isValidBST(root->right);
        }
    }
};