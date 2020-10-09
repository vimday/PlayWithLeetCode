/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1009_linked-list-cycle.cpp
 * @Created Time:2020-10-09 13:24:29
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
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode *p1 = head, *p2 = head->next;
        while (p1 && p2) {
            if (p1 == p2) return true;
            p1 = p1->next;

            if (p2->next)
                p2 = p2->next->next;
            else
                return false;
        }
        return false;
    }
};

//     1 o(n)算法，应该是最快的。
//     2 堆的地址从低到高，
//     3 LeetCode的链表内存是顺序申请的，
//     4 如果有环，head->next一定小于head，哈哈哈哈哈
//     5 
//     6 class Solution {
//     7 public:
//     8         ListNode *detectCycle(ListNode *head) {
//     9                 while(head) {
//    10                         if(!less<ListNode *>()(head, head->next)) {
//    11                                 return head->next;
//    12                         }
//    13                         head = head->next;
//    14                 }
//    15                 return nullptr;
//    16         }
//    17 