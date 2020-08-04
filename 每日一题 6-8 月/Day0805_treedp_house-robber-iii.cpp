/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0805_treedp_house-robber-iii.cpp
 * @Created Time:2020-08-05 00:06:45
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
    int rob(TreeNode* root) {
        auto pair = dfs(root);
        return max(pair.first, pair.second);
    }

private:
    pair<int, int> dfs(TreeNode* root) {
        if (!root)
            return {0, 0};
        auto pl = dfs(root->left), pr = dfs(root->right);
        int m1 = pl.second + pr.second + root->val;
        int m2 = max(pl.first, pl.second) + max(pr.first, pr.second);
        return {m1, m2};
    }
};