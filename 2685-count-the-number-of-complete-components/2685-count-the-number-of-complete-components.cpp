class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int res = 0;
        vector<vector<int>> graph(n);
        unordered_set<int> nodes;
        for(int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i = 0; i < n; i++)
        {
            if(!nodes.count(i))
            {
                vector<int> component = {};
                nodes.insert(i);
                component.push_back(i);
                bfs(graph, nodes, i, component);
                bool connected = true;
                for(int j = 0; j < component.size(); j++)
                {
                    if(graph[component[j]].size() != component.size() - 1)
                    {
                        connected = false;
                        break;
                    }
                }
                if(connected)
                {
                    res++;
                }
            }
        }
        return res;
    }
private:
    void bfs(vector<vector<int>>& graph, unordered_set<int>& nodes, int node, vector<int>& component)
    {
        queue<int> q;
        q.push(node);
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            for(int i = 0; i < graph[cur].size(); i++)
            {
                if(!nodes.count(graph[cur][i]))
                {
                    q.push(graph[cur][i]);
                    component.push_back(graph[cur][i]);
                    nodes.insert(graph[cur][i]);
                }
            }
        }
    }
};