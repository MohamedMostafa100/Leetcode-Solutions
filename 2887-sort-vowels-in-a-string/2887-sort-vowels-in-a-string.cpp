class Solution {
public:
    string sortVowels(string s) {
        string t = "";
        string sortedVowels = "AEIOUaeiou";
        unordered_map<char, int> vowels = {{'A', 0}, {'E', 0}, {'I', 0}, {'O', 0}, {'U', 0}, {'a', 0}, {'e', 0}, {'i', 0}, {'o', 0}, {'u', 0}};
        for(int i = 0; i < s.length(); i++)
        {
            if(vowels.find(s[i]) != vowels.end())
            {
                vowels[s[i]]++;
            }
        }
        for(int i = 0; i < s.length(); i++)
        {
            if(vowels.find(s[i]) != vowels.end())
            {
                for(int j = 0; j < sortedVowels.length(); j++)
                {
                    if(vowels[sortedVowels[j]] > 0)
                    {
                        t += sortedVowels[j];
                        vowels[sortedVowels[j]]--;
                        break;
                    }
                }
                continue;
            }
            t += s[i];
        }
        return t;
    }
};