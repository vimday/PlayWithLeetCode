/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1023_palindrome-linked-list.cpp
 * @Created Time:2020-10-23 13:26:12
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
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        if (!head || !head->next) return true;
        ListNode *p = head, *q = head;
        while (q->next && q->next->next) {
            p = p->next;
            q = q->next->next;
        }
        ListNode *h = reverse(p->next);
        return as(head, h);
    }
    ListNode *reverse(ListNode *h) {
        ListNode *p = new ListNode(-1), *t = p;
        while (h) {
            t = h->next;
            h->next = p->next;
            p->next = h;
            h = t;
        }
        return p->next;
    }
    bool as(ListNode *l1, ListNode *l2) {
        while (l1 && l2) {
            if (l1->val != l2->val)
                return false;
            l1 = l1->next;
            l2 = l2->next;
        }
        return true;
    }
};