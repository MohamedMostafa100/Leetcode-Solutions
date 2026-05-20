class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> res;    
        int commCount = 0;
        vector<char> seen(A.size(), 0);
        for(int i = 0; i < A.size(); i++)
        {
            seen[A[i] - 1]++;
            if(seen[A[i] - 1] == 2)
            {
                commCount++;
            }
            seen[B[i] - 1]++;
            if(seen[B[i] - 1] == 2)
            {
                commCount++;
            }
            res.push_back(commCount);
        }
        return res;
    }
};