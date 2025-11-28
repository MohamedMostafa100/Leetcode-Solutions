class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adjList(n);

        for(int i = 0; i < edges.size(); i++)
        {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }

        int splits = 0;
        dfs(0, adjList, values, k, -1, splits);
        return splits;
    }

private:
    long long dfs(int cur , vector<vector<int>>& adjList, vector<int>& values, int k, int parent, int& splits)
    {
        long long sum = values[cur];
        for(int i = 0; i < adjList[cur].size(); i++)
        {
            if(adjList[cur][i] != parent)
            {
                sum += dfs(adjList[cur][i], adjList, values, k, cur, splits);
            }
        }

        if(sum % k == 0)
        {
            splits++;
            return 0;
        }

        return sum;
    }
};