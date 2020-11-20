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