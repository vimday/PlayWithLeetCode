#include<bits/stdc++.h>
using namespace std;
 struct ListNode {
    int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //递归
        //return help(nullptr,head);
        //迭代
        if(!head||!head->next) return head;
        ListNode* pre=nullptr,*cur=head;
        while(cur->next){
            ListNode* nx=cur->next;
            cur->next=pre;
            pre=cur;
            cur=nx;
        }
        cur->next=pre;
        return cur;
        
    }
    ListNode* help(ListNode*pre,ListNode* cur){
        if(!cur) return pre;
        ListNode* nxcur=cur->next;
        cur->next=pre;
        return help(cur,nxcur);
    }
};