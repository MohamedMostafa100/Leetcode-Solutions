class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res = {arr[0]};
        unordered_set<int> curOrs = {arr[0]};
        for(int i = 1; i < arr.size(); i++)
        {
            unordered_set<int> nextOrs;
            nextOrs.insert(arr[i]);
            for(auto j : curOrs)
            {
                nextOrs.insert(arr[i] | j);
            }
            res.insert(nextOrs.begin(), nextOrs.end());
            curOrs = nextOrs;
        }
        return res.size();
    }
};