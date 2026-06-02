class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int res = INT_MAX;
        int landMin = INT_MAX;
        int waterMin = INT_MAX;
        for(int i = 0; i < landStartTime.size(); i++)
        {
            landMin = min(landMin, landStartTime[i] + landDuration[i]);
        }
        for(int i = 0; i < waterStartTime.size(); i++)
        {
            res = min(res, max(landMin, waterStartTime[i]) + waterDuration[i]);
        }
        for(int i = 0; i < waterStartTime.size(); i++)
        {
            waterMin = min(waterMin, waterStartTime[i] + waterDuration[i]);
        }
        for(int i = 0; i < landStartTime.size(); i++)
        {
            res = min(res, max(waterMin, landStartTime[i]) + landDuration[i]);
        }
        return res;
    }
};