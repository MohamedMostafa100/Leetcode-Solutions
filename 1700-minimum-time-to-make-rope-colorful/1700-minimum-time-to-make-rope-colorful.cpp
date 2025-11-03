class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res = 0;
        int sum = neededTime[0];
        int maxNum = neededTime[0];
        for(int i = 1; i < colors.length(); i++)
        {   
            if(colors[i] == colors[i - 1])
            {
                sum += neededTime[i];
                maxNum = max(maxNum, neededTime[i]);
            }
            else
            {
                res += sum - maxNum;
                sum = neededTime[i];
                maxNum = neededTime[i];
            }
        }
        res += sum - maxNum;
        return res;
    }
};