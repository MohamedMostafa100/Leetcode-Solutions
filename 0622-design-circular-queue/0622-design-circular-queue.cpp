class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        q.assign(k, 0);
        full = k;
        size = 0;
        nextP = 0;
        topP = 0;
    }
    
    bool enQueue(int value) {
        if(size < full)
        {
            q[nextP] = value;
            nextP = (nextP + 1) % full;
            size++;
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(size > 0)
        {
            topP = (topP + 1) % full;
            size--;
            return true;
        }
        return false;
    }
    
    int Front() {
        if(size > 0)
        {
            return q[topP];
        }
        return -1;
    }
    
    int Rear() {
        if(size > 0)
        {
            return q[(nextP - 1 + full) % full];
        }
        return -1;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == full;
    }
private:
    vector<int> q;
    int full;
    int size;
    int nextP;
    int topP;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */