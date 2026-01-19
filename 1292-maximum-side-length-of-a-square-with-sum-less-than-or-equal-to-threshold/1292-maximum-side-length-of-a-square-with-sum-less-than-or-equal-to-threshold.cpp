class Solution {
private:
    vector<vector<int>> rowSum;
    bool checkSquare(int row, int col, int side, int thres) {
        if (row + side - 1 >= rowSum.size() ||
            col + side - 1 >= rowSum[0].size()) {
            return false;
        }
        int tot = 0;
        for (int i = row; i < row + side; i++) {
            if (col > 0) {
                tot += rowSum[i][col + side - 1] - rowSum[i][col - 1];
            } else {
                tot += rowSum[i][col + side - 1];
            }
            if (tot > thres) {
                return false;
            }
        }
        return true;
    }

public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int res = 0;
        int n = mat.size();
        int m = mat[0].size();
        int l = 0;
        int r = min(n, m) + 1;
        rowSum = vector<vector<int>>(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            int tot = 0;
            for (int j = 0; j < m; j++) {
                tot += mat[i][j];
                rowSum[i][j] = tot;
            }
        }
        while (l < r) {
            int mid = (l + r) / 2;
            bool flag = false;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if(checkSquare(i, j, mid, threshold))
                    {
                        flag = true;
                        break;
                    }
                }
                if(flag)
                {
                    break;
                }
            }
            if(flag)
            {
                res = mid;
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return res;
    }
};