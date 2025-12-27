class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int res = 0;
        int numUsed = 0;
        unordered_map<int, int> freqs;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> finishTimes;
        priority_queue<int, vector<int>, greater<int>> availableRooms;
        sort(meetings.begin(), meetings.end());
        for(int i = 0; i < n; i++)
        {
            availableRooms.push(i);
        }
        for(int i = 0; i < meetings.size(); i++)
        {
            while(!finishTimes.empty() && meetings[i][0] >= finishTimes.top().first)
            {
                availableRooms.push(finishTimes.top().second);
                finishTimes.pop();
            }
            int roomUsed;
            int usedRoomFreq;
            if(availableRooms.empty())
            {
                pair<long long, int> lastMeeting = finishTimes.top();
                finishTimes.pop();
                finishTimes.push({meetings[i][1] + lastMeeting.first - meetings[i][0], lastMeeting.second});
                freqs[lastMeeting.second]++;
                roomUsed = lastMeeting.second;
                usedRoomFreq = freqs[lastMeeting.second];
            }
            else
            {
                finishTimes.push({meetings[i][1], availableRooms.top()});
                freqs[availableRooms.top()]++;
                roomUsed = availableRooms.top();
                usedRoomFreq = freqs[availableRooms.top()];
                availableRooms.pop();
            }
            if(usedRoomFreq > numUsed)
            {
                res = roomUsed;
                numUsed = usedRoomFreq;
            }
            else if(usedRoomFreq == numUsed)
            {
                res = min(res, roomUsed);
            }
        }
        return res;
    }
};