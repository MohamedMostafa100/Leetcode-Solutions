class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long res = 0;
        int sub = 0;
        sort(happiness.begin(), happiness.end(), greater<int>());
        for(int i = 0; i < happiness.size(); i++)
        {
            if(k == 0 || happiness[i] - sub <= 0)
            {
                break;
            }
            res += happiness[i] - sub;
            k--;
            sub++;
        }
        return res;
    }
};