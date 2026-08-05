class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> res;
        unordered_set<int> toRemove;
        vector<vector<int>> graph(n);
        vector<bool> visited(n);
        for(int i = 0; i < invocations.size(); i++)
        {
            int u = invocations[i][0];
            int v = invocations[i][1];
            graph[u].push_back(v);
        }
        dfs(graph, visited, toRemove, k);
        for(int i = 0; i < n; i++)
        {
            if(!toRemove.count(i))
            {
                for(int j = 0; j < graph[i].size(); j++)
                {
                    int v = graph[i][j];
                    if(toRemove.count(v))
                    {
                        for(int i = 0; i < n; i++)
                        {
                            res.push_back(i);
                        }
                        return res;
                    }
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(!toRemove.count(i))
            {
                res.push_back(i);
            }
        }
        return res;
    }
private:
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, unordered_set<int>& toRemove,  int node)
    {
        visited[node] = true;
        toRemove.insert(node);
        for(int i = 0; i < graph[node].size(); i++)
        {
            int v = graph[node][i];
            if(!visited[v])
            {
                dfs(graph, visited, toRemove, v);
            }
        }
    }
};