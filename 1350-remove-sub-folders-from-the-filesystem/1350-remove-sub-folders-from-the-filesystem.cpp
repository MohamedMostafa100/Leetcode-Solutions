class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> res;
        unordered_set<string> paths(folder.begin(), folder.end());
        for(int i = 0; i < folder.size(); i++)
        {
            string s = "";
            for(int j = 1; j < folder[i].length(); j++)
            {
                s += '/';
                while(folder[i][j] != '/' && j < folder[i].length())
                {
                    s += folder[i][j];
                    j++;
                }
                if(paths.find(s) != paths.end() && s.length() != folder[i].length())
                {
                    paths.erase(folder[i]);
                    break;
                }
            }
        }
        res.assign(paths.begin(), paths.end());
        return res;
    }
};