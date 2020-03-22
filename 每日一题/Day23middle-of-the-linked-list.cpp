/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day23middle-of-the-linked-list.cpp
 * @Created Time:2020-03-23 00:14:58
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
    ListNode* middleNode(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *s = head, *f = head->next;
        while (f) {
            s = s->next;
            if (f->next)
                f = f->next->next;
            else {
                break;
            }
        }
        return s;
    }
};