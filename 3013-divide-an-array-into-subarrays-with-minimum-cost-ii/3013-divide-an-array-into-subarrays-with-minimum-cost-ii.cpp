class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        long long res = LLONG_MAX;
        int n = nums.size();
        int l = 2;
        int r = 2;
        multiset<int> window;
        multiset<int> smallest;
        long long windowSum = nums[l];
        smallest.insert(nums[l]);
        for(int i = 1; i < n - k + 2; i++)
        { 
            while(r - l + 1 < min(dist, n - i - 1))
            {
                r++;
                if(smallest.size() < k - 2)
                {
                    smallest.insert(nums[r]);
                    windowSum += nums[r];
                }
                else
                {
                    auto lastEle = next(smallest.end(), -1);
                    if(nums[r] < *lastEle)
                    {
                        windowSum += -*lastEle + nums[r];
                        window.insert(*lastEle);
                        smallest.erase(lastEle);
                        smallest.insert(nums[r]);
                    }
                    else
                    {
                        window.insert(nums[r]);
                    }
                }
            }
            res = min(res, nums[0] + nums[i] + windowSum);
            if(smallest.find(nums[l]) != smallest.end())
            {
                smallest.erase(smallest.find(nums[l]));
                windowSum -= nums[l];
                if(!window.empty())
                {
                    smallest.insert(*(window.begin()));
                    windowSum += *(window.begin());
                    window.erase(window.begin());
                }
            }
            else
            {
                window.erase(window.find(nums[l]));
            }
            l++;
        }
        return res;
    }
};