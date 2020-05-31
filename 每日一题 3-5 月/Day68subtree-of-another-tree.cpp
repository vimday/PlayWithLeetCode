/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day68.cpp
 * @Created Time:2020-05-07 00:13:30
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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        //递归判断
        if (!s && !t) return true;
        if (!s || !t) return false;
        return issame(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    bool issame(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s || !t) return false;
        if (s->val != t->val) return false;
        return issame(s->left, t->left) && issame(s->right, t->right);
    }
};