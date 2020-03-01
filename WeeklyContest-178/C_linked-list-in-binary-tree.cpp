#include<bits/stdc++.h>
using namespace std;

// * Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
//  Definition for a binary tree node.
 struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
//由于节点值介于1-100之间 可以使用hash 前缀和思路
class Solution {
public:
    const int P = 131;
    unsigned long long pre = 0;
    unsigned long long p = 1;
    int size = 0;
    unordered_map<int, unsigned long long> s;
    bool fun(TreeNode* root, unsigned long long cur, int level) {
        if(root == NULL) return false;
        cur = cur*P + root->val;
        if(level >= size) if(cur - s[level-size]*p == pre) return true;
        s[level] = cur;
        return fun(root->left, cur, level+1) || fun(root->right, cur, level+1);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        while(head != NULL) {
            ++size;
            p = p*P;
            pre = pre*P+head->val;
            head = head->next;
        }
        s[0] = 0;
        return fun(root, 0, 1);
    }
};


//自上而下
 class Solution {
	ListNode* Head;
	
	bool dfsT(TreeNode* Node) {
		if (!Node) return false;
		if (Node->val == Head->val) {
			if(dfs(Head, Node)) return true;
		}
		if (dfsT(Node->left)) return true;
		if (dfsT(Node->right)) return true;
        return false;
	}

	bool dfs(ListNode* cur, TreeNode*Node) {
		if (cur->next == NULL) return true;
		if (Node->left && cur->next->val == Node->left->val) if(dfs(cur->next, Node->left)) return true;
		if (Node->right && cur->next->val == Node->right->val) if(dfs(cur->next, Node->right)) return true;
        return false;
	}

public:
	bool isSubPath(ListNode* head, TreeNode* root) {
		Head = head;
		return dfsT(root);
	}
};
 //自下而上dfs
class Solution {
public:
    bool res=false;
   // unordered_map<TreeNode*root,vector<int>> m;
    unordered_map<TreeNode*,TreeNode*> mf;
   
    void help(TreeNode* root,int n,vector<int>&v,int idx){
        if(!root||res)
            return;
        TreeNode* cur=root;
        int i=0;
        if(idx>=n){
        while(i<n&&cur&&cur->val==v[i++]){cur=mf[cur];}
        if(i==n){
            res=true;
            return;
        }}
        help(root->left,n,v,idx+1);
        help(root->right,n,v,idx+1);
            
    }
    void findf(TreeNode* root,TreeNode* f){
        if(!root)
            return;
        mf[root]=f;
        findf(root->left,root);
        findf(root->right,root);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        vector<int> lt;
        while(head!=nullptr){
            lt.push_back(head->val);
            head=head->next;
        }
        findf(root,nullptr);
        int n=lt.size();
        reverse(lt.begin(),lt.end());
        help(root,n,lt,1);
        return res;
    }
};
//java
// public boolean isSubPath(ListNode head, TreeNode root) {
//     if (head == null) {
//         return true;
//     }
//     if (root == null) {
//         return false;
//     }
//     //先判断当前的节点，如果不对，再看左子树和右子树呗
//     return isSub(head, root) || isSubPath(head, root.left) || isSubPath(head, root.right);
// }

// private boolean isSub(ListNode head, TreeNode node) {
//     //特判：链表走完了，返回true
//     if (head == null) {
//         return true;
//     }
//     //特判：链表没走完，树走完了，这肯定不行，返回false
//     if (node == null) {
//         return false;
//     }
//     //如果值不同，必定不是啊
//     if (head.val != node.val) {
//         return false;
//     }
//     //如果值相同，继续看，左边和右边有一个满足即可
//     return isSub(head.next, node.left) || isSub(head.next, node.right);
// }
