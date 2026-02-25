class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> res;
        vector<vector<int>> bitsBuck(16);
        sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size(); i++)
        {
            bitsBuck[__builtin_popcount(arr[i])].push_back(arr[i]);
        }
        for(int i = 0; i < bitsBuck.size(); i++)
        {
            res.insert(res.end(), bitsBuck[i].begin(), bitsBuck[i].end());
        }
        return res;
    }
};