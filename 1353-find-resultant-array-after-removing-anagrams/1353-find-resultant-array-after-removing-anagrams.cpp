class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        string last = words[0];
        sort(words[0].begin(), words[0].end());
        string cur;
        for(int i = 1; i < words.size(); i++)
        {
            cur = words[i];
            sort(words[i].begin(), words[i].end());
            if(words[i] != words[i - 1])
            {
                res.push_back(last);
                last = cur;
            }
        }
        res.push_back(last);
        return res;
    }
private:
    
};