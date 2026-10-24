class Solution:
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
        res = 0
        monthDays = [0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334]
        aliceStart = monthDays[int(arriveAlice[:2]) - 1] + int(arriveAlice[3:])
        aliceEnd = monthDays[int(leaveAlice[:2]) - 1] + int(leaveAlice[3:])
        bobStart = monthDays[int(arriveBob[:2]) - 1] + int(arriveBob[3:])
        bobEnd = monthDays[int(leaveBob[:2]) - 1] + int(leaveBob[3:])
        res =  min(aliceEnd, bobEnd) - max(aliceStart, bobStart)
        return res + 1 if res >= 0 else 0