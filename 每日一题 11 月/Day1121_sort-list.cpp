/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1121_sort-list.cpp
 * @Created Time:2020-11-22 14:56:50
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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode dh(0);
        dh.next = head;
        ListNode* p = head;
        int n = 0;
        while (p) {
            ++n;
            p = p->next;
        }
        for (int sz = 1; sz < n; sz <<= 1) {
            ListNode *cur = dh.next, *tail = &dh;
            while (cur) {
                auto left = cur;
                auto right = cut(left, sz);
                cur = cut(right, sz);
                tail->next = merge(left, right);
                while (tail->next) tail = tail->next;
            }
        }
        return dh.next;
    }
    ListNode* cut(ListNode* h, int sz) {
        auto p = h;
        while (--sz && p)
            p = p->next;
        if (!p) return nullptr;
        auto next = p->next;
        p->next = nullptr;
        return next;
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummyHead(0);
        auto p = &dummyHead;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                p = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                p = l2;
                l2 = l2->next;
            }
        }
        p->next = l1 ? l1 : l2;
        return dummyHead.next;
    }
};