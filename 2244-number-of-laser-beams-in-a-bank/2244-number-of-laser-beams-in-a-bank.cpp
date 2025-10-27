class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int res = 0;
        int prev = 0;
        for(int i = 0; i < bank.size(); i++)
        {
            int curr = 0;
            for(int j = 0; j < bank[i].length(); j++)
            {
                if(bank[i][j] == '1')
                {
                    curr++;
                }
            }
            res += prev * curr;
            prev = curr > 0 ? curr : prev;
        }
        return res;
    }
};