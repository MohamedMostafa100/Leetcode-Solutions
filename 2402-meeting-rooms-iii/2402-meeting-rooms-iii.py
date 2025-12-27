class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        res = 0
        numUsed = 0
        freqs = {i:0 for i in range(n)}
        finishTimes = []
        availableRooms = [i for i in range(n)]
        meetings = sorted(meetings)
        for m in meetings:
            while len(finishTimes) > 0 and m[0] >= finishTimes[0][0]:
                heapq.heappush(availableRooms, finishTimes[0][1])
                heapq.heappop(finishTimes)
            if len(availableRooms) == 0:
                lastMeeting = finishTimes[0]
                heapq.heappop(finishTimes)
                heapq.heappush(finishTimes, (m[1] + lastMeeting[0] - m[0], lastMeeting[1]))
                freqs[lastMeeting[1]] += 1
                roomUsed = lastMeeting[1]
                usedRoomFreq = freqs[lastMeeting[1]]
            else:
                heapq.heappush(finishTimes, (m[1], availableRooms[0]))
                freqs[availableRooms[0]] += 1
                roomUsed = availableRooms[0]
                usedRoomFreq = freqs[availableRooms[0]]
                heapq.heappop(availableRooms)
            if usedRoomFreq > numUsed:
                res = roomUsed
                numUsed = usedRoomFreq
            elif usedRoomFreq == numUsed:
                res = min(res, roomUsed)
        return res

