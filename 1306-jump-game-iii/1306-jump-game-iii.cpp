class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        return dfs(arr, visited, start);
    }
private:
    bool dfs(vector<int>& arr, vector<bool>& visited, int start)
    {
        if(start < 0 || start >= arr.size() || visited[start])
        {
            return false;
        }
        visited[start] = true;
        if(arr[start] == 0)
        {
            return true;
        }
        return (dfs(arr, visited, start + arr[start]) || dfs(arr, visited, start - arr[start]));
    }
};