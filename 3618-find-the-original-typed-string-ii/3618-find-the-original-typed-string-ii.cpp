class Solution {
public:
    int possibleStringCount(string word, int k) {
        vector<int> freqs;
        int count = 1;
        long long total = 1;
        long long invalid = 0;
        for (int i = 1; i < word.length(); i++) {
            if (word[i] == word[i - 1]) {
                count++;
            } else {
                freqs.push_back(count);
                count = 1;
            }
        }
        freqs.push_back(count);

        for (int i = 0; i < freqs.size(); i++) {
            total = (total * freqs[i]) % 1000000007;
        }

        if (freqs.size() >= k) {
            return total;
        }

        vector<int> dp(k, 0);
        dp[0] = 1;

        for (int i = 0; i < freqs.size(); i++) {
            vector<int> new_dp(k, 0);
            long long sum = 0;
            for (int j = 0; j < k; j++) {
                if (j > 0) {
                    sum = (sum + dp[j - 1]) % 1000000007;
                }

                if (j > freqs[i]) {
                    sum =
                        (sum - dp[j - freqs[i] - 1] + 1000000007) % 1000000007;
                }
                new_dp[j] = sum;
            }

            dp = new_dp;
        }
        
        for(int i = 0; i < k; i++)
        {
            invalid = (invalid + dp[i]) % 1000000007;
        }

        return (total - invalid + 1000000007) % 1000000007;
    }
};