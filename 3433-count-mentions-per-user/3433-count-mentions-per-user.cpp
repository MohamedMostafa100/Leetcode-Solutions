class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> res(numberOfUsers, 0);
        unordered_set<int> online;
        queue<pair<int, int>> offline;
        int allEvents = 0;
        sort(events.begin(), events.end(), [](vector<string>& a, vector<string>& b){
            if(stoi(a[1]) < stoi(b[1]))
            {
                return true;
            }
            else if(stoi(a[1]) == stoi(b[1]) && a[0] == "OFFLINE")
            {
                return true;
            }
            return false;
        });
        for(int i = 0; i < numberOfUsers; i++)
        {
            online.insert(i);
        }
        for(int i = 0; i < events.size(); i++)
        {
            while(!offline.empty() && stoi(events[i][1]) >= offline.front().second)
            {
                online.insert(offline.front().first);
                offline.pop();
            }
            if(events[i][0] == "MESSAGE")
            {
                if(events[i][2] == "ALL")
                {
                    for(int j = 0; j < res.size(); j++)
                    {
                        res[j]++;
                    }
                }
                else if(events[i][2] == "HERE")
                {
                    for(auto& it : online)
                    {
                        res[it]++;
                    }
                }
                else
                {
                    for(int j = 0; j < events[i][2].length(); j++)
                    {
                        string id = "";
                        while(j < events[i][2].length() && events[i][2][j] != ' ')
                        {
                            if(events[i][2][j] != 'i' && events[i][2][j] != 'd')
                            {
                                id += events[i][2][j];
                            }
                            j++;
                        }
                        res[stoi(id)]++;
                    }
                }
            }
            else
            {
                offline.push({stoi(events[i][2]), stoi(events[i][1]) + 60});
                online.erase(stoi(events[i][2]));
            }
        }
        return res;
    }
};