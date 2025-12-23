class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int res = 0;
        int maxVal = 0;
        sort(events.begin(), events.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < events.size(); i++) {
            while (!pq.empty() && events[i][0] > pq.top().first) {
                maxVal = max(maxVal, pq.top().second);
                pq.pop();
            }
            pq.push({events[i][1], events[i][2]});
            res = max(res, events[i][2] + maxVal);
        }
        return res;
    }
};