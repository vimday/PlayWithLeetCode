/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0925_construct-binary-tree-from-inorder-and-postor-traversal.cpp
 * @Created Time:2020-09-25 19:06:39
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
    TreeNode* buildTree(vector<int>& in, vector<int>& pt) {
        return dfs(0, in.size() - 1, 0, pt.size() - 1, in, pt);
    }
    TreeNode* dfs(int l1, int r1, int l2, int r2, vector<int>& in, vector<int>& pt) {
        if (l1 > r1 || l2 > r2) return nullptr;
        TreeNode* root = new TreeNode(pt[r2]);
        int mi = l1;
        for (int i = l1; i <= r1; ++i)
            if (in[i] == pt[r2]) {
                mi = i;
                break;
            }
        root->left = dfs(l1, mi - 1, l2, l2 + mi - 1 - l1, in, pt);
        root->right = dfs(mi + 1, r1, l2 + mi - l1, r2 - 1, in, pt);
        return root;
    }
};
class Solution {
private:
    unordered_map<int, int> inorder_index;

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for (int i = 0; i < n; ++i) {
            inorder_index[inorder[i]] = i;
        }
        return mytree(inorder, postorder, 0, n - 1, 0, n - 1);
    }

    TreeNode* mytree(const vector<int>& inorder, const vector<int>& postorder, int inorder_left, int inorder_right, int postorder_left, int postorder_right) {
        if (inorder_left > inorder_right) return nullptr;
        int inorder_rootnum = inorder_index[postorder[postorder_right]];
        int left_length = inorder_rootnum - inorder_left;  //
        int right_length = inorder.size() - left_length - 1;
        TreeNode* root = new TreeNode(postorder[postorder_right]);
        root->left = mytree(inorder, postorder, inorder_left, inorder_left + left_length - 1, postorder_left, postorder_left + left_length - 1);
        root->right = mytree(inorder, postorder, inorder_left + left_length + 1, inorder_right, postorder_left + left_length, postorder_right - 1);
        return root;
    }
};