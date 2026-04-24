class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left = 0;
        int right = 0;
        int joker = 0;
        for(int i = 0; i < moves.size(); i++)
        {
            if(moves[i] == 'R')
            {
                right++;
            }
            else if(moves[i] == 'L')
            {
                left++;
            }
            else
            {
                joker++;
            }
        }
        return abs(right - left) + joker;
    }
};