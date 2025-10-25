class Solution {
public:
    int nextBeautifulNumber(int n) {
        vector<int> freq(10, 0);
        vector<int> nums;
        generate(freq, nums, 0);
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums.size();
        while(l < r)
        {
            int mid = (l + r) / 2;
            if(nums[mid] > n)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return nums[l];
    }
private:
    void generate(vector<int>& freq, vector<int>& nums, int n)
    {
        if(n > 1224444)
        {
            return;
        }
        for(int i = 1; i <= 7; i++)
        {
            if(freq[i] < i)
            {
                int num = n * 10 + i;
                freq[i]++;
                if(checkBalanced(freq) && num != 0)
                {
                    nums.push_back(num);
                }
                generate(freq, nums, num);
                freq[i]--;
            }
        }
    }
    bool checkBalanced(vector<int>& freq)
    {
        for(int i = 1; i <= 7; i++)
        {
            if(freq[i] != 0 && freq[i] != i)
            {
                return false;
            }
        }
        return true;
    }
};