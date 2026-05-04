class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int start = 0;
        int end = n - 1;
        for(int i = 0; i < n / 2; i++)
        {
            for(int j = start; j < end; j++)
            {
                swap(matrix[i][j], matrix[j][end]);
                swap(matrix[i][j], matrix[end][end - j + start]);
                swap(matrix[i][j], matrix[end - j + start][i]);
            }
            start++;
            end--;
        }
    }
};