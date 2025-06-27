class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        string res = "";
        int alpha[26] = {0};

        for (int i = 0; i < s.length(); i++) {
            alpha[s[i] - 'a']++;
        }

        vector<char> cand;
        queue<string> q;
        for (int i = 25; i >= 0; i--) {
            if (alpha[i] >= k) {
                cand.push_back('a' + i);
                string t = "";
                t += cand[cand.size() - 1];
                q.push(t);
            }
        }

        while(!q.empty())
        {
            string curr = q.front();
            q.pop();

            if(curr.length() > res.length())
            {
                res = curr;
            }

            for(int i = 0; i < cand.size(); i++)
            {
                if(count(s, curr + cand[i], k))
                {
                    q.push(curr + cand[i]);
                }
            }
        }

        return res;
    }

private:
    bool count(string& s, string t, int k) {
        int idx = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == t[idx]) {
                idx++;
                if (idx == t.length()) {
                    idx = 0;
                    k--;
                    if (k == 0) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};