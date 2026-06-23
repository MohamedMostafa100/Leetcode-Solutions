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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = nullptr;
        ListNode* p = nullptr;
        vector<ListNode*> pointers;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < lists.size(); i++)
        {
            pointers.push_back(lists[i]);
            if(lists[i])
            {
                pq.push({lists[i]->val, i});
            }
        }
        while(!pq.empty())
        {
            int val = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            if(!res)
            {
                res = new ListNode(val);
                p = res;
            }
            else
            {
                p->next = new ListNode(val);
                p = p->next;
            }
            pointers[idx] = pointers[idx]->next;
            if(pointers[idx])
            {
                pq.push({pointers[idx]->val, idx});
            }
        }
        return res;
    }
};