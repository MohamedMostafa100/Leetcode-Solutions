class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int res = 0;
        int start = 0;
        int violation = false;
        vector<bool> sorted(strs.size() - 1, false);
        int unSorted = strs.size() - 1;
        for (int i = 0; i < strs[0].length() && unSorted > 0; i++) {
            violation = false;
            for (int j = 1; j < strs.size(); j++) {
                if (!sorted[j - 1] && strs[j][i] < strs[j - 1][i]) {
                    res++;
                    violation = true;
                    break;
                }
            }
            if(!violation)
            {
                for(int j = 1; j < strs.size(); j++)
                {
                    if(!sorted[j - 1] && strs[j][i] > strs[j - 1][i])
                    {
                        sorted[j - 1] = true;
                        unSorted--;
                    }
                }
            }
        }
        return res;
    }
};