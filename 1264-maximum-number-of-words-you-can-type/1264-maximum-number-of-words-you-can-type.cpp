class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int res = 0;
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
        for(int i = 0; i < text.size(); i++)
        {
            bool flag = true;
            while(i < text.size() && text[i] != ' ')
            {
                if(broken.find(text[i]) != broken.end())
                {
                    flag = false;
                }
                i++;
            }
            if(flag)
            {
                res += 1;
            }    
        }
        return res;
    }
};