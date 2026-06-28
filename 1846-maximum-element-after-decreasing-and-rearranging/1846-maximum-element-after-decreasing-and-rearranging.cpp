class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int res = 0;
        sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[i] > res)
            {
                res++;
            }
        }
        return res;
    }
};