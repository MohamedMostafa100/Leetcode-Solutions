class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int res = 0;
        vector<int> used(n, 0);
        priority_queue<int, vector<int>, greater<int>> rooms;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> endTimes;
        sort(meetings.begin(), meetings.end());
        for(int i = 0; i < n; i++)
        {
            rooms.push(i);
        }

        for(int i = 0; i < meetings.size(); i++)
        {
            while(!endTimes.empty() && meetings[i][0] >= endTimes.top().first)
            {
                rooms.push(endTimes.top().second);
                endTimes.pop();
            }

            if(!rooms.empty())
            {
                endTimes.push({meetings[i][1], rooms.top()});
                used[rooms.top()]++;
                if(used[rooms.top()] > used[res])
                {
                    res = rooms.top();
                }
                else if(used[rooms.top()] == used[res] && rooms.top() < res)
                {
                    res = rooms.top();
                }
                rooms.pop();
            }
            else
            {
                long long newStart = endTimes.top().first;
                endTimes.push({newStart + meetings[i][1] - meetings[i][0], endTimes.top().second});
                used[endTimes.top().second]++;
                if(used[endTimes.top().second] > used[res])
                {
                    res = endTimes.top().second;
                }
                else if(used[endTimes.top().second] == used[res] && endTimes.top().second < res)
                {
                    res = endTimes.top().second;
                }
                endTimes.pop();
            }
        }
        return res;
    }
};