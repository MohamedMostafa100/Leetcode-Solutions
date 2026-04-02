class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<int> res;
        vector<vector<int>> robots;
        stack<vector<int>> stk;
        for(int i = 0; i < positions.size(); i++)
        {
            robots.push_back({positions[i], healths[i], directions[i] == 'R' ? 0 : 1, i});
        }
        sort(robots.begin(), robots.end());
        for(int i = 0; i < robots.size(); i++)
        {
            if(robots[i][2] == 0)
            {
                stk.push(robots[i]);
            }
            else
            {
                while(!stk.empty() && stk.top()[2] == 0 && stk.top()[1] < robots[i][1])
                {
                    healths[stk.top()[3]] = 0;
                    healths[robots[i][3]]--;
                    robots[i][1]--;
                    stk.pop();
                }
                if(stk.empty() || stk.top()[2] == 1)
                {
                    stk.push(robots[i]);
                }
                else if(stk.top()[1] > robots[i][1])
                {
                    stk.top()[1]--;
                    healths[stk.top()[3]]--;
                    healths[robots[i][3]] = 0;
                }
                else
                {
                    healths[stk.top()[3]] = 0;
                    healths[robots[i][3]] = 0;
                    stk.pop();
                }
            }
        }
        for(int i = 0; i < healths.size(); i++)
        {
            if(healths[i] > 0)
            {
                res.push_back(healths[i]);
            }
        }
        return res;
    } 
};