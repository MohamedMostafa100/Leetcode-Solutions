class Router {
public:
    Router(int memoryLimit) : memoryLimit(memoryLimit) {
        
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        string packet = to_string(source) + "*" + to_string(destination) + "*" + to_string(timestamp);
        if(packetHash.find(packet) != packetHash.end())
        {
            return false;
        }
        if(packets.size() == memoryLimit)
        {
            int d = packets.front();
            packets.pop();
            int s = dests[d].front().second;
            int ts = dests[d].front().first;
            dests[d].pop_front();
            string p = to_string(s) + "*" + to_string(d) + "*" + to_string(ts);
            packetHash.erase(p);
        }
        dests[destination].push_back({timestamp, source});
        packets.push(destination);
        packetHash.insert(packet);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(packets.empty())
        {
            return {};
        }
        int destination = packets.front();
        packets.pop();
        int source = dests[destination].front().second;
        int timestamp = dests[destination].front().first;
        dests[destination].pop_front();
        string packet = to_string(source) + "*" + to_string(destination) + "*" + to_string(timestamp);
        packetHash.erase(packet);
        return {source, destination, timestamp};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        int l1 = 0;
        int r1 = dests[destination].size();
        while(l1 < r1)
        {
            int m = (l1 + r1) / 2;
            if(dests[destination][m].first < startTime)
            {
                l1 = m + 1;
            }
            else
            {
                r1 = m;
            }
        }
        if(r1 == dests[destination].size() || dests[destination][r1].first > endTime)
        {
            return 0;
        }
        int l2 = 0;
        int r2 = dests[destination].size();
        while(l2 < r2)
        {
            int m = (l2 + r2 + 1) / 2;
            if(m < dests[destination].size() && dests[destination][m].first <= endTime)
            {
                l2 = m;
            }
            else
            {
                r2 = m - 1;
            }
        }
        return r2 - r1 + 1;
    }
private:
    int memoryLimit;
    unordered_set<string> packetHash;
    queue<int> packets;
    unordered_map<int, deque<pair<int, int>>> dests;
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */