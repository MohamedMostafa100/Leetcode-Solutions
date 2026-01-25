class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int res = 0;
        int errs = 0;
        map<int, long long> arr;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;
        unordered_set<int> erroredIdxs;
        for (int i = 0; i < nums.size(); i++) {
            arr[i] = nums[i];
            if (i < nums.size() - 1) {
                pq.push({(long long)nums[i] + nums[i + 1], i});
            }
            if (i > 0 && nums[i] < nums[i - 1]) {
                erroredIdxs.insert(i - 1);
            }
        }
        while (!erroredIdxs.empty()) {
            res++;
            while (!pq.empty()) {
                int idx = pq.top().second;
                long long sum = pq.top().first;
                auto it = arr.find(idx);
                if (it == arr.end() || it == next(arr.end(), -1) ||
                    arr[idx] + arr[next(it, 1)->first] != sum) {
                    pq.pop();
                } else {
                    break;
                }
            }
            int idx = pq.top().second;
            long long sum = pq.top().first;
            pq.pop();
            auto it = arr.find(idx);
            int nextIdx = next(it, 1)->first;
            arr[idx] = sum;
            erroredIdxs.erase(idx);
            erroredIdxs.erase(nextIdx);
            arr.erase(nextIdx);
            if (it != next(arr.end(), -1)) {
                nextIdx = next(it, 1)->first;
                if (arr[idx] > arr[nextIdx]) {
                    erroredIdxs.insert(idx);
                }
                pq.push({arr[idx] + arr[nextIdx], idx});
            }
            if (it != arr.begin()) {
                int prevIdx = next(it, -1)->first;
                if (arr[prevIdx] > arr[idx]) {
                    erroredIdxs.insert(prevIdx);
                } else {
                    erroredIdxs.erase(prevIdx);
                }
                pq.push({arr[idx] + arr[prevIdx], prevIdx});
            }
        }
        return res;
    }
};