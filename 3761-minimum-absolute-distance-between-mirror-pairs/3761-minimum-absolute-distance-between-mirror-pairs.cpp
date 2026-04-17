class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int res = n;
        unordered_map<int, int> pos;
        pos[nums[n - 1]] = n - 1;
        for(int i = n - 2; i >= 0; i--)
        {
            int rev = reverse(nums[i]);
            cout << rev << endl;
            if(pos.count(rev))
            {
                res = min(res, pos[rev] - i);
            }
            pos[nums[i]] = i;
        }
        return res == n ? -1 : res;
    }
private:
    int reverse(int x)
    {
        int res = 0;
        while(x > 0)
        {
            res = res * 10 + (x % 10);
            x /= 10;
        }
        return res;
    }
};