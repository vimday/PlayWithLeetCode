/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day45add-two-nums-ii.cpp
 * @Created Time:2020-04-14 00:06:11
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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> s1, s2;
        ListNode *t1 = l1, *t2 = l2;
        while (t1) {
            s1.push(t1), t1 = t1->next;
        }
        while (t2) {
            s2.push(t2), t2 = t2->next;
        }
        int carry = 0;
        ListNode* p = new ListNode(-1);
        while (carry != 0 || !s1.empty() || !s2.empty()) {
            if (!s1.empty()) {
                carry += s1.top()->val;
                s1.pop();
            }
            if (!s2.empty()) {
                carry += s2.top()->val;
                s2.pop();
            }
            ListNode* t = new ListNode(carry % 10);
            t->next = p->next;
            p->next = t;
            carry /= 10;
        }

        return p->next;
    }
};

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode *pre = NULL, *cur = head, *temp;
        while (cur) {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
    ListNode* addTwo(ListNode* l1, ListNode* l2) {
        ListNode preHead(0), *p = &preHead;
        int extra = 0;
        while (l1 || l2 || extra) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
            extra = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return preHead.next;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        l1 = addTwo(l1, l2);
        return (reverse(l1));
    }
};
