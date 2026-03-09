class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string res = "";
        unordered_set<string> found(nums.begin(), nums.end());
        solve("", nums[0].length(), found, res);
        return res;
    }
private:
    bool solve(string cur, int n, unordered_set<string>& found, string& res)
    {
        if(cur.length() == n)
        {
            if(!found.count(cur))
            {
                res = cur;
                return true;
            }
            return false;
        }
        return solve(cur + '0', n, found, res) || solve(cur + '1', n, found, res);
    }
};