class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> found;
        unordered_set<char> uniq;
        for(auto ch : word)
        {
            if(ch >= 'A' && ch <= 'Z')
            {
                char lower = ch + 32;
                if(found.count(lower) && !found.count(ch))
                {
                    uniq.insert(ch);
                }
            }
            else
            {
                char upper = ch - 32;
                if(found.count(ch) && found.count(upper))
                {
                    if(uniq.count(upper))
                    {
                        uniq.erase(upper);
                    }
                }
            }
            found.insert(ch);
        }
        return uniq.size();
    }
};