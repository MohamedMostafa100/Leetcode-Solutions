class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> stk;
        vector<int> res(temperatures.size());
        for(int i = 0; i < temperatures.size(); i++)
        {
            while(!stk.empty() && temperatures[i] > stk.top().first)
            {
                res[stk.top().second] = i - stk.top().second;
                stk.pop();
            }
            stk.push(make_pair(temperatures[i], i));
        }
        while(!stk.empty())
        {
            res[stk.top().second] = 0;
            stk.pop();
        }
        return res;
    }
};
