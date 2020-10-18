/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1018_remove-nth-node-from-end-of-list.cpp
 * @Created Time:2020-10-18 12:12:57
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

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || n == 0)
            return head;
        ListNode *q = head, *p = head, *pre = nullptr;
        while (n--)
            q = q->next;
        if (!q)
            return head->next;
        while (q) {
            q = q->next;
            pre = p;
            p = p->next;
        }
        pre->next = pre->next->next;
        return head;
    }
};
class Solution {
public:
    int cur = 0;
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return NULL;
        head->next = removeNthFromEnd(head->next, n);
        cur++;
        if (n == cur) return head->next;
        return head;
    }
};