class MovieRentingSystem:

    def __init__(self, n: int, entries: List[List[int]]):
        self.prices = {}
        self.movies = {}
        self.rented = SortedSet()
        for s, m, p in entries:
            if m not in self.movies:
                self.movies[m] = SortedSet()
                self.prices[m] = {}
            self.movies[m].add((p, s))
            self.prices[m][s] = p

    def search(self, movie: int) -> List[int]:
        if movie not in self.movies:
            return []
        res = [self.movies[movie][i][1] for i in range(min(5, len(self.movies[movie])))]
        return res
        
    def rent(self, shop: int, movie: int) -> None:
        self.movies[movie].remove((self.prices[movie][shop], shop))
        self.rented.add((self.prices[movie][shop], shop, movie))

    def drop(self, shop: int, movie: int) -> None:
        self.movies[movie].add((self.prices[movie][shop], shop))
        self.rented.remove((self.prices[movie][shop], shop, movie))

    def report(self) -> List[List[int]]:
        res = [[self.rented[i][1], self.rented[i][2]] for i in range(min(5, len(self.rented)))]
        return res


# Your MovieRentingSystem object will be instantiated and called as such:
# obj = MovieRentingSystem(n, entries)
# param_1 = obj.search(movie)
# obj.rent(shop,movie)
# obj.drop(shop,movie)
# param_4 = obj.report()