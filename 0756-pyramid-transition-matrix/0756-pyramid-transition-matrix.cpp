class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> pattern;
        unordered_set<string> visited;
        for(int i = 0; i < allowed.size(); i++)
        {
            pattern[allowed[i].substr(0, 2)].push_back(allowed[i][2]);
        }
        return solve(bottom, "", pattern, "", visited, 0);
    }
private:
    bool solve(string bottom, string top, unordered_map<string, vector<char>>& pattern, string curStr, unordered_set<string>& visited, int i)
    {
        if(bottom.length() == 1)
        {
            return true;
        }
        if(visited.find(curStr) != visited.end())
        {
            return false;
        }
        if(i == bottom.length() - 1)
        {
            if(solve(top, "", pattern, "", visited, 0))
            {
                return true;
            }
            return false;
        }
        string block = bottom.substr(i, 2);
        if(pattern.find(block) != pattern.end())
        {
            for(int idx = 0; idx < pattern[block].size(); idx++)
            {
                top += pattern[block][idx];
                if(solve(bottom, top, pattern, curStr + pattern[block][idx], visited, i + 1))
                {
                    return true;
                }
                top.pop_back();
            }
        }
        visited.insert(bottom);
        return false;
    }
};