class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long long sum = 0;
        for(int i = 0; i < target.size(); i++)
        {
            sum += target[i];
            if(target[i] > 1)
            {
                pq.push(target[i]);
            }
        }
        while(!pq.empty())
        {
            int cur = pq.top();
            pq.pop();
            int diff = sum - cur;
            if(cur < diff || diff < 1)
            {
                return false;
            }
            int next = cur % diff;
            if(next == 0)
            {
                if(diff != 1)
                {
                    return false;
                }
            }
            sum = next + diff;
            if(next > 1)
            {
                pq.push(next);
            }
        }
        return true;
    }
};