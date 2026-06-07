class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int res = 0;
        int day = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(int i = 0; i < apples.size(); i++)
        {
            while(!minHeap.empty() && day >= minHeap.top().first)
            {
                minHeap.pop();
            }
            if(apples[i] > 0)  
            {
                minHeap.push({i + days[i], apples[i]});
            }
            if(!minHeap.empty())
            {
                int d = minHeap.top().first;
                int rem = minHeap.top().second;
                res++;
                minHeap.pop();
                rem--;
                if(rem > 0)
                {
                    minHeap.push({d, rem});
                }
            }
            day++;
        }
        while(!minHeap.empty())
        {
            while(!minHeap.empty() && day >= minHeap.top().first)
            {
                minHeap.pop();
            }
            if(!minHeap.empty())
            {
                int d = minHeap.top().first;
                int rem = minHeap.top().second;
                res++;
                minHeap.pop();
                rem--;
                if(rem > 0)
                {
                    minHeap.push({d, rem});
                }
            }
            day++;
        }
        return res;
    }
};