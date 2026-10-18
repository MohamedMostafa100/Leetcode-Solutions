#define MOD 1000000007
class Solution {
public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> comb(n + 1, vector<long long>(n + 1, 0));
        for(int i = 0; i < n + 1; i++)
        {
            comb[i][0] = 1;
            for(int j = 1; j < i + 1; j++)
            {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }
        return solve(nums, comb) - 1;
    }
private:
    int solve(vector<int>& nums, vector<vector<long long>>& comb)
    {
        if(nums.size() <= 2)
        {
            return 1;
        }
        vector<int> left;
        vector<int> right;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] < nums[0])
            {
                left.push_back(nums[i]);
            }
            else
            {
                right.push_back(nums[i]);
            }
        }
        int n = nums.size();
        int l = left.size();
        return (((comb[n - 1][l] * solve(left, comb)) % MOD) * solve(right, comb)) % MOD;
    }
};