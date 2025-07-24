class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int res = INT_MAX;
        int sum = 0;
        vector<vector<int>> graph(nums.size());
        vector<int> xors(nums.size());
        vector<unordered_set<int>> descendants(nums.size());
        for(int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(nums, graph, xors, descendants, 0, -1);
        sum = xors[0];
        for(int i = 1; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                int part1 = 0;
                int part2 = 0;
                int part3 = 0;
                if(descendants[i].find(j) != descendants[i].end())
                {
                    part1 = xors[i] ^ xors[j];
                    part2 = xors[j];
                    part3 = sum ^ xors[i];
                }
                else if(descendants[j].find(i) != descendants[j].end())
                {
                    part1 = xors[j] ^ xors[i];
                    part2 = xors[i];
                    part3 = sum ^ xors[j];
                }
                else
                {
                    part1 = xors[i];
                    part2 = xors[j];
                    part3 = sum ^ xors[i] ^ xors[j];
                }
                int score = max({part1, part2, part3}) - min({part1, part2, part3});
                res = min(res, score);
            }
        }
        return res;
    }

private:
    void dfs(vector<int>& nums, vector<vector<int>>& graph, vector<int>& xors, vector<unordered_set<int>>& descendants, int node, int parent)
    {
        xors[node] = nums[node];
        descendants[node].insert(node);
        for(int i = 0; i < graph[node].size(); i++)
        {
            if(graph[node][i] != parent)
            {
                dfs(nums, graph, xors, descendants, graph[node][i], node);
                descendants[node].insert(graph[node][i]);
                xors[node] ^= xors[graph[node][i]];
                descendants[node].insert(descendants[graph[node][i]].begin(), descendants[graph[node][i]].end());
            }
        }
    }
};