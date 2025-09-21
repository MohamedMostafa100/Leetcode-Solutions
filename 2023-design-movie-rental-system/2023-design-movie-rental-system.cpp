class MovieRentingSystem {
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(int i = 0; i < entries.size(); i++)
        {
            movies[entries[i][1]].insert({entries[i][2], entries[i][0]});
            prices[entries[i][1]][entries[i][0]] = entries[i][2];
        }
    }
    
    vector<int> search(int movie) {
        vector<int> res;
        for(auto it : movies[movie])
        {
            res.push_back(it.second);
            if(res.size() == 5)
            {
                break;
            }
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        movies[movie].erase({prices[movie][shop], shop});
        rented.insert({prices[movie][shop], shop, movie});
    }
    
    void drop(int shop, int movie) {
        movies[movie].insert({prices[movie][shop], shop});
        rented.erase({prices[movie][shop], shop, movie});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        for(auto it : rented)
        {
            vector<int> entry;
            entry.push_back(it[1]);
            entry.push_back(it[2]);
            res.push_back(entry);
            if(res.size() == 5)
            {
                break;
            }
        }
        return res;
    }
private:
    unordered_map<int, unordered_map<int, int>> prices;
    unordered_map<int, set<pair<int, int>>> movies;
    set<vector<int>> rented;
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */