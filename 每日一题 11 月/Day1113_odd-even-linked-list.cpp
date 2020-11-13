/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1113_odd-even-linked-list.cpp
 * @Created Time:2020-11-13 15:01:13
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
    ListNode* oddEvenList(ListNode* head) {
        // ListNode *h1=new ListNode(-1),*cur1=h1;int i=0;
        // ListNode *h2=new ListNode(-1),*cur2=h2;
        // while(head){
        //     if(i++%2){cur2->next=head;cur2=head;head=head->next;cur2->next=nullptr;}
        //     else{cur1->next=head;cur1=head;head=head->next;cur1->next=nullptr;}
        //     //cout<<head->val;
        // }
        // cur1->next=h2->next;
        // return h1->next;
        if (!head || !head->next) return head;
        ListNode *cur1 = head, *cur2 = head->next, *t = cur2;
        while (cur2 && cur2->next) {
            cur1->next = cur1->next->next;
            cur2->next = cur2->next->next;
            //cout<<cur1->val<<cur2->val;
            cur1 = cur1->next;
            cur2 = cur2->next;
            //cout<<cur1->val<<cur2->val;
        }
        cur1->next = t;
        return head;
    }
};