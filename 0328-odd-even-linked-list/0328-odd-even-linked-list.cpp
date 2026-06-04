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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)
        {
            return nullptr;
        }
        ListNode* p = head;
        ListNode* l1Head = nullptr;
        ListNode* l2Head = nullptr;
        ListNode* l1 = nullptr;
        ListNode* l2 = nullptr;
        bool odd = true;
        while(p)
        {
            ListNode* newNode = new ListNode(p->val);
            if(odd)
            {
                if(!l1Head)
                {
                    l1Head = newNode;
                    l1 = l1Head;
                }
                else
                {
                    l1->next = newNode;
                    l1 = l1->next;
                }
            }
            else
            {
                if(!l2Head)
                {
                    l2Head = newNode;
                    l2 = l2Head;
                }
                else
                {
                    l2->next = newNode;
                    l2 = l2->next;
                }
            }
            odd = !odd;
            p = p->next;
        }
        l1->next = l2Head;
        return l1Head;
    }
};