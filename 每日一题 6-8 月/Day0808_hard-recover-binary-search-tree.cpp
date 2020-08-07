/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0808_hard-recover-binary-search-tree.cpp
 * @Created Time:2020-08-08 00:55:06
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
    TreeNode *t1, *t2, *pre;
    void recoverTree(TreeNode* root) {
        dfs(root);
        int t = t1->val;
        t1->val = t2->val;
        t2->val = t;
    }
    void dfs(TreeNode* root) {
        if (!root)
            return;
        dfs(root->left);
        if (pre && pre->val > root->val) {
            if (!t1)
                t1 = pre;
            t2 = root;
        }

        pre = root;

        dfs(root->right);
    }
};

class Solution {
public:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* pre = nullptr;
    void recoverTree(TreeNode* root) {
        mirrorInOrder(root);
        int val = first->val;
        first->val = second->val;
        second->val = val;
    }
    void find(TreeNode* node) {
        //打印 node;
        if (pre && pre->val > node->val) {
            second = node;
            if (first != nullptr) return;
            first = pre;
        }
        pre = node;
    }

    void mirrorInOrder(TreeNode* root) {
        TreeNode* node = root;
        while (node != nullptr) {
            if (node->left != nullptr) {
                // 找到前驱节点 P
                TreeNode* P = node->left;
                while (P->right != nullptr && P->right != node) {
                    P = P->right;
                }
                if (P->right == nullptr) {
                    P->right = node;
                    node = node->left;
                } else {
                    //打印 node;
                    find(node);
                    P->right = nullptr;
                    node = node->right;
                }
            } else {
                // 打印 node;
                find(node);
                node = node->right;
            }
        }
    }
};

// class Solution {
// public
//     void recoverTree(TreeNode root) {
//         TreeNode before = null;
//         TreeNode first = null;
//         TreeNode second = null;
//         while (root != null) {
//             //当左子树不为null，寻找左子树的最右节点，该节点为中序遍历中的前一个节点
//             if (root.left != null) {
//                 TreeNode pre = getPredecessor(root);
//                 //pre节点没被修改，则修改右节点为root，以便后续循环中能通过pre.right回到root节点
//                 if (pre.right == null) {
//                     pre.right = root;
//                     root = root.left;
//                     //继续遍历左子树
//                     continue;
//                 } else if (pre.right == root) {
//                     //将修改后的pre节点恢复原样
//                     pre.right = null;
//                 }
//             }
//             //当左子树为null，或者pre.right为root时，先判断before节点和root节点是否倒序，然后再遍历右子树
//             if (first == null && before != null && before.val > root.val)
//                 first = before;
//             if (first != null && before != null && before.val > root.val)
//                 second = root;
//             before = root;
//             root = root.right;
//         }
//         swap(first, second);
//     }
//     //寻找一个节点的左子树的最右节点
// private
//     TreeNode getPredecessor(TreeNode n) {
//         TreeNode pre = n;
//         if (n.left != null) {
//             pre = pre.left;
//             while (pre.right != null && pre.right != n) {
//                 pre = pre.right;
//             }
//         }
//         return pre;
//     }
//     //交换两个节点
// private
//     void swap(TreeNode first, TreeNode second) {
//         if (first != null && second != null) {
//             int temp = first.val;
//             first.val = second.val;
//             second.val = temp;
//         }
//     }
// }