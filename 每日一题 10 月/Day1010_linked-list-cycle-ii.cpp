/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1010_linked-list-cycle-ii.cpp
 * @Created Time:2020-10-10 18:27:38
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
    ListNode *detectCycle(ListNode *head) {
        if (!head) return nullptr;
        ListNode *p1 = head, *p2 = head, *q = head;
        while (p1 && p2) {
            p1 = p1->next;
            if (p2->next)
                p2 = p2->next->next;
            else
                return nullptr;
            if (!p1 || !p2) return nullptr;
            if (p1 == p2)
                break;
        }
        while (p1 != q) {
            p1 = p1->next;
            q = q->next;
        }
        return q;
    }
};