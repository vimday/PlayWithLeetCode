/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1020_reorder-list.cpp
 * @Created Time:2020-10-20 11:05:44
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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        // 分成前后两段，然后reverse，然后拼在一起
        ListNode *fast = head, *slow = head;
        // 取后面的
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // 取前半段
        ListNode* pre = head;
        // 取后半段
        ListNode* post = slow->next;
        // 前半段的末尾变为NULL
        slow->next = NULL;
        post = reverse(post);

        ListNode* new_head = new ListNode(0);
        ListNode* cur = new_head;
        while (pre || post) {
            if (pre) {
                cur->next = pre;
                pre = pre->next;
                cur = cur->next;
            }
            if (post) {
                cur->next = post;
                post = post->next;
                cur = cur->next;
            }
        }
        cur->next = NULL;
        head = new_head->next;
    }

    ListNode* reverse(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* new_head = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return new_head;
    }
};
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;
        ListNode *s = head, *f = head->next;
        while (f && f->next) {
            s = s->next;
            f = f->next->next;
        }
        ListNode* h2 = s->next;
        s->next = nullptr;
        ListNode *pre = nullptr, *cur = h2;
        while (cur) {
            ListNode* t = cur->next;
            cur->next = pre;
            pre = cur;
            cur = t;
        }
        //         ListNode* dh=new ListNode(-1);cur=dh;
        //         while(pre||head){
        //             if(head) {cur->next=head;cur=head;head=head->next;}
        //            if(pre) {cur->next=pre;cur=pre;pre=pre->next;}

        //         }
        //         head=dh->next;
        cur = head;
        while (cur && pre) {
            // ListNode* curn=pre;
            // pre=pre->next;
            // ListNode* ncur=cur->next;
            // curn->next=ncur;
            // cur->next=curn;
            // cur=ncur;
            ListNode* ncur = cur->next;
            cur->next = pre;
            pre = pre->next;
            cur->next->next = ncur;
            cur = ncur;
        }
    }
};