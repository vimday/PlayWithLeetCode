/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0607_longest-consective-sequence-in-binary-tree.cpp
 * @Created Time:2020-06-06 00:14:34
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
    int res = 0;
    int longestConsecutive(TreeNode *root) {
        //求树中的最长连续序列长度，递归遍历即可
        if (!root) return 0;
        dfs(root, root->val, 0);
        return res;
    }
    void dfs(TreeNode *root, int pre, int cnt) {
        if (!root) return;
        if (root->val == pre + 1) {
            cnt++;
            res = max(res, cnt);
            dfs(root->left, pre + 1, cnt);
            dfs(root->right, pre + 1, cnt);
        } else {
            cnt = 1;
            pre = root->val;
            dfs(root->left, pre, cnt);
            dfs(root->right, pre, cnt);
        }
    }
};