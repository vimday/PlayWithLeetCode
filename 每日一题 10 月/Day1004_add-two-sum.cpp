/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1004_add-two-sum.cpp
 * @Created Time:2020-10-04 19:24:51
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode *dh = new ListNode(-1), *cur = dh;
        int c = 0;
        while (l1 || l2 || c) {
            int v = 0;
            if (l1) {
                v += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                v += l2->val;
                l2 = l2->next;
            }
            v += c;
            cur->next = new ListNode(v % 10);
            cur = cur->next;
            c = v / 10;
        }
        return dh->next;
    }
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        ListNode* h = l1;
        int c = 0;
        while (l2 || c) {
            if (l2) {
                c += l2->val;
                l2 = l2->next;
            }
            c += l1->val;
            l1->val = c % 10;
            c /= 10;
            if (!l1->next && (c || l2))
                l1->next = new ListNode(0);
            l1 = l1->next;
        }
        return h;
    }
};