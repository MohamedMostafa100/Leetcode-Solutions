class FoodRatings {
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i < foods.size(); i++)
        {
            foodMap[foods[i]] = {cuisines[i], ratings[i]};
            cuisineHighest[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        cuisineHighest[foodMap[food].first].erase({-foodMap[food].second, food});
        cuisineHighest[foodMap[food].first].insert({-newRating, food});
        foodMap[food].second = newRating;
    }
    
    string highestRated(string cuisine) {
        return (*cuisineHighest[cuisine].begin()).second;
    }
private:
    unordered_map<string, pair<string, int>> foodMap;
    unordered_map<string, set<pair<int, string>>> cuisineHighest;
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */