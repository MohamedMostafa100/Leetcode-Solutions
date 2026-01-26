class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        int minDiff = INT_MAX;
        sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size() - 1; i++)
        {
            minDiff = min(minDiff, arr[i + 1] - arr[i]);
        }
        for(int i = 0; i < arr.size() - 1; i++)
        {
            if(arr[i + 1] - arr[i] == minDiff)
            {
                res.push_back({arr[i], arr[i + 1]});
            }
        }
        return res;
    }
};