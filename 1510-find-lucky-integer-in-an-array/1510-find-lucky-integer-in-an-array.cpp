class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freqs;
        int res = -1;
        for(int i = 0; i < arr.size(); i++)
        {
            freqs[arr[i]]++;
        }

        for(auto it : freqs)
        {
            if(it.first == it.second)
            {
                res = max(res, it.first);
            }
        }

        return res;
    }
};