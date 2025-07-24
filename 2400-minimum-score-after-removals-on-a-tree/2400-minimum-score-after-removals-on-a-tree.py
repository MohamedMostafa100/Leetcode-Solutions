class Solution:
    def minimumScore(self, nums: List[int], edges: List[List[int]]) -> int:
        res = float('inf')
        sum = 0
        graph = [[] for num in nums]
        xors = [0 for num in nums]
        descendants = [set() for num in nums]
        for edge in edges:
            graph[edge[0]].append(edge[1])
            graph[edge[1]].append(edge[0])
        def dfs(node: int, parent: int):
            xors[node] = nums[node]
            descendants[node].add(node)
            for child in graph[node]:
                if child != parent:
                    dfs(child, node)
                    xors[node] ^= xors[child]
                    descendants[node].update(descendants[child])
        dfs(0, -1)
        sum = xors[0]
        for i in range(1, len(nums)):
            for j in range(i + 1, len(nums)):
                if j in descendants[i]:
                    part1 = xors[i] ^ xors[j]
                    part2 = xors[j]
                    part3 = sum ^ xors[i]
                elif i in descendants[j]:
                    part1 = xors[j] ^ xors[i]
                    part2 = xors[i]
                    part3 = sum ^ xors[j]
                else:
                    part1 = xors[i]
                    part2 = xors[j]
                    part3 = sum ^ xors[i] ^ xors[j]
                score = max(part1, part2, part3) - min(part1, part2, part3)
                res = min(res, score)
        return res

        