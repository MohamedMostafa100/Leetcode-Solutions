class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        return n >= 3 ? pow(2, (int)log2(n) + 1) : n;
    }
};