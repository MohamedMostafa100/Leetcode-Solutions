class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long res = 0;
        unordered_map<char, unordered_map<char, int>> graph;
        unordered_map<char, unordered_map<char, long long>> minCost;
        for(int i = 0; i < original.size(); i++)
        {
            if(graph[original[i]].count(changed[i]))
            {
                graph[original[i]][changed[i]] = min(graph[original[i]][changed[i]], cost[i]);
            }
            else
            {
                graph[original[i]][changed[i]] = cost[i];
            }
        }
        for(char i = 'a'; i <= 'z'; i++)
        {
            minCost[i] = dijk(i, graph);
        }
        for(int i = 0; i < source.length(); i++)
        {
            if(minCost[source[i]].count(target[i]))
            {
                res += minCost[source[i]][target[i]];
            }
            else
            {
                return -1;
            }
        }
        return res;
    }
private:
    unordered_map<char, long long> dijk(char source, unordered_map<char, unordered_map<char, int>>& graph)
    {
        unordered_map<char, long long> res;
        priority_queue<pair<long long, char>, vector<pair<long long, char>>, greater<pair<long long, char>>> pq;
        unordered_set<char> visited;
        res[source] = 0;
        pq.push({0, source});
        while(!pq.empty())
        {
            char dest = pq.top().second;
            long long cost = pq.top().first;
            pq.pop();
            if(visited.count(dest))
            {
                continue;
            }
            visited.insert(dest);
            for(auto it : graph[dest])
            {
                if(!res.count(it.first))
                {
                    res[it.first] = it.second + cost;
                }
                else
                {
                    res[it.first] = min(res[it.first], it.second + cost);
                }
                pq.push({it.second + cost, it.first});
            }
        }
        return res;
    }
};