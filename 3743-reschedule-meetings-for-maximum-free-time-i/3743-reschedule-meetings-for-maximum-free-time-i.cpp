class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int res = startTime[0];
        int left = 0;
        int curLength = 0;
        for(int right = 0; right < startTime.size(); right++)
        {
            curLength += endTime[right] - startTime[right];
            int s = right < k ? 0 : startTime[left];
            int e = right == startTime.size() - 1 ? eventTime : startTime[right + 1];
            res = max(res, e - s - curLength);
            if(right - left + 1 == k + 1)
            {
                curLength -= endTime[left] - startTime[left];
                left++;
            }
        }

        return res;
    }
};