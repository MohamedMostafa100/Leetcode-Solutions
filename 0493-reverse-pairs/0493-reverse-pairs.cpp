class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return divide(nums, 0, nums.size() - 1);
    }
private:
    int merge(vector<int>& nums, int l, int mid, int r)
    {
        int res = 0;
        vector<long long> a;
        vector<long long> b;
        for(int i = l; i <= mid; i++)
        {
            a.push_back(nums[i]);
        }
        for(int i = mid + 1; i <= r; i++)
        {
            b.push_back(nums[i]);
        }
        int aSize = a.size();
        int aPointer = 0;
        int bSize = b.size();
        int bPointer = 0;
        while(aPointer < aSize && bPointer < bSize)
        {
            if(a[aPointer] > b[bPointer] * 2)
            {
                res += aSize - aPointer;
                bPointer++;
            }
            else
            {
                aPointer++;
            }
        }
        aPointer = 0;
        bPointer = 0;
        for(int i = l; i <= r; i++)
        {
            if(bPointer == bSize || (aPointer < aSize && a[aPointer] <= b[bPointer]))
            {
                nums[i] = a[aPointer];
                aPointer++;
            }
            else
            {
                nums[i] = b[bPointer];
                bPointer++;
            }
        }
        return res;
    }
    int divide(vector<int>& nums, int l, int r)
    {
        if(l == r)
        {
            return 0;
        }
        int res = 0;
        int mid = (l + r) / 2;
        res += divide(nums, l, mid);
        res += divide(nums, mid + 1, r);
        res += merge(nums, l, mid, r);
        return res;
    }
};