class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int smallestAbs = INT_MAX;
        int countNeg = 0;
        bool containsZero = false;
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix.size(); j++)
            {
                sum += abs(matrix[i][j]);
                smallestAbs = min(smallestAbs, abs(matrix[i][j]));
                if(matrix[i][j] < 0)
                {
                    countNeg++;
                }
                else if(matrix[i][j] == 0)
                {
                    containsZero = true;
                }
            }
        }
        if(countNeg % 2 != 0 && !containsZero)
        {
            return sum - (2 * smallestAbs);
        }
        return sum;
    }
};