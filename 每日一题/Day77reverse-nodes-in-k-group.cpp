/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day77reverse-nodes-in-k-group.cpp
 * @Created Time:2020-05-16 00:05:06
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        ListNode *dh = new ListNode(-1), *cur = dh;
        while (cur && head) {
            ListNode* l = head;
            ListNode* r = cut(head, k);
            if (r) {
                ListNode* nh = r->next;
                r->next = nullptr;
                cur->next = reverse(l);
                cur = l;
                head = nh;
            } else {
                cur->next = l;
                break;
            }
        }
        return dh->next;
    }
    ListNode* cut(ListNode* h, int k) {
        ListNode* p = h;
        while (--k && p)
            p = p->next;

        return p;
    }
    ListNode* reverse(ListNode* h) {
        ListNode *cur = h, *pre = nullptr;
        while (cur) {
            ListNode* t = cur->next;
            cur->next = pre;
            pre = cur;
            cur = t;
        }
        return pre;
    }
};