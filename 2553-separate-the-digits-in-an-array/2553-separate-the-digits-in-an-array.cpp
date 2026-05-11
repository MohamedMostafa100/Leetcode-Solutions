class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            vector<int> seperated = sep(nums[i]);
            for(int j = seperated.size() - 1; j >= 0; j--)
            {
                res.push_back(seperated[j]);
            }
        }
        return res;
    }
private:
    vector<int> sep(int x)
    {
        vector<int> res;
        while(x > 0)
        {
            res.push_back(x % 10);
            x /= 10;
        }
        return res;
    }
};