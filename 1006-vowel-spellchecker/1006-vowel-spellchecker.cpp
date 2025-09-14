class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exactMatch;
        unordered_map<string, string> capMatch;
        unordered_map<string, string> vowMatch;
        for(int i = 0; i < wordlist.size(); i++)
        {
            exactMatch.insert(wordlist[i]);
            string lowerStr = preCap(wordlist[i]);
            string constStr = preVow(lowerStr);
            if(capMatch.find(lowerStr) == capMatch.end())
            {
                capMatch[lowerStr] = wordlist[i];
            }
            if(vowMatch.find(constStr) == vowMatch.end())
            {
                vowMatch[constStr] = wordlist[i];
            }
        }
        for(int i = 0; i < queries.size(); i++)
        {
            string lowerStr = preCap(queries[i]);
            string constStr = preVow(lowerStr);
            if(exactMatch.find(queries[i]) != exactMatch.end())
            {
                continue;
            }
            else if(capMatch.find(lowerStr) != capMatch.end())
            {
                queries[i] = capMatch[lowerStr];
            }
            else if(vowMatch.find(constStr) != vowMatch.end())
            {
                queries[i] = vowMatch[constStr];
            }
            else
            {
                queries[i] = "";
            }
        }
        return queries;
    }
private:
    string preCap(string s)
    {
        string t = "";
        for(char i = 0; i < s.length(); i++)
        {
            t += tolower(s[i]);
        }
        return t;
    }
    string preVow(string s)
    {
        string t = "";
        for(char i = 0; i < s.length(); i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                t += '#';
            }
            else
            {
                t += s[i];
            }
        }
        return t;
    }
};