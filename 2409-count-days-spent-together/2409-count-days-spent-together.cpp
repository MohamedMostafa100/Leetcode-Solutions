class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int res = 0;
        vector<int> monthDays = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
        int aliceStart = monthDays[stoi(arriveAlice.substr(0, 2)) - 1] + stoi(arriveAlice.substr(3, 2));
        int aliceEnd = monthDays[stoi(leaveAlice.substr(0, 2)) - 1] + stoi(leaveAlice.substr(3, 2));
        int bobStart = monthDays[stoi(arriveBob.substr(0, 2)) - 1] + stoi(arriveBob.substr(3, 2));
        int bobEnd = monthDays[stoi(leaveBob.substr(0, 2)) - 1] + stoi(leaveBob.substr(3, 2));
        res =  min(aliceEnd, bobEnd) - max(aliceStart, bobStart);
        return res >= 0 ? res + 1 : 0;
    }
};