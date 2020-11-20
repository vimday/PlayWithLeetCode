/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day1120_insertion-sort-list.cpp
 * @Created Time:2020-11-20 21:23:38
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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode node(-1);
        ListNode* dummy = &node;
        dummy->next = head;
        ListNode *curr = head->next, *prev = head;
        while (curr) {
            if (curr->val < prev->val) {
                ListNode* tmp = dummy;
                while (tmp->next->val < curr->val)
                    tmp = tmp->next;
                prev->next = curr->next;
                curr->next = tmp->next;
                tmp->next = curr;
                curr = prev->next;
            } else {
                curr = curr->next;
                prev = prev->next;
            }
        }
        return dummy->next;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        return bublesort(head);
        auto dh = new ListNode(-1), pre = dh, tail = head;
        dh->next = head;
        while (tail != nullptr && tail->next != nullptr) {
            if (tail->val <= tail->next->val) {
                tail = tail->next;
                continue;
            }
            pre = dh;
            auto cur = tail->next;
            while (pre->next->val < cur->val)
                pre = pre->next;
            tail->next = cur->next;
            cur->next = pre->next;
            pre->next = cur;
        }
        return dh->next;
    }
    ListNode* bublesort(ListNode* head) {
        ListNode* dh = new ListNode(-1);
        dh->next = head;
        ListNode* tail = nullptr;

        while (dh->next != tail) {
            auto cur = dh->next, pre = dh, cm = cur, pcm = dh;
            for (; cur != tail; cur = cur->next, pre = pre->next)
                if (cur->val > cm->val) {
                    //cout<<cur->val<<endl;
                    pcm = pre;
                    cm = cur;
                }
            if (cm->next == tail) {
                tail = cm;
                continue;
            }

            pcm->next = cm->next;
            pre->next = cm;
            cm->next = tail;
            tail = cm;
            //cout<<tail->val<<endl;
        }
        return dh->next;
    }
    ListNode* insert1(ListNode* head) {
        auto dh = new ListNode(-1);  //dh->next=head;
        auto tmp = dh;
        for (auto cur = head; cur != nullptr; cur = tmp) {
            auto pre = dh;
            for (; pre->next && pre->next->val < cur->val; pre = pre->next)
                ;
            tmp = cur->next;
            cur->next = pre->next;
            pre->next = cur;
        }
        return dh->next;
    }
};