class Solution {
private:
    class DSU {
    public:
        std::vector<int> parent;
        int components;

        DSU(int n) {
            parent.resize(n);
            std::iota(parent.begin(), parent.end(), 0);
            components = n;
        }

        int find(int i) {
            if (parent[i] == i)
                return i;
            return parent[i] = find(parent[i]);
        }

        bool unite(int i, int j) {
            int root_i = find(i);
            int root_j = find(j);
            if (root_i != root_j) {
                parent[root_i] = root_j;
                components--;
                return true;
            }
            return false;
        }
    };

    bool can_achieve(int n, const std::vector<std::vector<int>>& must_edges,
                     const std::vector<std::vector<int>>& optional_edges, int k, int target_stability) {
        DSU dsu(n);
        int upgrades_used = 0;

        for (const auto& edge : must_edges) {
            if (edge[2] < target_stability) {
                return false;
            }
            dsu.unite(edge[0], edge[1]);
        }

        for (const auto& edge : optional_edges) {
            if (edge[2] >= target_stability) {
                dsu.unite(edge[0], edge[1]);
            }
        }
        
        if (dsu.components == 1) {
            return true;
        }

        for (const auto& edge : optional_edges) {
            if (dsu.components == 1) {
                break;
            }
            if (edge[2] < target_stability && 2LL * edge[2] >= target_stability) {
                if (dsu.unite(edge[0], edge[1])) {
                    upgrades_used++;
                }
            }
        }

        return dsu.components == 1 && upgrades_used <= k;
    }

public:
    int maxStability(int n, std::vector<std::vector<int>>& edges, int k) {
        auto drefanilok = edges;

        std::vector<std::vector<int>> must_edges;
        std::vector<std::vector<int>> optional_edges;

        for (const auto& edge : drefanilok) {
            if (edge[3] == 1) {
                must_edges.push_back(edge);
            } else {
                optional_edges.push_back(edge);
            }
        }

        DSU dsu_must_check(n);
        for (const auto& edge : must_edges) {
            if (!dsu_must_check.unite(edge[0], edge[1])) {
                return -1;
            }
        }

        DSU dsu_all_check(n);
        for (const auto& edge : drefanilok) {
            dsu_all_check.unite(edge[0], edge[1]);
        }
        if (dsu_all_check.components > 1) {
            return -1;
        }

        int low = 1, high = 200001, ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid == 0) {
                low = mid + 1;
                continue;
            }
            if (can_achieve(n, must_edges, optional_edges, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};