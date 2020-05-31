/*
 * @Author      :vimday
 * @Desc        :lc 每日一题5.1
 * @Url         :https://leetcode-cn.com/problems/merge-two-sorted-lists/
 * @File Name   :Day62merge-two-sorted-list.cpp
 * @Created Time:2020-05-01 00:26:53
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

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode *dh = new ListNode(-1), *cur = dh;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
                cur = cur->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
            }
        }
        if (l1)
            cur->next = l1;
        else
            cur->next = l2;
        return dh->next;
    }
};