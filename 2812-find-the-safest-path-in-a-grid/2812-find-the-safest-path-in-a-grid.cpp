class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int res = INT_MAX;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        priority_queue<pair<int, int>> pq;
        unordered_set<int> visited;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    grid[i][j] = 0;
                    q.push({i, j});
                }
                else
                {
                    grid[i][j] = -1;
                }
            }
        }
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(j - 1 >= 0 && grid[i][j - 1] == -1)
            {
                grid[i][j - 1] = grid[i][j] + 1;
                q.push({i, j - 1});
            }
            if(j + 1 < n && grid[i][j + 1] == -1)
            {
                grid[i][j + 1] = grid[i][j] + 1;
                q.push({i, j + 1});
            }
            if(i - 1 >= 0 && grid[i - 1][j] == -1)
            {
                grid[i - 1][j] = grid[i][j] + 1;
                q.push({i - 1, j});
            }
            if(i + 1 < m && grid[i + 1][j] == -1)
            {
                grid[i + 1][j] = grid[i][j] + 1;
                q.push({i + 1, j});
            }
        }
        pq.push({grid[0][0], 0});
        while(!pq.empty())
        {
            int cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(visited.count(node))
            {
                continue;
            }
            res = min(res, cost);
            visited.insert(node);
            int i = node / n;
            int j = node % n;
            if(i == m - 1 && j == n - 1)
            {
                break;
            }
            if(j - 1 >= 0)
            {
                int newNode = n * i + (j - 1);
                if(!visited.count(newNode))
                {
                    pq.push({grid[i][j - 1], newNode});
                }
            }
            if(j + 1 < n)
            {
                int newNode = n * i + (j + 1);
                if(!visited.count(newNode))
                {
                    pq.push({grid[i][j + 1], newNode});
                }
            }
            if(i - 1 >= 0)
            {
                int newNode = n * (i - 1) + j;
                if(!visited.count(newNode))
                {
                    pq.push({grid[i - 1][j], newNode});
                }
            }
            if(i + 1 < m)
            {
                int newNode = n * (i + 1) + j;
                if(!visited.count(newNode))
                {
                    pq.push({grid[i + 1][j], newNode});
                }
            }
        }
        return res;
    }
};