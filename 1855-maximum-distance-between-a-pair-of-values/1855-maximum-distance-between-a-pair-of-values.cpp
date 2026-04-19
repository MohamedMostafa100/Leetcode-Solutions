class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        int i = nums1.size() - 1;
        int j = nums2.size() - 1;
        while(i >= 0 && j >= 0)
        {
            if(nums1[i] <= nums2[j])
            {
                res = max(res, j - i);
                i--;
            }
            else
            {
                j--;
            }
        }
        return res;
    }
};