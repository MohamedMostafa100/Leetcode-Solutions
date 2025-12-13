class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string> res;
        vector<pair<string, string>> resPairs;
        unordered_set<string> lines = {"electronics", "grocery", "pharmacy", "restaurant"};
        for(int i = 0; i < code.size(); i++)
        {
            if(nonSpecial(code[i]) && lines.count(businessLine[i]) && isActive[i])
            {
                resPairs.push_back({businessLine[i], code[i]});
            }
        }
        sort(resPairs.begin(), resPairs.end());
        for(int i = 0; i < resPairs.size(); i++)
        {
            res.push_back(resPairs[i].second);
        }
        return res;
    }
private:
    bool nonSpecial(string& s)
    {
        if(s.empty())
        {
            return false;
        }
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] != '_' && !(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= 'A' && s[i] <= 'Z') && !(s[i] >= '0' && s[i] <= '9'))
            {
                return false;
            }
        }
        return true;
    }
};