/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0626_remove-duplicate-node-lcci.cpp
 * @Created Time:2020-06-26 01:04:28
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
    ListNode* removeDuplicateNodes(ListNode* head) {
        vector<bool> use(20001, false);
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* p = dummy;
        while (p->next != NULL) {
            if (use.at(p->next->val))
                p->next = p->next->next;
            else {
                use.at(p->next->val) = true;
                p = p->next;
            }
        }
        return dummy->next;
    }
};
class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        ListNode* ob = head;
        while (ob != nullptr) {
            ListNode* oc = ob;
            while (oc->next != nullptr) {
                if (oc->next->val == ob->val) {
                    oc->next = oc->next->next;
                } else {
                    oc = oc->next;
                }
            }
            ob = ob->next;
        }
        return head;
    }
};