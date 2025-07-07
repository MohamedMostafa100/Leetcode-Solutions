class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int res = 0;
        int lastDay = INT_MIN;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < events.size(); i++)
        {
            lastDay = max(lastDay, events[i][1]);
        }
        sort(events.begin(), events.end());

        int j = 0;
        for(int i = 0; i <= lastDay; i++)
        {
            while(j < events.size() && events[j][0] <= i)
            {
                pq.push(events[j][1]);
                j++;
            }

            while(!pq.empty() && pq.top() < i)
            {
                pq.pop();
            }

            if(!pq.empty())
            {
                pq.pop();
                res++;
            }
        }

        return res;
    }
};