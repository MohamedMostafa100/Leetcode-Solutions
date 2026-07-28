class Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int res = 0;
        int n = values.size();
        vector<vector<pair<int, int>>> graph(n);
        vector<int> visited(n, 0);
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int val = edges[i][2];
            graph[u].push_back({v, val});
            graph[v].push_back({u, val});
        }
        dfs(values, graph, visited, 0, maxTime, 0, res);
        return res;
    }
private:
    void dfs(vector<int>& values, vector<vector<pair<int, int>>>& graph, vector<int>& visited, int node, int maxTime, int curRes, int& res)
    {
        if(maxTime < 0)
        {
            return;
        }
        if(visited[node] == 0)
        {
            curRes += values[node];
        }
        if(node == 0)
        {
            res = max(res, curRes);
        }
        visited[node]++;
        for(int i = 0; i < graph[node].size(); i++)
        {
            dfs(values, graph, visited, graph[node][i].first, maxTime - graph[node][i].second, curRes, res);
        }
        visited[node]--;
    }
};