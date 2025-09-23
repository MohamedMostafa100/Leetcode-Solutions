class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0;
        int j = 0;
        while(i < version1.size() || j < version2.size())
        {
            string cur1 = "";
            string cur2 = "";
            if(i < version1.size())
            {
                while(version1[i] != '.' && i < version1.size())
                {
                    cur1 += version1[i];
                    i++;
                }
                i++;
            }
            else
            {
                cur1 += '0';
            }
            if(j < version2.size())
            {
                while(version2[j] != '.' && j < version2.size())
                {
                    cur2 += version2[j];
                    j++;
                }
                j++;
            }
            else
            {
                cur2 += '0';
            }
            if(stoi(cur1) > stoi(cur2))
            {
                return 1;
            }
            else if(stoi(cur1) < stoi(cur2))
            {
                return -1;
            }
        }
        return 0;
    }
};