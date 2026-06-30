class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0;
        int l = 0;
        int chars[3];
        int charCount = 0;
        for(int r = 0; r < s.length(); r++)
        {
            chars[s[r] - 'a']++;
            if(chars[s[r] - 'a'] == 1)
            {
                charCount++;
            }
            while(charCount == 3)
            {
                res += (s.length() - r);
                chars[s[l] - 'a']--;
                if(chars[s[l] - 'a'] == 0)
                {
                    charCount--;
                }
                l++;
            }
        }
        return res;
    }
};