class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int res = 0;
        unordered_set<int> pres;
        for(int i = 0; i < arr1.size(); i++)
        {
            int a = arr1[i];
            while(!pres.count(a) && a > 0)
            {
                pres.insert(a);
                a /= 10;
            }
        }
        for(int i = 0; i < arr2.size(); i++)
        {
            int b = arr2[i];
            while(b > 0)
            {
                if(pres.count(b))
                {
                    res = max(res, (int)to_string(b).length());
                    break;
                }
                b /= 10;
            }
        }
        return res;
    }
};