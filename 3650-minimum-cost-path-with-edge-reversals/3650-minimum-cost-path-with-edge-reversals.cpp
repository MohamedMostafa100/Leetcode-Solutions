class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> graph(n);
        for(int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0], edges[i][2] * 2});
        }
        return dijk(n, graph);
    }
private:
    int dijk(int n, vector<vector<pair<int, int>>>& graph)
    {
        vector<int> res(n, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_set<int> visited;
        pq.push({0, 0});
        while(!pq.empty())
        {
            int dest = pq.top().second;
            int cost = pq.top().first;
            pq.pop();
            if(visited.count(dest))
            {
                continue;
            }
            visited.insert(dest);
            for(int i = 0; i < graph[dest].size(); i++)
            {
                if(res[graph[dest][i].first] == -1 || cost + graph[dest][i].second < res[graph[dest][i].first])
                {
                    res[graph[dest][i].first] = cost + graph[dest][i].second;
                    pq.push({cost + graph[dest][i].second, graph[dest][i].first});
                }
            }
        }
        return res[n - 1];
    }
};