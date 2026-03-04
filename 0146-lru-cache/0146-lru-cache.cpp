struct Node {
    pair<int, int> val;
    Node *next;
    Node* prev;
    Node() : val({-1, -1}), next(nullptr), prev(nullptr) {}
    Node(pair<int, int> x) : val(x), next(nullptr), prev(nullptr) {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        size = 0;
        this->capcity = capacity;
        head = nullptr;
        tail = nullptr;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
        {
            return -1;
        }
        Node* keyNode = mp[key];
        if(keyNode != tail)
        {
            if(keyNode == head)
            {
                head = head->next;
                head->prev = nullptr;
            }
            else
            {
                keyNode->prev->next = keyNode->next;
                keyNode->next->prev = keyNode->prev;
            }
            tail->next = keyNode;
            keyNode->prev = tail;
            keyNode->next = nullptr;
            tail = tail->next;
        }
        return mp[key]->val.second;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end())
        {
            mp[key]->val.second = value;
            get(key);
            return;
        }
        if(size < capcity)
        {
            if(!tail)
            {
                tail = new Node({key, value});
                head = tail;
            }
            else
            {
                tail->next = new Node({key, value});
                tail->next->prev = tail;
                tail = tail->next;
            }
            mp[key] = tail;
            size++;
        }
        else
        {
            tail->next = new Node({key, value});
            tail->next->prev = tail;
            tail = tail->next;
            mp[key] = tail;
            mp.erase(head->val.first);
            head = head->next;
            head->prev = nullptr;
        }
    }
private:
    vector<int> v;
    unordered_map<int, Node*> mp;
    int size;
    int capcity;
    Node* head;
    Node* tail;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */