class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int res = intervals.size();
        sort(intervals.begin(), intervals.end(), [&](vector<int> a, vector<int> b){
            if(a[0] < b[0])
            {
                return true;
            }
            else if(a[0] > b[0])
            {
                return false;
            }
            return a[1] > b[1];
        });
        int maxEnd = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][1] <= maxEnd)
            {
                res--;
            }
            maxEnd = max(maxEnd, intervals[i][1]);
        }
        return res;
    }
};