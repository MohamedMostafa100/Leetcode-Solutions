class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int res = 0;
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>&b){
            if (a[0] == b[0])
            {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        for (char i = 0; i < points.size(); i++)
        {
            char lowerLimit = -1;
            for (char j = i + 1; j < points.size(); j++)
            {
                if (points[j][1] < points[i][1])
                {
                    if (points[j][1] > lowerLimit)
                    {
                        res++;
                        lowerLimit = points[j][1];
                    }
                }
                else if(points[j][1] == points[i][1])
                {
                    res++;
                    break;
                }
            }
        } 
        return res;
    }
};