class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int res = n;
        for(int i = 0; i < n; i++)
        {
            if(words[i] == target)
            {
                res = min({res, abs(i - startIndex), i + n - startIndex, startIndex + n - i});
            }
        }
        return res == n ? -1 : res;
    }
};