class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int res = INT_MAX;
        vector<vector<pair<int, int>>> graph(n);
        queue<int> q;
        unordered_set<int> visited;
        for(int i = 0; i < roads.size(); i++)
        {
            graph[roads[i][0] - 1].push_back({roads[i][1] - 1, roads[i][2]});
            graph[roads[i][1] - 1].push_back({roads[i][0] - 1, roads[i][2]});
        }
        q.push(0);
        visited.insert(0);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(int i = 0; i < graph[node].size(); i++)
            {
                res = min(res, graph[node][i].second);
                if(!visited.count(graph[node][i].first))
                {
                    q.push(graph[node][i].first);
                    visited.insert(graph[node][i].first);
                }
            }
        }
        return res;
    }
};