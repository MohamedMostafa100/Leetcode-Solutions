/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
        {
            return nullptr;
        }
        unordered_map<Node*, Node*> newNodes;
        Node* newHead = new Node(head->val);
        Node* p = head->next;
        Node* prev = newHead;
        newNodes[head] = newHead;
        if(head->random)
        {
            Node* rand = newNodes.find(head->random) != newNodes.end() ? newNodes[head->random] : new Node(head->random->val);
            newHead->random = rand;
            newNodes[head->random] = rand;
        }
        while(p)
        {
            Node* newNode = nullptr;
            Node* rand = nullptr;
            if(newNodes.find(p) != newNodes.end())
            {
                newNode = newNodes[p];
            }
            else
            {
                newNode = new Node(p->val);
                newNodes[p] = newNode;
            }
            prev->next = newNode;
            if(newNodes.find(p->random) != newNodes.end())
            {
                rand = newNodes[p->random];
            }
            else if(p->random)
            {
                rand = new Node(p->random->val);
                newNodes[p->random] = rand;
            }
            newNode->random = rand;
            prev = newNode;
            p = p->next;
        }
        return newHead;
    }
};