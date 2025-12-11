class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int res = 0;
        vector<int> minX(n + 1, INT_MAX);
        vector<int> maxX(n + 1, 1);
        vector<int> minY(n + 1, INT_MAX);
        vector<int> maxY(n + 1, 1);
        for(int i = 0; i < buildings.size(); i++)
        {
            int x = buildings[i][0];
            int y = buildings[i][1];
            minX[y] = min(minX[y], x);
            maxX[y] = max(maxX[y], x);
            minY[x] = min(minY[x], y);
            maxY[x] = max(maxY[x], y);
        }
        for(int i = 0; i < buildings.size(); i++)
        {
            int x = buildings[i][0];
            int y = buildings[i][1];
            if(x > minX[y] && x < maxX[y] && y > minY[x] && y < maxY[x])
            {
                res++;
            }
        }
        return res;
    }
};