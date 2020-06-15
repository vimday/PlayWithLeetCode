/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0616_hard-serialize-and-deserialize-binary-tree.cpp
 * @Created Time:2020-06-16 00:17:06
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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL)
            return "#_";
        string res = to_string(root->val) + "_";
        res += serialize(root->left);
        res += serialize(root->right);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        std::stringstream ss(data);
        std::string item;
        queue<string> q;
        while (std::getline(ss, item, '_'))
            q.push(item);
        return helper(q);
    }
    TreeNode* helper(queue<string>& q) {
        string val = q.front();
        q.pop();
        if (val == "#")
            return NULL;
        TreeNode* head = new TreeNode(stoi(val));
        head->left = helper(q);
        head->right = helper(q);
        return head;
    }
};
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        stringstream ss;
        queue<TreeNode*> Q;
        Q.push(root);
        while (Q.size()) {
            TreeNode* p = Q.front();
            Q.pop();
            if (!p)
                ss << "# ";
            else {
                ss << p->val << " ";
                Q.push(p->left);
                Q.push(p->right);
            }
        }
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        stringstream ss(data);
        string t;
        ss >> t;
        TreeNode* rt = new TreeNode(stoi(t));
        queue<TreeNode*> Q;
        Q.push(rt);
        while (Q.size()) {
            TreeNode* p = Q.front();
            Q.pop();
            ss >> t;
            if (t[0] == '#') {
                p->left = NULL;
            } else {
                p->left = new TreeNode(stoi(t));
                Q.push(p->left);
            }
            ss >> t;
            if (t[0] == '#') {
                p->right = NULL;
            } else {
                p->right = new TreeNode(stoi(t));
                Q.push(p->right);
            }
        }
        return rt;
    }
};
