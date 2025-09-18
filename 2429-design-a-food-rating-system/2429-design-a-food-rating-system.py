class FoodRatings:

    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        self.foodMap = {}
        self.cuisineHighest = {}
        for i in range(len(foods)):
            self.foodMap[foods[i]] = (cuisines[i], ratings[i])
            if cuisines[i] not in self.cuisineHighest:
                self.cuisineHighest[cuisines[i]] = SortedSet()
            self.cuisineHighest[cuisines[i]].add((-ratings[i], foods[i]))

    def changeRating(self, food: str, newRating: int) -> None:
        self.cuisineHighest[self.foodMap[food][0]].remove((-self.foodMap[food][1], food))
        self.cuisineHighest[self.foodMap[food][0]].add((-newRating, food))
        self.foodMap[food] = (self.foodMap[food][0], newRating)


    def highestRated(self, cuisine: str) -> str:
        return self.cuisineHighest[cuisine][0][1]


# Your FoodRatings object will be instantiated and called as such:
# obj = FoodRatings(foods, cuisines, ratings)
# obj.changeRating(food,newRating)
# param_2 = obj.highestRated(cuisine)