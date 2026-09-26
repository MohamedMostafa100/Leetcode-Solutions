class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string res = "";
        unordered_map<string, string> wordMap;
        for(int i = 0; i < knowledge.size(); i++)
        {
            wordMap[knowledge[i][0]] = knowledge[i][1];
        }
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
            {
                string word = "";
                i++;
                while(s[i] != ')')
                {
                    word += s[i];
                    i++;
                }
                if(wordMap.count(word))
                {
                    res += wordMap[word];
                }
                else
                {
                    res += '?';
                }
            }
            else
            {
                res += s[i];
            }
        }
        return res;
    }
};