class Solution:
    def countMentions(self, numberOfUsers: int, events: List[List[str]]) -> List[int]:
        res = [0 for _ in range(numberOfUsers)]
        online = set(range(numberOfUsers))
        offline = deque()
        events = sorted(events, key=lambda event: (int(event[1]), [-ord(c) for c in event[0]]))
        for event in events:
            print(offline)
            while len(offline) > 0 and int(event[1]) >= offline[0][1]:
                online.add(offline[0][0])
                offline.popleft()
            if event[0] == 'MESSAGE':
                if event[2] == 'ALL':
                    for i in range(len(res)):
                        res[i] += 1
                elif event[2] == 'HERE':
                    for c in online:
                        res[c] += 1
                else:
                    ids = event[2].split(' id')
                    ids[0] = ids[0][2:]
                    for i in ids:
                        res[int(i)] += 1
            else:
                offline.append((int(event[2]), int(event[1]) + 60))
                online.remove(int(event[2]))
        return res
