class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        vector<int> top;
        vector<int> bottom;
        int mx = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            mx = max(mx, nums[i]);
            insertTop(top, nums[i]);
            insertBottom(bottom, nums[i]);
        }
        return max(top[0] * top[1] * top[2], bottom[0] * bottom[1] * mx);
    }

private:
    void insertBottom(vector<int>& arr, int val) {
        if (arr.size() < 2) {
            arr.push_back(val);
            return;
        }
        int mx = arr[0];
        int maxI = 0;
        if(arr[1] > mx)
        {
            mx = arr[1];
            maxI = 1;
        }
        if(val < mx)
        {
            arr[maxI] = val;
        }
    }
    void insertTop(vector<int>& arr, int val) {
        if (arr.size() < 3) {
            arr.push_back(val);
            return;
        }
        int mn = arr[0];
        int minI = 0;
        if (arr[1] < mn) {
            mn = arr[1];
            minI = 1;
        } if (arr[2] < mn) {
            mn = arr[2];
            minI = 2;
        }
        if(val > mn)
        {
            arr[minI] = val;
        }
    }
};