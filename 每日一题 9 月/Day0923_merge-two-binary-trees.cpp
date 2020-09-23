/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0923_merge-two-binary-trees.cpp
 * @Created Time:2020-09-23 22:53:25
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1) return t2;
        if (!t2) return t1;
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
};
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1) return t2;
        if (!t2) return t1;
        stack<TreeNode*> s1, s2;
        s1.push(t1);
        s2.push(t2);
        while (!s1.empty()) {
            TreeNode* ts1 = s1.top();
            s1.pop();
            TreeNode* ts2 = s2.top();
            s2.pop();
            if (!ts1 || !ts2)
                continue;
            ts1->val += ts2->val;
            if (!ts1->left) {
                ts1->left = ts2->left;
                s1.push(ts2->left);
                s2.push(nullptr);
            } else {
                s1.push(ts1->left);
                s2.push(ts2->left);
            }
            if (!ts1->right) {
                ts1->right = ts2->right;
                s1.push(ts2->right);
                s2.push(nullptr);
            } else {
                s1.push(ts1->right);
                s2.push(ts2->right);
            }
        }
        return t1;
    }
};