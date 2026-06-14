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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* p = list1;
    ListNode* q = list2;
    ListNode* newList = nullptr;
    ListNode* nl = nullptr;
    while (p || q)
    {
        ListNode* newNode = nullptr;
        if (!q || (p && p->val <= q->val))
        {
            newNode = new ListNode(p->val);
            p = p->next;
        }
        else if (!p || (q && q->val < p->val))
        {
            newNode = new ListNode(q->val);
            q = q->next;
        }
        if (!newList)
        {
            newList = newNode;
            nl = newList;
        }
        else
        {
            nl->next = newNode;
            nl = nl->next;
        }
    }
    return newList;
}
};
