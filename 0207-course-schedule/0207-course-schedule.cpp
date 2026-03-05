class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (int i = 0; i < prerequisites.size(); i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        int visited = 0;
        queue<int> q;
        vector<int> inDegree(numCourses, 0);
        for(int i = 0; i < adj.size(); i++)
        {
            for(int j = 0; j < adj[i].size(); j++)
            {
                inDegree[adj[i][j]]++;
            }
        }

        for(int i = 0; i < inDegree.size(); i++)
        {
            if(inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            visited++;
            for(int i = 0; i < adj[q.front()].size(); i++)
            {
                inDegree[adj[q.front()][i]]--;

                if(inDegree[adj[q.front()][i]] == 0)
                {
                    q.push(adj[q.front()][i]);
                }
            }
            q.pop();
        }
        return visited == numCourses;
    }
};