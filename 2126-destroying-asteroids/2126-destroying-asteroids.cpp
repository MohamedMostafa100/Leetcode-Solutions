class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long curMass = mass;
        sort(asteroids.begin(), asteroids.end());
        for(int i = 0; i < asteroids.size(); i++)
        {
            if(curMass < asteroids[i])
            {
                return false;
            }
            curMass += asteroids[i];
        }
        return true;
    }
};