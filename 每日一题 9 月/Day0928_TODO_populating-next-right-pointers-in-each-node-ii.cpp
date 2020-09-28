/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0928_TODO_populating-next-right-pointers-in-each-node-ii.cpp
 * @Created Time:2020-09-28 11:59:09
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

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        Node* last = root;
        while (last != NULL) {
            // 获得队首元素
            while (last && last->left == NULL && last->right == NULL) last = last->next;
            if (last == NULL) break;
            Node* cur = NULL;
            // 遍历队列
            for (Node* i = last; i != NULL; i = i->next) {
                // 进行push和pop操作
                if (i->left) {
                    if (cur != NULL) {
                        cur->next = i->left;
                    }
                    cur = i->left;
                }
                if (i->right) {
                    if (cur != NULL) {
                        cur->next = i->right;
                    }
                    cur = i->right;
                }
            }
            // 更新队首
            last = last->left ? last->left : last->right;
        }
        return root;
    }
};
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        if (root->left && root->right)
            root->left->next = root->right;
        else if (root->left) {
            Node* nx = root->next;
            while (nx && !nx->left && !nx->right)
                nx = nx->next;
            if (nx && nx->left)
                root->left->next = nx->left;
            else if (nx && nx->right)
                root->left->next = nx->right;
        }
        if (root->right) {
            Node* nx = root->next;
            while (nx && !nx->left && !nx->right)
                nx = nx->next;
            if (nx && nx->left)
                root->right->next = nx->left;
            else if (nx && nx->right)
                root->right->next = nx->right;
        }
        connect(root->right);
        connect(root->left);
        return root;
    }
};
// class Solution {
//     public Node connect_1(Node root) {
//         if (root == null) {
//             return null;
//         }
//         // 借助队列实现层次遍历
//         LinkedList<Node> queue = new LinkedList<>();
//         queue.add(root);
//         while (!queue.isEmpty()) {
//             int size = queue.size();
//             while (size-- > 0) {
//                 Node node = queue.remove();
//                 if (size > 0) {
//                     node.next = queue.peek();
//                 }
//                 if (node.left != null) {
//                     queue.add(node.left);
//                 }
//                 if (node.right != null) {
//                     queue.add(node.right);
//                 }
//             }
//         }
//         return root;
//     }

//     public Node connect(Node root) {
//         if (root == null) {
//             return null;
//         }
//         if (root.left != null) {
//             if (root.right != null) {
//                 // 若右子树不为空，则左子树的 next 即为右子树
//                 root.left.next = root.right;
//             } else {
//                 // 若右子树为空，则右子树的 next 由根节点的 next 得出
//                 root.left.next = nextNode(root.next);
//             }
//         }
//         if (root.right != null) {
//             // 右子树的 next 由根节点的 next 得出
//             root.right.next = nextNode(root.next);
//         }
//         // 先确保 root.right 下的节点的已完全连接，因 root.left 下的节点的连接
//         // 需要 root.left.next 下的节点的信息，若 root.right 下的节点未完全连
//         // 接（即先对 root.left 递归），则 root.left.next 下的信息链不完整，将
//         // 返回错误的信息。可能出现的错误情况如下图所示。此时，底层最左边节点将无
//         // 法获得正确的 next 信息：
//         //                  o root
//         //                 / \
//         //     root.left  o —— o  root.right
//         //               /    / \
//         //              o —— o   o
//         //             /        / \
//         //            o        o   o
//         connect(root.right);
//         connect(root.left);
//         return root;
//     }

//     private Node nextNode(Node node) {
//         while (node != null) {
//             if (node.left != null) {
//                 return node.left;
//             }
//             if (node.right != null) {
//                 return node.right;
//             }
//             node = node.next;
//         }
//         return null;
//     }
// }