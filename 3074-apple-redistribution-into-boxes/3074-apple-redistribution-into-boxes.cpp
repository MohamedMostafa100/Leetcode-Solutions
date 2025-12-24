class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int res = 0;
        int tot = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.begin(), capacity.end(), greater<int>());
        for(int i = 0; i < capacity.size(); i++)
        {
            res++;
            if(tot - capacity[i] <= 0)
            {
                break;
            }
            tot -= capacity[i];
        }
        return res;
    }
};