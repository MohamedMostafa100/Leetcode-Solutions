class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int rank = 1;
        vector<pair<int, int>> nums;
        for(int i = 0; i < arr.size(); i++)
        {
            nums.push_back({arr[i], i});
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            if(i > 0 && nums[i].first > nums[i - 1].first)
            {
                rank++;
            }
            arr[nums[i].second] = rank;
        }
        return arr;
    }
};