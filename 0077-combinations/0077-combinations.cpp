class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        solve(res, {}, 1, n, k);
        return res;
    }
private:
    void solve(vector<vector<int>>& res, vector<int> cur, int i, int n, int k)
    {
        if(cur.size() == k)
        {
            res.push_back(cur);
            return;
        }
        for(int x = i; x <= n; x++)
        {
            cur.push_back(x);
            solve(res, cur, x + 1, n, k);
            cur.pop_back();
        }
    }
};