class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea = 0;
        double maxDiag = 0;
        for(int i = 0; i < dimensions.size(); i++)
        {
            double diag = sqrt(pow(dimensions[i][0], 2) + pow(dimensions[i][1], 2));
            if(diag > maxDiag)
            {
                maxArea = dimensions[i][0] * dimensions[i][1];
            }
            else if(diag == maxDiag)
            {
                maxArea = max(maxArea, dimensions[i][0] * dimensions[i][1]);
            }
            maxDiag = max(maxDiag, diag);
        }
        return maxArea;
    }
};