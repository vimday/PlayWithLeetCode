/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0703_binary_convert-sorted-array-to-binary-search-tree.cpp
 * @Created Time:2020-07-03 00:18:34
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return help(nums, 0, n);
    }
    TreeNode* help(vector<int>& v, int l, int r) {
        if (l == r) return nullptr;
        int mi = l + (r - l >> 1);
        TreeNode* root = new TreeNode(v[mi]);
        root->left = help(v, l, mi);
        root->right = help(v, mi + 1, r);
        return root;
    }
};