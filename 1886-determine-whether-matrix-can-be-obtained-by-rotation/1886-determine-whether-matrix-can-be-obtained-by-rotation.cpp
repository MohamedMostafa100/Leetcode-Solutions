class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        vector<vector<int>> newMat = mat;
        int n = mat.size();
        for(int k = 0; k < 4; k++)
        {
            bool match = true;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(mat[i][j] != target[i][j])
                    {
                        match = false;
                    }
                    newMat[j][n - i - 1] = mat[i][j];
                }
            }
            if(match)
            {
                return true;
            }
            mat = newMat;
        }
        return false;
    }
};