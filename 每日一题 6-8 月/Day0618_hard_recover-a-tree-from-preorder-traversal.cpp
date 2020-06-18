/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0618_hard_recover-a-tree-from-preorder-traversal.cpp
 * @Created Time:2020-06-18 20:03:01
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
    TreeNode* recoverFromPreorder(string s) {
        int n = s.size();
        vector<TreeNode*> sk;
        for (int i = 0, val, dep; i < n;) {
            val = 0;
            dep = 0;
            while (i < n && s[i] == '-') {
                i++;
                dep++;
            }
            while (i < n && s[i] != '-') {
                val = 10 * val + s[i] - '0';
                i++;
            }
            TreeNode* cur = new TreeNode(val);
            while (sk.size() > dep) sk.pop_back();
            if (sk.size()) {
                if (sk.back()->left == nullptr)
                    sk.back()->left = cur;
                else
                    sk.back()->right = cur;
            }
            sk.push_back(cur);
        }
        return sk[0];
    }
};

// Author: Huahua, running time: 24 ms
class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        vector<TreeNode*> stack;
        for (int i = 0, level, val; i < S.length();) {
            for (level = 0; S[i] == '-'; i++)
                level++;
            for (val = 0; i < S.length() && S[i] != '-'; i++)
                val = val * 10 + S[i] - '0';
            TreeNode* node = new TreeNode(val);
            while (stack.size() > level) stack.pop_back();
            if (!stack.empty())
                if (!stack.back()->left)
                    stack.back()->left = node;
                else
                    stack.back()->right = node;
            stack.push_back(node);
        }
        return stack[0];
    }
};
// Author: Huahua, running time: 24 ms
class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        int i = 0;
        return recover(S, i, 0);
    }

private:
    TreeNode* recover(const string& s, int& i, int depth) {
        const int d = getD(s, i);
        if (d != depth) {
            i -= d;
            return nullptr;
        }
        auto root = new TreeNode(getVal(s, i));
        root->left = recover(s, i, d + 1);
        root->right = recover(s, i, d + 1);
        return root;
    }

    int getD(const string& s, int& i) {
        int d = 0;
        while (i < s.length() && s[i] == '-') {
            ++d;
            ++i;
        }
        return d;
    }

    int getVal(const string& s, int& i) {
        int val = 0;
        while (i < s.length() && isdigit(s[i]))
            val = val * 10 + (s[i++] - '0');
        return val;
    }
};