class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int res = 0;
        vector<int> gaps;
        vector<bool> canMoved(startTime.size(), false);
        gaps.push_back(startTime[0]);
        for(int i = 1; i < startTime.size(); i++)
        {
            gaps.push_back(startTime[i] - endTime[i - 1]);
        }
        gaps.push_back(eventTime - endTime[endTime.size() - 1]);
        int maxLeft = 0;
        int maxRight = 0;
        for(int i = 1; i < startTime.size(); i++)
        {
            maxLeft = max(maxLeft, gaps[i - 1]);

            if(maxLeft >= endTime[i] - startTime[i])
            {
                canMoved[i] = true;
            }
        }

        for(int j = startTime.size() - 2; j >= 0; j--)
        {
            maxRight = max(maxRight, gaps[j + 2]);

            if(maxRight >= endTime[j] - startTime[j])
            {
                canMoved[j] = true;
            }
        }

        for(int i = 0; i < startTime.size(); i++)
        {
            int s;
            int e;
            if(canMoved[i])
            {
                s = i == 0 ? 0 : endTime[i - 1];
                e = i == startTime.size() - 1 ? eventTime : startTime[i + 1];
            }
            else
            {
                s = i == 0 ? endTime[i] - startTime[i] : endTime[i - 1] + endTime[i] - startTime[i];
                e = i == startTime.size() - 1 ? eventTime : startTime[i + 1];
            }
            res = max(res, e - s);
        }

        return res;
    }
};