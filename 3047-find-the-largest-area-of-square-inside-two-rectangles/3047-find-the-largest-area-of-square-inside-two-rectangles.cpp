class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long res = 0;
        for(int i = 0; i < bottomLeft.size(); i++)
        {
            for(int j = i + 1; j < bottomLeft.size(); j++)
            {
                long long intX = min(topRight[i][0], topRight[j][0]) - max(bottomLeft[i][0], bottomLeft[j][0]);
                long long intY = min(topRight[i][1], topRight[j][1]) - max(bottomLeft[i][1], bottomLeft[j][1]);
                if(intX > 0 && intY > 0)
                {
                    res = max(res, min(intX, intY) * 1LL * min(intX, intY));
                }
            }
        }
        return res;
    }
};