class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        visited = [False for _ in range(len(arr))]
        def dfs(start: int) -> bool:
            if start < 0 or start >= len(arr) or visited[start]:
                return False
            visited[start] = True
            if arr[start] == 0:
                return True
            return dfs(start + arr[start]) or dfs(start - arr[start])    
        return dfs(start)