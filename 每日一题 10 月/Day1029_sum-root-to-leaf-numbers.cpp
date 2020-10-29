/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1029_sum-root-to-leaf-numbers.cpp
 * @Created Time:2020-10-29 19:10:30
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
    string s;
    int res = 0;
    int sumNumbers(TreeNode *root) {
        if (!root) return 0;
        s.push_back('0' + root->val);
        if (!root->left && !root->right)
            res += stoi(s);
        if (root->left)
            sumNumbers(root->left);
        if (root->right)
            sumNumbers(root->right);
        s.pop_back();
        return res;
    }
};
class Solution {
public:
    int helper(TreeNode *root, int sum) {
        if (!root)
            return 0;
        else if (!root->left && !root->right)
            return 10 * sum + root->val;
        return helper(root->left, 10 * sum + root->val) +
               helper(root->right, 10 * sum + root->val);
    }
    int sumNumbers(TreeNode *root) {
        return helper(root, 0);
    }
};