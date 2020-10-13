/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1013_swap-pairs.cpp
 * @Created Time:2020-10-13 14:20:20
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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dh = new ListNode(-1), *pre = dh, *t;
        pre->next = head;
        while (pre->next && pre->next->next) {
            t = pre->next;
            pre->next = t->next;
            t->next = t->next->next;
            pre->next->next = t;
            pre = t;
        }
        return dh->next;
    }
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;
        return next;
    }
};