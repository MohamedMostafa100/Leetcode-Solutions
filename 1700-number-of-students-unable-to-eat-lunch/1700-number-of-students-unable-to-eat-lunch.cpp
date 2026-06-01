class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q(students.begin(), students.end());
        for(int i = 0; i < sandwiches.size(); i++)
        {
            int count = 0;
            while(q.front() != sandwiches[i])
            {
                count++;
                if(count == q.size())
                {
                    return q.size();
                }
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }
        return 0;
    }
};