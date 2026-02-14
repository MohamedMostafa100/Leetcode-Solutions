class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        excess = [[0 for _ in range(i + 1)] for i in range(101)]
        excess[0][0] = poured
        for i in range(100):
            for j in range(i + 1):
                if i == query_row and j == query_glass:
                    return min(excess[i][j], 1.0)
                excess[i + 1][j] += (0.5 * max(excess[i][j] - 1, 0.0)) 
                excess[i + 1][j + 1] += (0.5 * max(excess[i][j] - 1, 0.0))
        return 0.0