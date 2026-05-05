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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
        {
            return head;
        }
        ListNode* p = head;
        ListNode* q = head;
        int i = 0;
        while(i < k)
        {
            p = p->next;
            i++;
            if(!p)
            {
                k %= i;
                i = 0;
                p = head;
            }
        }
        if(p == q)
        {
            return head;
        }
        while(p->next)
        {
            p = p->next;
            q = q->next;
        }
        p->next = head;
        head = q->next;
        q->next = nullptr;
        return head;
    }
};