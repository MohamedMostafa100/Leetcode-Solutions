class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> res;
        for(int i = 0; i < queries.size(); i++)
        {
            for(int j = 0; j < dictionary.size(); j++)
            {
                if(checkDist(queries[i], dictionary[j]))
                {
                    res.push_back(queries[i]);
                    break;
                }
            }
        }
        return res;
    }
public:
    bool checkDist(string& s, string& t)
    {
        char dist = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] != t[i])
            {
                dist++;
            }
            if(dist > 2)
            {
                return false;
            }
        }
        return true;
    }
};