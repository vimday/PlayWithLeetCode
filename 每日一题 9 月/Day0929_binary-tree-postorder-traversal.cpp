/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0929_binary-tree-postorder-traversal.cpp
 * @Created Time:2020-09-29 14:16:38
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if (!root) return res;
        stack<pair<TreeNode *, bool>> sk;
        sk.push(make_pair(root, false));
        while (sk.size()) {
            auto p = sk.top();
            sk.pop();
            TreeNode *cur = p.first;
            bool f = p.second;
            if (!cur)
                continue;
            if (f)
                res.push_back(cur->val);
            else {
                sk.push(make_pair(cur, true));
                //if(cur->right)
                sk.push(make_pair(cur->right, false));
                //if(cur->left)
                sk.push(make_pair(cur->left, false));
            }
        }
        return res;
        //l r m
        //trick  m r l,reverse

        //         TreeNode* cur=root,*pre=root;vector<int> res;stack<TreeNode*> s;

        //         while(s.size()||cur){
        //             while(cur){
        //                 s.push(cur);
        //                 cur=cur->left;
        //             }
        //             cur=s.top();
        //             if(!cur->right||pre==cur->right){
        //                 s.pop();
        //                 res.push_back(cur->val);
        //                 pre=cur;
        //                 cur=nullptr;
        //             }else
        //                 cur=cur->right;
        //         }
        //         return res;
    }
};

class Solution {
public:
    void addPath(vector<int> &vec, TreeNode *node) {
        vector<int> tmp;
        while (node != nullptr) {
            tmp.emplace_back(node->val);
            node = node->right;
        }
        reverse(tmp.begin(), tmp.end());
        for (auto &it : tmp) {
            vec.emplace_back(it);
        }
    }

    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        TreeNode *p1 = root, *p2 = nullptr;

        while (p1 != nullptr) {
            p2 = p1->left;
            if (p2 != nullptr) {
                while (p2->right != nullptr && p2->right != p1) {
                    p2 = p2->right;
                }
                if (p2->right == nullptr) {
                    p2->right = p1;
                    p1 = p1->left;
                    continue;
                } else {
                    p2->right = nullptr;
                    addPath(res, p1->left);
                }
            }
            p1 = p1->right;
        }
        addPath(res, root);
        return res;
    }
};