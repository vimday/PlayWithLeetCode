/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0818_convert-sorted-list-to-binary-search-tree.cpp
 * @Created Time:2020-08-18 00:29:45
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
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return new TreeNode(head->val);
        ListNode *pre = head, *cur = head->next, *nxt = head->next->next;
        while (nxt && nxt->next) {
            pre = pre->next;
            cur = pre->next;
            nxt = nxt->next->next;
        }
        TreeNode* res = new TreeNode(cur->val);
        pre->next = nullptr;
        res->left = sortedListToBST(head);
        res->right = sortedListToBST(cur->next);
        return res;
    }
};