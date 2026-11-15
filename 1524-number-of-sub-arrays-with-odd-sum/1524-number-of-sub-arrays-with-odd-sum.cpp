#define MOD 1000000007  
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long res = 0;
        int odd = 0;
        int even = 0;
        int cur = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            cur += arr[i];
            if(cur & 1)
            {
                res++;
                if(i > 0)
                {
                    odd++;
                }
            }
            else if(i > 0)
            {
                even++;
            }
        }
        for(int i = 1; i < arr.size(); i++)
        {
            if(arr[i - 1] & 1)
            {
                int temp = even;
                even = odd;
                odd = temp;
            }
            res = (res + odd) % MOD;
            if(arr[i] & 1)
            {
                odd--;
            }
            else
            {
                even--;
            }
        }
        return res;
    }
};