class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        unordered_map<int, unordered_map<int, double>> excess;
        excess[0][0] = poured;
        for(int i = 0; i < 100; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                if(i == query_row && j == query_glass)
                {
                    return min(excess[i][j], 1.0);
                }
                excess[i + 1][j] += (0.5 * max(excess[i][j] - 1, 0.0));
                excess[i + 1][j + 1] += (0.5 * max(excess[i][j] - 1, 0.0));
            }
        }
        return 0;
    }
};