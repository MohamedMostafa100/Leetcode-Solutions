class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> graph(n);
        vector<int> odds;
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0] - 1;
            int v = edges[i][1] - 1;
            graph[u].insert(v);
            graph[v].insert(u);
        }
        for(int i = 0; i < n; i++)
        {
            if(graph[i].size() % 2 == 1)
            {
                odds.push_back(i);
            }
        }
        if(odds.size() == 0)
        {
            return true;
        }
        else if(odds.size() == 2)
        {
            int u = odds[0];
            int v = odds[1];
            if(!graph[u].count(v))
            {
                return true;
            }
            for(int i = 0; i < n; i++)
            {
                if(i != u && i != v)
                {
                    if(!graph[i].count(u) && !graph[i].count(v))
                    {
                        return true;
                    }
                }
            }
        }
        else if(odds.size() == 4)
        {
            int a = odds[0];
            int b = odds[1];
            int c = odds[2];
            int d = odds[3];
            if((!graph[a].count(b) && !graph[c].count(d)) || (!graph[a].count(c) && !graph[b].count(d)) || (!graph[a].count(d) && !graph[b].count(c)))
            {
                return true;
            } 
        }
        return false;
    }
};