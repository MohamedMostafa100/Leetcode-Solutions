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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* p = head;
        ListNode* q = p;
        unordered_set<int> del(nums.begin(), nums.end());
        while(q)
        {
            if(del.find(q->val) != del.end())
            {
                if(q == head)
                {
                    q = q->next;
                    p->next = nullptr;
                    p = q;
                    head = p;
                }
                else
                {
                    q = q->next;
                    p->next = q;
                }
                continue;
            }
            p = q;
            q = q->next;
        }
        return head;
    }
};