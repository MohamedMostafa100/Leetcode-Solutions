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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* newHead = new ListNode(-1);
        newHead->next = head;
        head = newHead;
        ListNode* p = head;
        ListNode* q = head->next;
        while(q)
        {
            q = q->next;
            if(!q)
            {
                break;
            }
            q = q->next;
            p = p->next;
        }
        p->next = p->next->next;
        return head->next;
    }
};