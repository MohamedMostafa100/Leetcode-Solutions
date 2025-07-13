class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int res = 0;
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int j = trainers.size() - 1;
        for(int i = players.size() - 1; i >= 0; i--)
        {
            if(trainers[j] >= players[i])
            {
                j--;
                res++;
                if(j < 0)
                {
                    break;
                }
            }
        }

        return res;
    }
};