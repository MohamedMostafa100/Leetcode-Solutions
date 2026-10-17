class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> idxs;
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end(), [&](int& a, int& b){
            int sumA = sumDigits(a);
            int sumB = sumDigits(b);
            if(sumA < sumB)
            {
                return true;
            }
            else if(sumA > sumB)
            {
                return false;
            }
            return a < b;
        });
        for(int i = 0; i < nums.size(); i++)
        {
            idxs[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++)
        {

            if(nums[i] != sortedNums[i])
            {
                res++;
                int temp = nums[i];
                swap(nums[i], nums[idxs[sortedNums[i]]]);
                idxs[temp] = idxs[sortedNums[i]];
            }
        }
        return res;
    }
private:
    int sumDigits(int x)
    {
        int res = 0;
        while(x > 0)
        {
            res += x % 10;
            x /= 10;
        }
        return res;
    }
};