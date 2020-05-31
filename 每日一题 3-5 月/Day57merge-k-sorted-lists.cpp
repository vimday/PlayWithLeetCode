/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day57merge-k-sorted-lists.cpp
 * @Created Time:2020-04-26 00:31:21
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        unordered_map<int, int> m;
        int mx = INT_MIN, mn = INT_MAX;
        for (auto node : lists) {
            ListNode* t = node;
            while (t) {
                mx = max(mx, t->val);
                mn = min(mn, t->val);
                ++m[t->val];
                t = t->next;
            }
        }
        for (int i = mn; i <= mx; ++i) {
            if (!m.count(i)) continue;
            for (int j = 0; j < m[i]; ++j) {
                cur->next = new ListNode(i);
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        ListNode* dhead = new ListNode(-1);
        ListNode* cur = dhead;
        function<bool(ListNode*, ListNode*)> cmp = [&](ListNode* l1, ListNode* l2) {
            return l2->val < l1->val;
        };
        //模板类参数中不能含有lamada，因为由lambda表达式创建的匿名类型没有默认构造函数。 (我记得与boost :: bind类似的问题。)是否有一些理由草案标准不允许这个，或者我错了，它是允许的，但GCC只是落后于他们的实现？
        // priority_queue<ListNode*,vector<ListNode*>,decltype([&](ListNode* l1,ListNode*l2){
        //     return l2->val<l1->val;
        // })> pq;
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for (ListNode* l : lists) {
            if (!l)
                continue;
            pq.push(l);
        }
        while (!pq.empty()) {
            ListNode* t = pq.top();
            pq.pop();
            cur->next = t;
            cur = t;
            if (t->next)
                pq.push(t->next);
        }
        return dhead->next;
    }
};