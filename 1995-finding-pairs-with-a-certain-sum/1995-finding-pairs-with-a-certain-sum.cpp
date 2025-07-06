class FindSumPairs {
private:
    unordered_map<int, int> mp;
    vector<int>& nums1;
    vector<int>& nums2;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) : nums1(nums1), nums2(nums2) {
        for(int i = 0; i < this->nums2.size(); i++)
        {
            mp[this->nums2[i]]++;
        }
    }
    
    void add(int index, int val) {
        mp[nums2[index]]--;
        if(mp[nums2[index]] == 0)
        {
            mp.erase(nums2[index]);
        }
        nums2[index] += val;
        mp[nums2[index]]++;
    }
    
    int count(int tot) {
        int res = 0;
        for(int i = 0; i < nums1.size(); i++)
        {
            if(mp.find(tot - nums1[i]) != mp.end())
            {
                res += mp[tot - nums1[i]];
            }
        }

        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */