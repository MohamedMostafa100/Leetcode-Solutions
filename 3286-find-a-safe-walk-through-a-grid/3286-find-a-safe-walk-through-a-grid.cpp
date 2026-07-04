class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        unordered_set<int> visited;
        minHeap.push({grid[0][0], 0});
        while(!minHeap.empty())
        {
            int cost = minHeap.top().first;
            int node = minHeap.top().second;
            minHeap.pop();
            if(visited.count(node))
            {
                continue;
            }
            visited.insert(node);
            int i = node / n;
            int j = node % n;
            if(i == m - 1 && j == n - 1)
            {
                return true;
            }
            if(j - 1 >= 0)
            {
                int newNode = n * i + (j - 1);
                if(!visited.count(newNode) && cost + grid[i][j - 1] < health)
                {
                    minHeap.push({cost + grid[i][j - 1], newNode});
                }
            }
            if(j + 1 < n)
            {
                int newNode = n * i + (j + 1);
                if(!visited.count(newNode) && cost + grid[i][j + 1] < health)
                {
                    minHeap.push({cost + grid[i][j + 1], newNode});
                }
            }
            if(i - 1 >= 0)
            {
                int newNode = n * (i - 1) + j;
                if(!visited.count(newNode) && cost + grid[i - 1][j] < health)
                {
                    minHeap.push({cost + grid[i - 1][j], newNode});
                }
            }
            if(i + 1 < m)
            {
                int newNode = n * (i + 1) + j;
                if(!visited.count(newNode) && cost + grid[i + 1][j] < health)
                {
                    minHeap.push({cost + grid[i + 1][j], newNode});
                }
            }
        }
        return false;
    }
};