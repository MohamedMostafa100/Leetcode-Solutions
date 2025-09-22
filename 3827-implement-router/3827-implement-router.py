class Router:

    def __init__(self, memoryLimit: int):
        self.memoryLimit = memoryLimit
        self.packetHash = set()
        self.packets = deque()
        self.dests = {} 

    def addPacket(self, source: int, destination: int, timestamp: int) -> bool:
        packet = f"{source}*{destination}*{timestamp}"
        if packet in self.packetHash:
            return False
        if len(self.packets) == self.memoryLimit:
            d = self.packets.popleft()
            ts, s = self.dests[d].popleft()          
            p = f"{s}*{d}*{ts}"
            self.packetHash.remove(p)
        if destination not in self.dests:
            self.dests[destination] = deque()
        self.dests[destination].append((timestamp, source))
        self.packets.append(destination)
        self.packetHash.add(packet)
        return True
        
    def forwardPacket(self) -> List[int]:
        if len(self.packets) == 0:
            return []
        destination = self.packets.popleft()
        timestamp, source = self.dests[destination].popleft()
        packet = f"{source}*{destination}*{timestamp}"
        self.packetHash.remove(packet)
        return [source, destination, timestamp]

    def getCount(self, destination: int, startTime: int, endTime: int) -> int:
        if destination not in self.dests:
            return 0
        l1 = 0
        r1 = len(self.dests[destination])
        while l1 < r1:
            m = (l1 + r1) // 2
            if self.dests[destination][m][0] < startTime:
                l1 = m + 1
            else:
                r1 = m
        if r1 == len(self.dests[destination]) or self.dests[destination][r1][0] > endTime:
            return 0
        l2 = 0
        r2 = len(self.dests[destination])
        while l2 < r2:
            m = (l2 + r2 + 1) // 2
            if m < len(self.dests[destination]) and self.dests[destination][m][0] <= endTime:
                l2 = m
            else:
                r2 = m - 1
        return r2 - r1 + 1
        


# Your Router object will be instantiated and called as such:
# obj = Router(memoryLimit)
# param_1 = obj.addPacket(source,destination,timestamp)
# param_2 = obj.forwardPacket()
# param_3 = obj.getCount(destination,startTime,endTime)