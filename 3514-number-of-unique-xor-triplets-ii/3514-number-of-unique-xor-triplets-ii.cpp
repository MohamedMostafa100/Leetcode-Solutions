class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> doubles, triples;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < nums.size(); j++)
            {
                doubles.insert(nums[i] ^ nums[j]);
            }
        }
        for(auto val : doubles)
        {
            for(int i = 0; i < nums.size(); i++)
            {
                triples.insert(val ^ nums[i]);
            }
        }
        return triples.size();
    }
};