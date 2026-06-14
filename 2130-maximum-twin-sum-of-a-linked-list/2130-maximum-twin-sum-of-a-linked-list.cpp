/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        int res = 0;
        ListNode* p = head;
        ListNode* q = head->next;
        while(q->next)
        {
            q = q->next->next;
            ListNode* temp = p->next;
            p->next = p->next->next;
            temp->next = head;
            head = temp;
        }
        p = p->next;
        q = head;
        while(p)
        {
            res = max(res, q->val + p->val);
            p = p->next;
            q = q->next;
        }
        return res;
    }
};