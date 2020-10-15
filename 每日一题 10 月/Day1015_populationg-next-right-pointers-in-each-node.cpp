/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1015_populationg-next-right-pointers-in-each-node.cpp
 * @Created Time:2020-10-15 17:59:54
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
        //迭代
        if (!root || !root->left) return root;
        Node* pre = root;
        Node* cur = NULL;
        while (pre->left) {
            cur = pre;
            while (cur) {
                cur->left->next = cur->right;
                if (cur->next)
                    cur->right->next = cur->next->left;
                cur = cur->next;
            }
            pre = pre->left;
        }
        //递归
        //
        // root->left->next=root->right;
        // if(root->next)
        //     root->right->next=root->next->left;
        // connect(root->left);
        // connect(root->right);

        //bfs
        // queue<Node*> q;
        // q.push(root);
        // while(!q.empty()){
        //     int n=q.size();Node *nt=nullptr;
        //     while(n--){
        //         Node* t=q.front();q.pop();
        //         t->next=nt;nt=t;
        //         if(t->right) {q.push(t->right);q.push(t->left);}
        //     }
        // }
        return root;
    }
};
